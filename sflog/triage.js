const DIAGNOSTICS = [
  {
    code: "assertion_failure",
    summary: "Assertion failure",
    severity: "error",
    priority: 0,
    test(line, eventType) {
      if (eventType === "VARIABLE_ASSIGNMENT") {
        const candidate = extractVariableAssignmentValue(line);
        return (
          (looksLikeExceptionPayload(candidate) ||
            looksLikePlainAssertionMessage(candidate)) &&
          /AssertException|Assertion Failed/i.test(candidate)
        );
      }

      return (
        (eventType === "FATAL_ERROR" || eventType === "EXCEPTION_THROWN") &&
        /AssertException|Assertion Failed/i.test(line)
      );
    },
  },
  {
    code: "validation_failure",
    summary: "Validation failure",
    severity: "error",
    priority: 1,
    test(line, eventType) {
      if (
        eventType !== "VARIABLE_ASSIGNMENT" &&
        eventType !== "EXCEPTION_THROWN" &&
        eventType !== "FATAL_ERROR"
      ) {
        return false;
      }

      const candidate =
        eventType === "VARIABLE_ASSIGNMENT"
          ? extractVariableAssignmentValue(line)
          : line;

      if (
        eventType === "VARIABLE_ASSIGNMENT" &&
        !looksLikeErrorBearingVariableValue(candidate) &&
        !looksLikePlainValidationMessage(candidate)
      ) {
        return false;
      }

      return /FIELD_CUSTOM_VALIDATION_EXCEPTION|VALIDATION_EXCEPTION/i.test(
        candidate
      );
    },
  },
  {
    code: "dml_failure",
    summary: "DML failure",
    severity: "error",
    priority: 2,
    test(line, eventType) {
      if (
        eventType !== "VARIABLE_ASSIGNMENT" &&
        eventType !== "EXCEPTION_THROWN" &&
        eventType !== "FATAL_ERROR"
      ) {
        return false;
      }

      const candidate =
        eventType === "VARIABLE_ASSIGNMENT"
          ? extractVariableAssignmentValue(line)
          : line;

      if (
        eventType === "VARIABLE_ASSIGNMENT" &&
        !looksLikeErrorBearingVariableValue(candidate) &&
        !looksLikePlainDmlMessage(candidate)
      ) {
        return false;
      }

      return /DmlException|Insert failed|Update failed|Upsert failed|Delete failed|Merge failed|REQUIRED_FIELD_MISSING/i.test(
        candidate
      );
    },
  },
  {
    code: "fatal_exception",
    summary: "Fatal exception",
    severity: "error",
    priority: 3,
    test(line, eventType) {
      if (eventType === "FATAL_ERROR") {
        return true;
      }

      if (eventType === "VARIABLE_ASSIGNMENT") {
        return looksLikeExceptionPayload(extractVariableAssignmentValue(line));
      }

      return eventType === "EXCEPTION_THROWN";
    },
  },
  {
    code: "suspicious_error_payload",
    summary: "Suspicious error payload",
    severity: "warning",
    priority: 4,
    test(line, eventType) {
      return (
        eventType === "VARIABLE_ASSIGNMENT" &&
        looksLikeSerializedErrorPayload(extractVariableAssignmentValue(line))
      );
    },
  },
  {
    code: "rollback_detected",
    summary: "Rollback detected",
    severity: "warning",
    priority: 5,
    test(_line, eventType) {
      return eventType === "ROLLBACK";
    },
  },
];

function extractVariableAssignmentValue(line) {
  const match = line.match(
    /^[^|]*\|VARIABLE_ASSIGNMENT\|[^|]*\|[^|]*\|([\s\S]*?)(?:\|0x[0-9a-fA-F]+)?$/
  );

  return match ? match[1] : line;
}

function looksLikeSerializedErrorPayload(text) {
  return (
    /"Error\s*\[/i.test(text) ||
    /\bstatusCode=(?:[A-Z][A-Z0-9_]+)\b/.test(text) ||
    /\bmessage=[^|"]*(?:exception|failed|error)\b/i.test(text)
  );
}

function looksLikeExceptionPayload(text) {
  return /(?:^|["\s])(?:[A-Za-z0-9_$.]+Exception):\s+\S/.test(text);
}

function looksLikeErrorBearingVariableValue(text) {
  return looksLikeSerializedErrorPayload(text) || looksLikeExceptionPayload(text);
}

function looksLikePlainValidationMessage(text) {
  return /\b(?:FIELD_CUSTOM_VALIDATION_EXCEPTION|VALIDATION_EXCEPTION)\b(?=[,:])/.test(
    text
  );
}

function looksLikePlainDmlMessage(text) {
  return /\b(?:Insert|Update|Upsert|Delete|Merge) failed\. First exception on row\b/i.test(
    text
  );
}

function looksLikePlainAssertionMessage(text) {
  return /\bAssertion Failed\b(?=[:.])/i.test(text);
}

function extractEventType(line) {
  const match = line.match(/^[^|]*\|([^|]+)(?:\||$)/);
  return match ? match[1] : undefined;
}

function isLogEntryStart(line) {
  return /^\d{2}:\d{2}:\d{2}\.\d+(?:\s+\([^)]+\))?\|[^|]+(?:\||$)/.test(line);
}

function splitLogEntries(logText) {
  const entries = [];
  let currentEntry;

  for (const rawLine of String(logText ?? "").split(/\r?\n/)) {
    const line = rawLine.trim();
    if (!line) {
      continue;
    }

    if (isLogEntryStart(line)) {
      if (currentEntry) {
        entries.push(currentEntry);
      }
      currentEntry = line;
      continue;
    }

    if (currentEntry) {
      currentEntry += `\n${line}`;
    }
  }

  if (currentEntry) {
    entries.push(currentEntry);
  }

  return entries;
}

function extractSourceLine(line) {
  const match = line.match(/\|(\[(\d+)\]|\[[A-Z_]+\])\|/);
  return match && match[2] ? Number(match[2]) : undefined;
}

function buildReason(diagnostic, rawLine, eventType) {
  return {
    code: diagnostic.code,
    severity: diagnostic.severity,
    summary: diagnostic.summary,
    line: extractSourceLine(rawLine),
    eventType,
  };
}

function collectLineDiagnostics(line, eventType) {
  const matches = DIAGNOSTICS.filter((diagnostic) =>
    diagnostic.test(line, eventType)
  );
  const matchedCodes = new Set(matches.map((diagnostic) => diagnostic.code));
  const hasSpecificError =
    matchedCodes.has("assertion_failure") ||
    matchedCodes.has("validation_failure") ||
    matchedCodes.has("dml_failure");

  return matches.filter((diagnostic) => {
    if (diagnostic.code === "fatal_exception" && hasSpecificError) {
      return false;
    }

    if (
      diagnostic.code === "suspicious_error_payload" &&
      matches.some((candidate) => candidate.severity === "error")
    ) {
      return false;
    }

    return true;
  });
}

function summarizeLog(logText) {
  const reasonsByCode = new Map();

  for (const line of splitLogEntries(logText)) {
    const eventType = extractEventType(line);

    for (const diagnostic of collectLineDiagnostics(line, eventType)) {
      if (reasonsByCode.has(diagnostic.code)) {
        continue;
      }

      reasonsByCode.set(
        diagnostic.code,
        buildReason(diagnostic, line, eventType)
      );
    }
  }

  const reasons = [...reasonsByCode.values()].sort((left, right) => {
    const leftPriority = DIAGNOSTICS.find(
      (diagnostic) => diagnostic.code === left.code
    ).priority;
    const rightPriority = DIAGNOSTICS.find(
      (diagnostic) => diagnostic.code === right.code
    ).priority;

    return leftPriority - rightPriority;
  });

  return {
    hasErrors: reasons.length > 0,
    primaryReason: reasons[0] ? reasons[0].summary : undefined,
    reasons,
  };
}

module.exports = {
  summarizeLog,
};
