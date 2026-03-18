const DML_STATUS_CODE_PATTERN =
  /REQUIRED_FIELD_MISSING|FIELD_INTEGRITY_EXCEPTION|DUPLICATE_VALUE|INVALID_FIELD_FOR_INSERT_UPDATE|STRING_TOO_LONG|INVALID_OR_NULL_FOR_RESTRICTED_PICKLIST|INVALID_CROSS_REFERENCE_KEY|CANNOT_INSERT_UPDATE_ACTIVATE_ENTITY|DELETE_FAILED|ENTITY_IS_DELETED/;
const VALIDATION_STATUS_CODE_PATTERN =
  /FIELD_CUSTOM_VALIDATION_EXCEPTION|VALIDATION_EXCEPTION/;

const DIAGNOSTICS = [
  {
    code: "assertion_failure",
    summary: "Assertion failure",
    severity: "error",
    priority: 0,
    test(line, eventType) {
      if (
        eventType !== "VARIABLE_ASSIGNMENT" &&
        eventType !== "FATAL_ERROR" &&
        eventType !== "EXCEPTION_THROWN"
      ) {
        return false;
      }

      const candidate =
        eventType === "VARIABLE_ASSIGNMENT"
          ? extractVariableAssignmentValue(line)
          : extractEventDetailValue(line, eventType);

      return looksLikeStructuredAssertionFailure(candidate);
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

      if (
        (eventType === "EXCEPTION_THROWN" || eventType === "FATAL_ERROR") &&
        !looksLikeStructuredThrownValidationFailure(candidate)
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
        !looksLikePlainDmlMessage(candidate) &&
        !looksLikePlainDmlStatusMessage(candidate)
      ) {
        return false;
      }

      if (
        (eventType === "EXCEPTION_THROWN" || eventType === "FATAL_ERROR") &&
        !looksLikeStructuredThrownDmlFailure(candidate)
      ) {
        return false;
      }

      return (
        /DmlException|Insert failed|Update failed|Upsert failed|Delete failed|Merge failed/i.test(
          candidate
        ) || DML_STATUS_CODE_PATTERN.test(candidate)
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
    /^[^|]*\|VARIABLE_ASSIGNMENT\|(?:\[[^\]]+\]\|)?[^|]*\|([\s\S]*?)(?:\|0x[0-9a-fA-F]+)?$/
  );

  return match ? match[1] : line;
}

function looksLikeSerializedErrorPayload(text) {
  const normalized = normalizeVariableValue(text);
  const serializedStatusCode = extractSerializedStatusCode(normalized);

  return (
    /^Error\s*\[/i.test(normalized) ||
    looksLikeSerializedErrorStatusCode(serializedStatusCode) ||
    /\bmessage=[^|"]*(?:exception|failed|error)\b/i.test(normalized)
  );
}

function looksLikeExceptionPayload(text) {
  const normalized = normalizeVariableValue(text);

  return (
    /^[A-Za-z0-9_$.]+Exception:\s+\S/.test(normalized) ||
    /^[A-Za-z0-9_$.]+Exception$/.test(normalized)
  );
}

function looksLikeErrorBearingVariableValue(text) {
  return looksLikeSerializedErrorPayload(text) || looksLikeExceptionPayload(text);
}

function looksLikePlainValidationMessage(text) {
  const normalized = normalizeVariableValue(text);

  return (
    /^(?:FIELD_CUSTOM_VALIDATION_EXCEPTION|VALIDATION_EXCEPTION)$/.test(
      normalized
    ) ||
    /\b(?:FIELD_CUSTOM_VALIDATION_EXCEPTION|VALIDATION_EXCEPTION)\b(?=[,:])/.test(
      normalized
    )
  );
}

function looksLikePlainDmlMessage(text) {
  return /\b(?:Insert|Update|Upsert|Delete|Merge) failed\. First exception on row\b/i.test(
    normalizeVariableValue(text)
  );
}

function looksLikePlainAssertionMessage(text) {
  return /\bAssertion Failed\b(?=[:.]|$)/i.test(normalizeVariableValue(text));
}

function looksLikeStructuredAssertionFailure(text) {
  const normalized = normalizeVariableValue(text);

  return (
    /^(?:[A-Za-z0-9_$.]+\.)?AssertException(?::|\b)/.test(normalized) ||
    looksLikePlainAssertionMessage(normalized)
  );
}

function looksLikePlainDmlStatusMessage(text) {
  return new RegExp(`^(?:${DML_STATUS_CODE_PATTERN.source})(?=[,:]|$)`).test(
    normalizeVariableValue(text)
  );
}

function extractSerializedStatusCode(text) {
  const match = String(text ?? "").match(/\bstatusCode=([A-Z][A-Z0-9_]+)\b/);
  return match ? match[1] : undefined;
}

function looksLikeSerializedErrorStatusCode(statusCode) {
  return Boolean(statusCode) &&
    (DML_STATUS_CODE_PATTERN.test(statusCode) ||
      VALIDATION_STATUS_CODE_PATTERN.test(statusCode) ||
      /(EXCEPTION|ERROR|FAILED|INVALID|REQUIRED|DUPLICATE|DELETE|CANNOT|ENTITY_IS_DELETED|STRING_TOO_LONG)/.test(
        statusCode
      ));
}

function looksLikeStructuredThrownValidationFailure(text) {
  return (
    (/DmlException/.test(text) && VALIDATION_STATUS_CODE_PATTERN.test(text)) ||
    new RegExp(
      `(?:statusCode=|first error:\\s*)(?:${VALIDATION_STATUS_CODE_PATTERN.source})`
    ).test(text)
  );
}

function looksLikeStructuredThrownDmlFailure(text) {
  return (
    /DmlException/.test(text) ||
    new RegExp(
      `(?:statusCode=|first error:\\s*)(?:${DML_STATUS_CODE_PATTERN.source})`
    ).test(text)
  );
}

function normalizeVariableValue(text) {
  const normalized = String(text ?? "").trim();
  if (normalized.startsWith('"') && normalized.endsWith('"')) {
    return normalized.slice(1, -1).trim();
  }
  return normalized;
}

function extractEventDetailValue(line, eventType) {
  const eventPattern = eventType ? escapeRegExp(eventType) : "[^|]+";
  const match = String(line ?? "").match(
    new RegExp(`^[^|]*\\|${eventPattern}\\|(?:\\[[^\\]]+\\]\\|)?([\\s\\S]*)$`)
  );

  return match ? match[1] : "";
}

function extractEventType(line) {
  const match = line.match(/^[^|]*\|([^|]+)(?:\||$)/);
  return match ? match[1] : undefined;
}

function escapeRegExp(text) {
  return String(text ?? "").replace(/[.*+?^${}()|[\]\\]/g, "\\$&");
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
