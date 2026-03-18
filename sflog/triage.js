const DIAGNOSTICS = [
  {
    code: "assertion_failure",
    summary: "Assertion failure",
    severity: "error",
    priority: 0,
    test(line, eventType) {
      return (
        eventType === "FATAL_ERROR" &&
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
      return (
        eventType === "VARIABLE_ASSIGNMENT" &&
        /"Error\s*\[|\bstatusCode=|\bmessage=/i.test(line)
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

function summarizeLog(logText) {
  const reasonsByCode = new Map();

  for (const rawLine of String(logText ?? "").split(/\r?\n/)) {
    const line = rawLine.trim();
    if (!line) {
      continue;
    }

    const eventType = extractEventType(line);

    for (const diagnostic of DIAGNOSTICS) {
      if (!diagnostic.test(line, eventType) || reasonsByCode.has(diagnostic.code)) {
        continue;
      }

      reasonsByCode.set(
        diagnostic.code,
        buildReason(diagnostic, line, eventType)
      );
      break;
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
