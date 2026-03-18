# Sflog Triage Design

Date: 2026-03-17
Repo: `C:\Users\k2\git\tree-sitter-sfapex`
Related consumer: `C:\Users\k2\git\Apex-Log-Viewer`

## Summary

This design upgrades `sflog` from a line-oriented parser into a triage-oriented parser for Salesforce Apex logs. The immediate goal is to help `Apex-Log-Viewer` identify which saved logs are worth opening when a developer is debugging failures.

Version 1 prioritizes triage in the log list, not richer in-log visualization. The parser must first accept real NebulaLogger logs without parse failures, then surface a small set of reliable diagnostics per file so the extension can power `Errors only` and show short, trustworthy reasons such as `Validation failure, rollback`.

## Problem

The current `sflog` grammar is too shallow for modern Salesforce logs and does not fully reflect the formats seen in real NebulaLogger output. It breaks on newer headers such as `64.0` and `66.0` with `DATA_ACCESS`, and it treats most event payloads as undifferentiated detail strings.

`Apex-Log-Viewer` currently classifies logs for the `Errors only` filter by scanning each file for coarse error tokens. That is fast, but it is not reliable enough for nuanced debugging cases such as:

- handled exceptions that are stored in variables instead of surfacing as `FATAL_ERROR`
- validation or DML failures represented inside payload strings
- rollbacks that explain why work disappeared
- assertion failures
- query failures or clearly anomalous SOQL traces

The result is a gap between the developer question, "Which log should I open first?", and the signals the tooling can currently extract.

## Goals

- Parse real NebulaLogger Apex logs without syntax failures for the formats observed in `C:\Users\k2\git\NebulaLogger\apexlogs`.
- Recognize a focused set of triage-relevant event shapes instead of treating all payloads as opaque strings.
- Produce a deterministic file-level triage summary that `Apex-Log-Viewer` can consume for list filtering and short reason labels.
- Keep the first release narrow enough to support a single implementation plan and low-regression rollout.

## Non-Goals

- Rebuild the full `Apex-Log-Viewer` log detail experience around tree-sitter in v1.
- Model every Salesforce log event type.
- Infer performance problems from weak heuristics that would create noisy false positives.
- Add speculative diagnostics that do not have support in the real NebulaLogger fixtures.

## Primary User Outcome

Given a workspace full of saved Apex logs, a Salesforce developer should be able to turn on `Errors only` and quickly see the files most likely to explain a failure, with a short summary of why each file was marked.

## Design Direction

The chosen direction is a triage-oriented parser, not just a more permissive grammar.

`sflog` will do three things:

1. Parse real logs without error.
2. Structure key event payloads needed for debugging triage.
3. Derive file-level diagnostics from those events.

`Apex-Log-Viewer` will do four things:

1. Request or consume the file-level triage summary for a saved log.
2. Use `hasErrors` to drive the existing list filter and badge behavior.
3. Show a short primary reason in the list row when available.
4. Preserve the option to reuse the same diagnostics later in the full log viewer.

## Diagnostic Model

Version 1 uses a small, explicit set of diagnostic codes.

### Hard Errors

- `fatal_exception`
  - Triggered by events such as `EXCEPTION_THROWN` or `FATAL_ERROR`, or by payloads that clearly contain exceptions like `NullPointerException`, `IllegalArgumentException`, `DmlException`, `TypeException`, or similar.
- `assertion_failure`
  - Triggered by `AssertException`, assertion-failed messages, or equivalent explicit assertion failures.
- `validation_failure`
  - Triggered by validation exceptions or payloads such as `FIELD_CUSTOM_VALIDATION_EXCEPTION`.
- `dml_failure`
  - Triggered by explicit DML exceptions or payloads indicating failed `insert`, `update`, `upsert`, `delete`, or `merge`.

### Debug Blockers

- `rollback_detected`
  - Triggered by rollback events or lines that clearly indicate the transaction was rolled back.
- `suspicious_error_payload`
  - Triggered when no top-level fatal event exists, but a payload clearly contains an error object or failure descriptor that a developer would care about immediately.
- `limit_risk`
  - Included in v1 only when the underlying log evidence shows a concrete failing or near-failing limit condition rather than ordinary limit reporting.
- `soql_anomaly`
  - Included in v1 only when real fixtures provide strong, low-noise signals such as malformed query exceptions or query error payloads.

The preferred v1 minimum set is:

- `fatal_exception`
- `assertion_failure`
- `validation_failure`
- `dml_failure`
- `rollback_detected`
- `suspicious_error_payload`

`limit_risk` and `soql_anomaly` are part of the design, but they should ship in the first implementation only if the sanitized fixture set demonstrates reliable signals.

## File-Level Contract

The parser layer should expose a compact file-level summary that is stable enough for reuse outside the extension.

Conceptual shape:

```ts
type LogDiagnosticCode =
  | 'fatal_exception'
  | 'assertion_failure'
  | 'validation_failure'
  | 'dml_failure'
  | 'rollback_detected'
  | 'limit_risk'
  | 'soql_anomaly'
  | 'suspicious_error_payload';

type LogDiagnostic = {
  code: LogDiagnosticCode;
  severity: 'error' | 'warning';
  line?: number;
  eventType?: string;
  summary: string;
};

type LogTriageSummary = {
  hasErrors: boolean;
  primaryReason?: string;
  reasons: LogDiagnostic[];
};
```

Rules for v1:

- `hasErrors` is true when at least one triage-relevant diagnostic is present.
- `primaryReason` is a short, human-readable summary intended for the list view.
- `reasons` is ordered by severity and usefulness.
- The UI should display at most two reason summaries for a file in the list context.

Examples:

- `NullPointerException, rollback`
- `Validation failure, DML failure`
- `Assertion failure`
- `Validation failure, suspicious error payload`

## Parser Scope

The grammar must support the real header and event formats observed in the NebulaLogger corpus, including:

- modern header versions such as `64.0` and `66.0`
- components including `DATA_ACCESS`
- event lines with location segments like `[109]` and `[EXTERNAL]`
- events with multiple payload segments
- multi-line limit blocks
- payload-heavy lines such as `VARIABLE_ASSIGNMENT` with serialized error objects

The event structures that matter most for v1 triage are:

- `EXCEPTION_THROWN`
- `FATAL_ERROR`
- `VARIABLE_ASSIGNMENT`
- DML-related events and error payloads
- validation-related events and payloads
- rollback-related events
- `SOQL_EXECUTE_*` when the payload indicates a genuine anomaly
- limit-related events when the payload indicates a real failure or imminent failure

Events such as `METHOD_ENTRY`, `METHOD_EXIT`, `SYSTEM_METHOD_ENTRY`, and `SYSTEM_METHOD_EXIT` remain useful for future analysis, but they are not central to the first triage slice.

## Responsibility Split

### tree-sitter-sfapex

Responsible for:

- accepting real logs without parse failures
- structuring the payloads that matter to triage
- deriving deterministic diagnostics from parsed events

Not responsible for:

- extension-specific rendering decisions
- row-level UX behavior in the VS Code list
- inventing new error semantics that are not grounded in the parsed log evidence

### Apex-Log-Viewer

Responsible for:

- consuming `LogTriageSummary`
- storing `hasErrors`, `primaryReason`, and `reasons` for each saved log
- driving the `Errors only` filter and row badges
- deciding how much of the summary to expose in list rows, badges, or later details

Not responsible for:

- duplicating the parser semantics with separate regex heuristics once the structured summary is available

## Implementation Strategy

The work should be implemented in four steps.

### Step 1: Real-log parser coverage

Add failing corpus tests in `tree-sitter-sfapex` using sanitized excerpts from real NebulaLogger logs that represent:

- new header formats and components
- fatal exceptions
- validation and DML failures
- rollback
- suspicious error payloads in `VARIABLE_ASSIGNMENT`
- candidate limit and SOQL anomalies if strong fixtures exist

Then update the grammar until those fixtures parse without error.

### Step 2: Structured triage events

Introduce enough semantic structure to identify the event kind, source line, and primary payload values needed for diagnostics. This should remain minimal and focused on triage rather than full semantic modeling of every event family.

### Step 3: File-level diagnostics

Add the analyzer that converts parsed events into `LogTriageSummary`. Keep the result small, deterministic, and conservative. False positives are worse than leaving a non-fatal warning for a later iteration.

### Step 4: Extension integration

Update `Apex-Log-Viewer` so its progressive file scan uses structured triage results rather than a boolean token match. Preserve the existing scan cadence and low concurrency so the filter remains responsive.

## Testing Strategy

### tree-sitter-sfapex

- Add corpus tests for every supported v1 diagnostic trigger.
- Include at least one sanitized real-log excerpt for each accepted header version currently observed.
- Verify that suspicious payloads such as validation exceptions inside `VARIABLE_ASSIGNMENT` are covered explicitly.

### Apex-Log-Viewer

- Add unit tests for mapping `LogTriageSummary` into list-row state.
- Verify that logs with fatal exceptions, assertions, validation failures, DML failures, and rollbacks appear in `Errors only`.
- Verify that ordinary logs do not become false positives.
- Verify that the row summary stays short and stable.

## Error Handling and Safety

- If a log cannot be classified because it is unreadable or unavailable, the extension may continue using its conservative fallback behavior for that file.
- The triage summary should only elevate `limit_risk` or `soql_anomaly` when the evidence is explicit enough to avoid noisy list rows.
- Payload parsing should prefer robustness over overfitting. If a payload cannot be safely decomposed, keep the raw summary string instead of guessing extra fields.

## Risks

- Overfitting the first diagnostic pass to NebulaLogger-specific message phrasing.
- Producing too many reasons per file, which would reduce the usefulness of the list view.
- Letting the extension and parser drift into duplicate semantics again.

## Mitigations

- Base each diagnostic on sanitized real fixtures, not hypothetical patterns.
- Keep v1 to a short diagnostic list with severity ordering and a two-reason display cap.
- Define the parser-owned `LogTriageSummary` contract once and have the extension consume it directly.

## Ready-for-Planning Scope

This spec is intentionally scoped to one implementation plan:

- improve `sflog` parse coverage for real logs
- add triage-oriented semantics
- produce file-level diagnostics
- wire those diagnostics into `Apex-Log-Viewer` list triage

It does not include a redesign of the full log viewer, a broader performance analysis feature set, or a complete Salesforce event taxonomy.
