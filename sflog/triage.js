const DIAGNOSTICS = [
  {
    code: "assertion_failure",
    summary: "Assertion failure",
    severity: "error",
    priority: 0,
    test(line, eventType) {
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
    test(line) {
      return /FIELD_CUSTOM_VALIDATION_EXCEPTION|VALIDATION_EXCEPTION/i.test(
        line
      );
    },
  },
  {
    code: "dml_failure",
    summary: "DML failure",
    severity: "error",
    priority: 2,
    test(line) {
      return /DmlException|Insert failed|Update failed|Upsert failed|Delete failed|Merge failed|REQUIRED_FIELD_MISSING/i.test(
        line
      );
    },
  },
  {
    code: "fatal_exception",
    summary: "Fatal exception",
    severity: "error",
    priority: 3,
    test(line, eventType) {
      return (
        (eventType === "EXCEPTION_THROWN" || eventType === "FATAL_ERROR") &&
        /[A-Za-z0-9_.]+Exception\b|Assertion Failed/i.test(line)
      );
    },
  },
  {
    code: "suspicious_error_payload",
    summary: "Suspicious error payload",
    severity: "warning",
    priority: 4,
    test(line, eventType) {
      const hasExplicitErrorWrapper = /"Error\s*\[/i.test(line);
      const hasErrorStatusCode = /\bstatusCode=(?:[A-Z][A-Z0-9_]+)\b/.test(line);
      const hasErrorMessage = /\bmessage=[^|"]*(?:exception|failed|error)\b/i.test(
        line
      );

      return (
        eventType === "VARIABLE_ASSIGNMENT" &&
        (hasExplicitErrorWrapper || hasErrorStatusCode || hasErrorMessage)
      );
    },
  },
  {
    code: "rollback_detected",
    summary: "Rollback detected",
    severity: "warning",
    priority: 5,
    test(line, eventType) {
      return (
        eventType === "ROLLBACK" || /Savepoint restored|\bROLLBACK\b/i.test(line)
      );
    },
  },
];

function extractEventType(line) {
  const match = line.match(/^[^|]*\|([^|]+)\|/);
  return match ? match[1] : undefined;
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

  for (const rawLine of String(logText ?? "").split(/\r?\n/)) {
    const line = rawLine.trim();
    if (!line) {
      continue;
    }

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
    hasErrors: reasons.some((reason) => reason.severity === "error"),
    primaryReason: reasons[0] ? reasons[0].summary : undefined,
    reasons,
  };
}

module.exports = {
  summarizeLog,
};
