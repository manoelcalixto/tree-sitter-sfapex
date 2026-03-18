export type LogDiagnosticCode =
  | "fatal_exception"
  | "assertion_failure"
  | "validation_failure"
  | "dml_failure"
  | "rollback_detected"
  | "suspicious_error_payload";

export type LogDiagnosticSeverity = "error" | "warning";

export interface LogDiagnostic {
  code: LogDiagnosticCode;
  severity: LogDiagnosticSeverity;
  summary: string;
  line?: number;
  eventType?: string;
}

export interface LogTriageSummary {
  hasErrors: boolean;
  primaryReason?: string;
  reasons: LogDiagnostic[];
}

export function summarizeLog(logText: string): LogTriageSummary;
