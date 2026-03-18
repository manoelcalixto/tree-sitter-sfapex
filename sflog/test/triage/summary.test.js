const test = require("node:test");
const assert = require("node:assert/strict");

const { summarizeLog } = require("../../../bindings/node/sflog-triage");

test("reports validation failure and rollback in priority order", () => {
  const summary = summarizeLog(`
17:11:52.319 (372616766)|VARIABLE_ASSIGNMENT|[131]|error|"Error [statusCode=FIELD_CUSTOM_VALIDATION_EXCEPTION, code=null, message=Could not save..., fields=[Name]]"|0x3722c840
17:11:52.525 (530873859)|ROLLBACK|[111]|Savepoint restored
`);

  assert.equal(summary.hasErrors, true);
  assert.equal(summary.primaryReason, "Validation failure");
  assert.deepEqual(summary.reasons.map((reason) => reason.code), [
    "validation_failure",
    "rollback_detected",
  ]);
});

test("reports a fatal exception for uncategorized fatal errors", () => {
  const summary = summarizeLog(`
17:11:53.0 (1600140461)|EXCEPTION_THROWN|[834]|System.IllegalArgumentException: DeveloperName is required
`);

  assert.equal(summary.hasErrors, true);
  assert.equal(summary.primaryReason, "Fatal exception");
  assert.deepEqual(summary.reasons.map((reason) => reason.code), [
    "fatal_exception",
  ]);
});

test("prefers assertion failures over a generic fatal exception", () => {
  const summary = summarizeLog(`
17:11:53.0 (1600140462)|FATAL_ERROR|System.AssertException: Assertion Failed
`);

  assert.equal(summary.hasErrors, true);
  assert.equal(summary.primaryReason, "Assertion failure");
  assert.deepEqual(summary.reasons.map((reason) => reason.code), [
    "assertion_failure",
  ]);
});

test("reports dml failures from exception payloads", () => {
  const summary = summarizeLog(`
17:11:52.320 (372616767)|EXCEPTION_THROWN|[131]|System.DmlException: Insert failed. First exception on row 0; first error: REQUIRED_FIELD_MISSING, Required fields are missing: [Name]: [Name]
`);

  assert.equal(summary.hasErrors, true);
  assert.equal(summary.primaryReason, "DML failure");
  assert.deepEqual(summary.reasons.map((reason) => reason.code), [
    "dml_failure",
  ]);
});

test("reports suspicious serialized error payloads", () => {
  const summary = summarizeLog(`
17:11:52.319 (372616766)|VARIABLE_ASSIGNMENT|[131]|error|"Error [statusCode=UNKNOWN_EXCEPTION, code=null, message=Queueable job failed unexpectedly, fields=[]]"|0x3722c840
`);

  assert.equal(summary.hasErrors, true);
  assert.equal(summary.primaryReason, "Suspicious error payload");
  assert.deepEqual(summary.reasons.map((reason) => reason.code), [
    "suspicious_error_payload",
  ]);
});

test("does not classify successful status payloads as errors", () => {
  const summary = summarizeLog(`
17:11:52.319 (372616766)|VARIABLE_ASSIGNMENT|[131]|response|"HttpResponse [statusCode=200, message=OK]"|0x3722c840
`);

  assert.equal(summary.hasErrors, false);
  assert.equal(summary.primaryReason, undefined);
  assert.deepEqual(summary.reasons, []);
});

test("keeps validation and dml reasons when both appear on one line", () => {
  const summary = summarizeLog(`
17:11:52.320 (372616767)|EXCEPTION_THROWN|[131]|System.DmlException: Insert failed. First exception on row 0; first error: FIELD_CUSTOM_VALIDATION_EXCEPTION, Could not save..., fields=[Name]
`);

  assert.equal(summary.hasErrors, true);
  assert.equal(summary.primaryReason, "Validation failure");
  assert.deepEqual(summary.reasons.map((reason) => reason.code), [
    "validation_failure",
    "dml_failure",
  ]);
});

test("classifies AssertException from EXCEPTION_THROWN as assertion failures", () => {
  const summary = summarizeLog(`
17:11:53.0 (1600140462)|EXCEPTION_THROWN|[834]|System.AssertException: Assertion Failed
`);

  assert.equal(summary.hasErrors, true);
  assert.equal(summary.primaryReason, "Assertion failure");
  assert.deepEqual(summary.reasons.map((reason) => reason.code), [
    "assertion_failure",
  ]);
});

test("treats rollback-only logs as triage hits", () => {
  const summary = summarizeLog(`
17:11:52.525 (530873859)|ROLLBACK|[111]|Savepoint restored
`);

  assert.equal(summary.hasErrors, true);
  assert.equal(summary.primaryReason, "Rollback detected");
  assert.deepEqual(summary.reasons.map((reason) => reason.code), [
    "rollback_detected",
  ]);
});

test("ignores execute anonymous source lines outside structured log events", () => {
  const summary = summarizeLog(`
Execute Anonymous:
System.debug('FIELD_CUSTOM_VALIDATION_EXCEPTION');
`);

  assert.equal(summary.hasErrors, false);
  assert.equal(summary.primaryReason, undefined);
  assert.deepEqual(summary.reasons, []);
});

test("preserves event context for multiline variable assignments", () => {
  const summary = summarizeLog(`
17:11:52.319 (372616766)|VARIABLE_ASSIGNMENT|[131]|error|payloadStart
Error [statusCode=UNKNOWN_EXCEPTION, code=null, message=Queueable job failed unexpectedly, fields=[]]
`);

  assert.equal(summary.hasErrors, true);
  assert.equal(summary.primaryReason, "Suspicious error payload");
  assert.deepEqual(summary.reasons.map((reason) => reason.code), [
    "suspicious_error_payload",
  ]);
});

test("returns no reasons for non-error log lines", () => {
  const summary = summarizeLog(`
17:11:52.1 (6438204)|METHOD_ENTRY|[31]||System.OrgLimits.getMap()
17:11:52.1 (96974034)|METHOD_EXIT|[31]||System.OrgLimits.getMap()
`);

  assert.equal(summary.hasErrors, false);
  assert.equal(summary.primaryReason, undefined);
  assert.deepEqual(summary.reasons, []);
});
