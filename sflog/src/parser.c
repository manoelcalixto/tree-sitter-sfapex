#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 53
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 64
#define ALIAS_COUNT 0
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  anon_sym_LF = 1,
  sym_version = 2,
  anon_sym_COMMA = 3,
  anon_sym_SEMI = 4,
  anon_sym_DB = 5,
  anon_sym_WORKFLOW = 6,
  anon_sym_NBA = 7,
  anon_sym_VALIDATION = 8,
  anon_sym_CALLOUT = 9,
  anon_sym_APEX_CODE = 10,
  anon_sym_APEX_PROFILING = 11,
  anon_sym_VISUALFORCE = 12,
  anon_sym_SYSTEM = 13,
  anon_sym_WAVE = 14,
  anon_sym_DATA_ACCESS = 15,
  anon_sym_NONE = 16,
  anon_sym_ERROR = 17,
  anon_sym_WARN = 18,
  anon_sym_INFO = 19,
  anon_sym_DEBUG = 20,
  anon_sym_FINE = 21,
  anon_sym_FINER = 22,
  anon_sym_FINEST = 23,
  anon_sym_ExecuteAnonymous_COLON = 24,
  sym_apex_code = 25,
  anon_sym_PIPE = 26,
  anon_sym_PIPE_LBRACK = 27,
  anon_sym_RBRACK = 28,
  anon_sym_PIPE_LPAREN = 29,
  anon_sym_RPAREN_PIPE = 30,
  anon_sym_EXTERNAL = 31,
  aux_sym_limit_token1 = 32,
  anon_sym_COLON = 33,
  anon_sym_outof = 34,
  sym_event_detail_value = 35,
  sym_time = 36,
  anon_sym_LPAREN = 37,
  anon_sym_RPAREN = 38,
  sym_number = 39,
  sym_identifier = 40,
  sym_source_file = 41,
  sym_log_header = 42,
  sym_log_level_settings = 43,
  sym_log_level_setting = 44,
  sym_component = 45,
  sym_log_level = 46,
  sym_anonymous_block = 47,
  sym__anonymous_label = 48,
  sym_log_entry = 49,
  sym_location = 50,
  sym_namespace = 51,
  sym_limit_usage = 52,
  sym_limit = 53,
  sym_event_details = 54,
  sym_event_detail = 55,
  sym_timestamp = 56,
  sym_duration = 57,
  sym_event_identifier = 58,
  aux_sym_source_file_repeat1 = 59,
  aux_sym_log_level_settings_repeat1 = 60,
  aux_sym_anonymous_block_repeat1 = 61,
  aux_sym_limit_usage_repeat1 = 62,
  aux_sym_event_details_repeat1 = 63,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [sym_version] = "version",
  [anon_sym_COMMA] = ",",
  [anon_sym_SEMI] = ";",
  [anon_sym_DB] = "DB",
  [anon_sym_WORKFLOW] = "WORKFLOW",
  [anon_sym_NBA] = "NBA",
  [anon_sym_VALIDATION] = "VALIDATION",
  [anon_sym_CALLOUT] = "CALLOUT",
  [anon_sym_APEX_CODE] = "APEX_CODE",
  [anon_sym_APEX_PROFILING] = "APEX_PROFILING",
  [anon_sym_VISUALFORCE] = "VISUALFORCE",
  [anon_sym_SYSTEM] = "SYSTEM",
  [anon_sym_WAVE] = "WAVE",
  [anon_sym_DATA_ACCESS] = "DATA_ACCESS",
  [anon_sym_NONE] = "NONE",
  [anon_sym_ERROR] = "ERROR",
  [anon_sym_WARN] = "WARN",
  [anon_sym_INFO] = "INFO",
  [anon_sym_DEBUG] = "DEBUG",
  [anon_sym_FINE] = "FINE",
  [anon_sym_FINER] = "FINER",
  [anon_sym_FINEST] = "FINEST",
  [anon_sym_ExecuteAnonymous_COLON] = "Execute Anonymous:",
  [sym_apex_code] = "apex_code",
  [anon_sym_PIPE] = "|",
  [anon_sym_PIPE_LBRACK] = "|[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_PIPE_LPAREN] = "|(",
  [anon_sym_RPAREN_PIPE] = ")|",
  [anon_sym_EXTERNAL] = "EXTERNAL",
  [aux_sym_limit_token1] = "identifier",
  [anon_sym_COLON] = ":",
  [anon_sym_outof] = "out of",
  [sym_event_detail_value] = "event_detail_value",
  [sym_time] = "time",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_number] = "number",
  [sym_identifier] = "identifier",
  [sym_source_file] = "source_file",
  [sym_log_header] = "log_header",
  [sym_log_level_settings] = "log_level_settings",
  [sym_log_level_setting] = "log_level_setting",
  [sym_component] = "component",
  [sym_log_level] = "log_level",
  [sym_anonymous_block] = "anonymous_block",
  [sym__anonymous_label] = "_anonymous_label",
  [sym_log_entry] = "log_entry",
  [sym_location] = "location",
  [sym_namespace] = "namespace",
  [sym_limit_usage] = "limit_usage",
  [sym_limit] = "limit",
  [sym_event_details] = "event_details",
  [sym_event_detail] = "event_detail",
  [sym_timestamp] = "timestamp",
  [sym_duration] = "duration",
  [sym_event_identifier] = "event_identifier",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_log_level_settings_repeat1] = "log_level_settings_repeat1",
  [aux_sym_anonymous_block_repeat1] = "anonymous_block_repeat1",
  [aux_sym_limit_usage_repeat1] = "limit_usage_repeat1",
  [aux_sym_event_details_repeat1] = "event_details_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [sym_version] = sym_version,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_DB] = anon_sym_DB,
  [anon_sym_WORKFLOW] = anon_sym_WORKFLOW,
  [anon_sym_NBA] = anon_sym_NBA,
  [anon_sym_VALIDATION] = anon_sym_VALIDATION,
  [anon_sym_CALLOUT] = anon_sym_CALLOUT,
  [anon_sym_APEX_CODE] = anon_sym_APEX_CODE,
  [anon_sym_APEX_PROFILING] = anon_sym_APEX_PROFILING,
  [anon_sym_VISUALFORCE] = anon_sym_VISUALFORCE,
  [anon_sym_SYSTEM] = anon_sym_SYSTEM,
  [anon_sym_WAVE] = anon_sym_WAVE,
  [anon_sym_DATA_ACCESS] = anon_sym_DATA_ACCESS,
  [anon_sym_NONE] = anon_sym_NONE,
  [anon_sym_ERROR] = anon_sym_ERROR,
  [anon_sym_WARN] = anon_sym_WARN,
  [anon_sym_INFO] = anon_sym_INFO,
  [anon_sym_DEBUG] = anon_sym_DEBUG,
  [anon_sym_FINE] = anon_sym_FINE,
  [anon_sym_FINER] = anon_sym_FINER,
  [anon_sym_FINEST] = anon_sym_FINEST,
  [anon_sym_ExecuteAnonymous_COLON] = anon_sym_ExecuteAnonymous_COLON,
  [sym_apex_code] = sym_apex_code,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_PIPE_LBRACK] = anon_sym_PIPE_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_PIPE_LPAREN] = anon_sym_PIPE_LPAREN,
  [anon_sym_RPAREN_PIPE] = anon_sym_RPAREN_PIPE,
  [anon_sym_EXTERNAL] = anon_sym_EXTERNAL,
  [aux_sym_limit_token1] = sym_identifier,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_outof] = anon_sym_outof,
  [sym_event_detail_value] = sym_event_detail_value,
  [sym_time] = sym_time,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_number] = sym_number,
  [sym_identifier] = sym_identifier,
  [sym_source_file] = sym_source_file,
  [sym_log_header] = sym_log_header,
  [sym_log_level_settings] = sym_log_level_settings,
  [sym_log_level_setting] = sym_log_level_setting,
  [sym_component] = sym_component,
  [sym_log_level] = sym_log_level,
  [sym_anonymous_block] = sym_anonymous_block,
  [sym__anonymous_label] = sym__anonymous_label,
  [sym_log_entry] = sym_log_entry,
  [sym_location] = sym_location,
  [sym_namespace] = sym_namespace,
  [sym_limit_usage] = sym_limit_usage,
  [sym_limit] = sym_limit,
  [sym_event_details] = sym_event_details,
  [sym_event_detail] = sym_event_detail,
  [sym_timestamp] = sym_timestamp,
  [sym_duration] = sym_duration,
  [sym_event_identifier] = sym_event_identifier,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_log_level_settings_repeat1] = aux_sym_log_level_settings_repeat1,
  [aux_sym_anonymous_block_repeat1] = aux_sym_anonymous_block_repeat1,
  [aux_sym_limit_usage_repeat1] = aux_sym_limit_usage_repeat1,
  [aux_sym_event_details_repeat1] = aux_sym_event_details_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [sym_version] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DB] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_WORKFLOW] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NBA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VALIDATION] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CALLOUT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_APEX_CODE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_APEX_PROFILING] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VISUALFORCE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SYSTEM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_WAVE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DATA_ACCESS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NONE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ERROR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_WARN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_INFO] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DEBUG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FINE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FINER] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FINEST] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ExecuteAnonymous_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_apex_code] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EXTERNAL] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_limit_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_outof] = {
    .visible = true,
    .named = false,
  },
  [sym_event_detail_value] = {
    .visible = true,
    .named = true,
  },
  [sym_time] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_log_header] = {
    .visible = true,
    .named = true,
  },
  [sym_log_level_settings] = {
    .visible = true,
    .named = true,
  },
  [sym_log_level_setting] = {
    .visible = true,
    .named = true,
  },
  [sym_component] = {
    .visible = true,
    .named = true,
  },
  [sym_log_level] = {
    .visible = true,
    .named = true,
  },
  [sym_anonymous_block] = {
    .visible = true,
    .named = true,
  },
  [sym__anonymous_label] = {
    .visible = false,
    .named = true,
  },
  [sym_log_entry] = {
    .visible = true,
    .named = true,
  },
  [sym_location] = {
    .visible = true,
    .named = true,
  },
  [sym_namespace] = {
    .visible = true,
    .named = true,
  },
  [sym_limit_usage] = {
    .visible = true,
    .named = true,
  },
  [sym_limit] = {
    .visible = true,
    .named = true,
  },
  [sym_event_details] = {
    .visible = true,
    .named = true,
  },
  [sym_event_detail] = {
    .visible = true,
    .named = true,
  },
  [sym_timestamp] = {
    .visible = true,
    .named = true,
  },
  [sym_duration] = {
    .visible = true,
    .named = true,
  },
  [sym_event_identifier] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_log_level_settings_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_anonymous_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_limit_usage_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_event_details_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_available = 1,
  field_consumed = 2,
  field_name = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_available] = "available",
  [field_consumed] = "consumed",
  [field_name] = "name",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_available, 4},
    {field_consumed, 2},
    {field_name, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(147);
      ADVANCE_MAP(
        '(', 205,
        ')', 206,
        ',', 150,
        ':', 187,
        ';', 151,
        'A', 83,
        'C', 16,
        'D', 18,
        'E', 84,
        'F', 55,
        'I', 68,
        'N', 31,
        'S', 109,
        'V', 24,
        'W', 19,
        ']', 178,
        'o', 125,
        '|', 175,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(208);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '\n', 148,
        ';', 151,
        'A', 83,
        'C', 16,
        'D', 17,
        'N', 30,
        'S', 109,
        'V', 24,
        'W', 23,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(131);
      if (lookahead == ' ') ADVANCE(189);
      if (lookahead == '|') ADVANCE(174);
      if (('\t' <= lookahead && lookahead <= '\r')) ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead != 0) ADVANCE(201);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(131);
      if (lookahead == '|') ADVANCE(174);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead != 0) ADVANCE(201);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(119);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '|') ADVANCE(176);
      if (('\t' <= lookahead && lookahead <= '\r')) ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      if (lookahead != 0) ADVANCE(142);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(5);
      if (lookahead != 0 &&
          (lookahead < '0' || '9' < lookahead)) ADVANCE(142);
      END_STATE();
    case 8:
      if (lookahead == ' ') ADVANCE(22);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(137);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(138);
      if (lookahead == ':') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == '.') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == '.') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == ':') ADVANCE(139);
      END_STATE();
    case 14:
      if (lookahead == ':') ADVANCE(171);
      END_STATE();
    case 15:
      if (lookahead == ':') ADVANCE(140);
      END_STATE();
    case 16:
      if (lookahead == 'A') ADVANCE(62);
      END_STATE();
    case 17:
      if (lookahead == 'A') ADVANCE(99);
      if (lookahead == 'B') ADVANCE(152);
      END_STATE();
    case 18:
      if (lookahead == 'A') ADVANCE(99);
      if (lookahead == 'B') ADVANCE(152);
      if (lookahead == 'E') ADVANCE(29);
      END_STATE();
    case 19:
      if (lookahead == 'A') ADVANCE(88);
      if (lookahead == 'O') ADVANCE(86);
      END_STATE();
    case 20:
      if (lookahead == 'A') ADVANCE(154);
      END_STATE();
    case 21:
      if (lookahead == 'A') ADVANCE(32);
      END_STATE();
    case 22:
      if (lookahead == 'A') ADVANCE(118);
      END_STATE();
    case 23:
      if (lookahead == 'A') ADVANCE(105);
      if (lookahead == 'O') ADVANCE(86);
      END_STATE();
    case 24:
      if (lookahead == 'A') ADVANCE(61);
      if (lookahead == 'I') ADVANCE(93);
      END_STATE();
    case 25:
      if (lookahead == 'A') ADVANCE(111);
      END_STATE();
    case 26:
      if (lookahead == 'A') ADVANCE(66);
      END_STATE();
    case 27:
      if (lookahead == 'A') ADVANCE(60);
      END_STATE();
    case 28:
      if (lookahead == 'A') ADVANCE(100);
      END_STATE();
    case 29:
      if (lookahead == 'B') ADVANCE(102);
      END_STATE();
    case 30:
      if (lookahead == 'B') ADVANCE(20);
      END_STATE();
    case 31:
      if (lookahead == 'B') ADVANCE(20);
      if (lookahead == 'O') ADVANCE(73);
      END_STATE();
    case 32:
      if (lookahead == 'C') ADVANCE(34);
      END_STATE();
    case 33:
      if (lookahead == 'C') ADVANCE(77);
      if (lookahead == 'P') ADVANCE(90);
      END_STATE();
    case 34:
      if (lookahead == 'C') ADVANCE(46);
      END_STATE();
    case 35:
      if (lookahead == 'C') ADVANCE(44);
      END_STATE();
    case 36:
      if (lookahead == 'D') ADVANCE(28);
      END_STATE();
    case 37:
      if (lookahead == 'D') ADVANCE(43);
      END_STATE();
    case 38:
      if (lookahead == 'E') ADVANCE(107);
      END_STATE();
    case 39:
      if (lookahead == 'E') ADVANCE(168);
      END_STATE();
    case 40:
      if (lookahead == 'E') ADVANCE(163);
      END_STATE();
    case 41:
      if (lookahead == 'E') ADVANCE(161);
      END_STATE();
    case 42:
      if (lookahead == 'E') ADVANCE(67);
      END_STATE();
    case 43:
      if (lookahead == 'E') ADVANCE(157);
      END_STATE();
    case 44:
      if (lookahead == 'E') ADVANCE(159);
      END_STATE();
    case 45:
      if (lookahead == 'E') ADVANCE(108);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(45);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(209);
      END_STATE();
    case 46:
      if (lookahead == 'E') ADVANCE(95);
      END_STATE();
    case 47:
      if (lookahead == 'E') ADVANCE(89);
      END_STATE();
    case 48:
      if (lookahead == 'F') ADVANCE(75);
      END_STATE();
    case 49:
      if (lookahead == 'F') ADVANCE(57);
      END_STATE();
    case 50:
      if (lookahead == 'F') ADVANCE(82);
      END_STATE();
    case 51:
      if (lookahead == 'F') ADVANCE(64);
      END_STATE();
    case 52:
      if (lookahead == 'G') ADVANCE(167);
      END_STATE();
    case 53:
      if (lookahead == 'G') ADVANCE(158);
      END_STATE();
    case 54:
      if (lookahead == 'I') ADVANCE(36);
      END_STATE();
    case 55:
      if (lookahead == 'I') ADVANCE(72);
      END_STATE();
    case 56:
      if (lookahead == 'I') ADVANCE(71);
      END_STATE();
    case 57:
      if (lookahead == 'I') ADVANCE(65);
      END_STATE();
    case 58:
      if (lookahead == 'I') ADVANCE(81);
      END_STATE();
    case 59:
      if (lookahead == 'K') ADVANCE(51);
      END_STATE();
    case 60:
      if (lookahead == 'L') ADVANCE(181);
      END_STATE();
    case 61:
      if (lookahead == 'L') ADVANCE(54);
      END_STATE();
    case 62:
      if (lookahead == 'L') ADVANCE(63);
      END_STATE();
    case 63:
      if (lookahead == 'L') ADVANCE(80);
      END_STATE();
    case 64:
      if (lookahead == 'L') ADVANCE(76);
      END_STATE();
    case 65:
      if (lookahead == 'L') ADVANCE(56);
      END_STATE();
    case 66:
      if (lookahead == 'L') ADVANCE(50);
      END_STATE();
    case 67:
      if (lookahead == 'M') ADVANCE(160);
      END_STATE();
    case 68:
      if (lookahead == 'N') ADVANCE(48);
      END_STATE();
    case 69:
      if (lookahead == 'N') ADVANCE(165);
      END_STATE();
    case 70:
      if (lookahead == 'N') ADVANCE(155);
      END_STATE();
    case 71:
      if (lookahead == 'N') ADVANCE(53);
      END_STATE();
    case 72:
      if (lookahead == 'N') ADVANCE(39);
      END_STATE();
    case 73:
      if (lookahead == 'N') ADVANCE(40);
      END_STATE();
    case 74:
      if (lookahead == 'N') ADVANCE(27);
      END_STATE();
    case 75:
      if (lookahead == 'O') ADVANCE(166);
      END_STATE();
    case 76:
      if (lookahead == 'O') ADVANCE(106);
      END_STATE();
    case 77:
      if (lookahead == 'O') ADVANCE(37);
      END_STATE();
    case 78:
      if (lookahead == 'O') ADVANCE(87);
      END_STATE();
    case 79:
      if (lookahead == 'O') ADVANCE(49);
      END_STATE();
    case 80:
      if (lookahead == 'O') ADVANCE(103);
      END_STATE();
    case 81:
      if (lookahead == 'O') ADVANCE(70);
      END_STATE();
    case 82:
      if (lookahead == 'O') ADVANCE(91);
      END_STATE();
    case 83:
      if (lookahead == 'P') ADVANCE(38);
      END_STATE();
    case 84:
      if (lookahead == 'R') ADVANCE(85);
      if (lookahead == 'X') ADVANCE(98);
      if (lookahead == 'x') ADVANCE(113);
      END_STATE();
    case 85:
      if (lookahead == 'R') ADVANCE(78);
      END_STATE();
    case 86:
      if (lookahead == 'R') ADVANCE(59);
      END_STATE();
    case 87:
      if (lookahead == 'R') ADVANCE(164);
      END_STATE();
    case 88:
      if (lookahead == 'R') ADVANCE(69);
      if (lookahead == 'V') ADVANCE(41);
      END_STATE();
    case 89:
      if (lookahead == 'R') ADVANCE(74);
      END_STATE();
    case 90:
      if (lookahead == 'R') ADVANCE(79);
      END_STATE();
    case 91:
      if (lookahead == 'R') ADVANCE(35);
      END_STATE();
    case 92:
      if (lookahead == 'S') ADVANCE(162);
      END_STATE();
    case 93:
      if (lookahead == 'S') ADVANCE(104);
      END_STATE();
    case 94:
      if (lookahead == 'S') ADVANCE(101);
      END_STATE();
    case 95:
      if (lookahead == 'S') ADVANCE(92);
      END_STATE();
    case 96:
      if (lookahead == 'T') ADVANCE(170);
      END_STATE();
    case 97:
      if (lookahead == 'T') ADVANCE(156);
      END_STATE();
    case 98:
      if (lookahead == 'T') ADVANCE(47);
      END_STATE();
    case 99:
      if (lookahead == 'T') ADVANCE(25);
      END_STATE();
    case 100:
      if (lookahead == 'T') ADVANCE(58);
      END_STATE();
    case 101:
      if (lookahead == 'T') ADVANCE(42);
      END_STATE();
    case 102:
      if (lookahead == 'U') ADVANCE(52);
      END_STATE();
    case 103:
      if (lookahead == 'U') ADVANCE(97);
      END_STATE();
    case 104:
      if (lookahead == 'U') ADVANCE(26);
      END_STATE();
    case 105:
      if (lookahead == 'V') ADVANCE(41);
      END_STATE();
    case 106:
      if (lookahead == 'W') ADVANCE(153);
      END_STATE();
    case 107:
      if (lookahead == 'X') ADVANCE(110);
      END_STATE();
    case 108:
      if (lookahead == 'X') ADVANCE(98);
      END_STATE();
    case 109:
      if (lookahead == 'Y') ADVANCE(94);
      END_STATE();
    case 110:
      if (lookahead == '_') ADVANCE(33);
      END_STATE();
    case 111:
      if (lookahead == '_') ADVANCE(21);
      END_STATE();
    case 112:
      if (lookahead == 'c') ADVANCE(127);
      END_STATE();
    case 113:
      if (lookahead == 'e') ADVANCE(112);
      END_STATE();
    case 114:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 115:
      if (lookahead == 'f') ADVANCE(188);
      END_STATE();
    case 116:
      if (lookahead == 'm') ADVANCE(120);
      END_STATE();
    case 117:
      if (lookahead == 'n') ADVANCE(129);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(121);
      END_STATE();
    case 119:
      if (lookahead == 'o') ADVANCE(115);
      END_STATE();
    case 120:
      if (lookahead == 'o') ADVANCE(126);
      END_STATE();
    case 121:
      if (lookahead == 'o') ADVANCE(117);
      END_STATE();
    case 122:
      if (lookahead == 's') ADVANCE(14);
      END_STATE();
    case 123:
      if (lookahead == 't') ADVANCE(4);
      END_STATE();
    case 124:
      if (lookahead == 't') ADVANCE(114);
      END_STATE();
    case 125:
      if (lookahead == 'u') ADVANCE(123);
      END_STATE();
    case 126:
      if (lookahead == 'u') ADVANCE(122);
      END_STATE();
    case 127:
      if (lookahead == 'u') ADVANCE(124);
      END_STATE();
    case 128:
      if (lookahead == 'x') ADVANCE(113);
      END_STATE();
    case 129:
      if (lookahead == 'y') ADVANCE(116);
      END_STATE();
    case 130:
      if (lookahead == '|') ADVANCE(180);
      END_STATE();
    case 131:
      if (lookahead == '|') ADVANCE(174);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(131);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 132:
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(132);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(172);
      if (lookahead != 0) ADVANCE(173);
      END_STATE();
    case 133:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(186);
      END_STATE();
    case 134:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(210);
      END_STATE();
    case 135:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 136:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 137:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(204);
      END_STATE();
    case 138:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(149);
      END_STATE();
    case 139:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 140:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 141:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 142:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 143:
      if (eof) ADVANCE(147);
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == '|') ADVANCE(174);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead != 0) ADVANCE(201);
      END_STATE();
    case 144:
      if (eof) ADVANCE(147);
      if (lookahead == '(') ADVANCE(205);
      if (lookahead == '|') ADVANCE(174);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(144);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 145:
      if (eof) ADVANCE(147);
      if (lookahead == ')') ADVANCE(130);
      if (lookahead == 'E') ADVANCE(128);
      if (lookahead == '|') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(145);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 146:
      if (eof) ADVANCE(147);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (lookahead != 0 &&
          (lookahead < '0' || ':' < lookahead)) ADVANCE(186);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(148);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_version);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(149);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_DB);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_WORKFLOW);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_NBA);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_VALIDATION);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_CALLOUT);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_APEX_CODE);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_APEX_PROFILING);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_VISUALFORCE);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_SYSTEM);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_WAVE);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_DATA_ACCESS);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_NONE);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_ERROR);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_WARN);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_INFO);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_DEBUG);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_FINE);
      if (lookahead == 'R') ADVANCE(169);
      if (lookahead == 'S') ADVANCE(96);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_FINER);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_FINEST);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_ExecuteAnonymous_COLON);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_apex_code);
      if (lookahead == '\t' ||
          lookahead == 0x0b ||
          lookahead == '\f' ||
          lookahead == ' ') ADVANCE(172);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(173);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_apex_code);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(173);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '(') ADVANCE(179);
      if (lookahead == '[') ADVANCE(177);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_PIPE_LBRACK);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_PIPE_LPAREN);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_RPAREN_PIPE);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_EXTERNAL);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_limit_token1);
      if (lookahead == ':') ADVANCE(139);
      if (lookahead != 0) ADVANCE(186);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_limit_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      if (lookahead != 0 &&
          (lookahead < '0' || ':' < lookahead)) ADVANCE(186);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_limit_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(186);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_limit_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(182);
      if (lookahead != 0 &&
          (lookahead < '0' || ':' < lookahead)) ADVANCE(186);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_limit_token1);
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(186);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_outof);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(6);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '.') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == ':') ADVANCE(200);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == ':') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(197);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(198);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_event_detail_value);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(201);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_time);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_time);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(202);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_time);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(203);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == ':') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(209);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(207);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(209);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(210);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 145},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 145},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 145},
  [11] = {.lex_state = 144},
  [12] = {.lex_state = 144},
  [13] = {.lex_state = 145},
  [14] = {.lex_state = 145},
  [15] = {.lex_state = 145},
  [16] = {.lex_state = 145},
  [17] = {.lex_state = 145},
  [18] = {.lex_state = 145},
  [19] = {.lex_state = 144},
  [20] = {.lex_state = 145},
  [21] = {.lex_state = 146},
  [22] = {.lex_state = 146},
  [23] = {.lex_state = 143},
  [24] = {.lex_state = 133},
  [25] = {.lex_state = 45},
  [26] = {.lex_state = 144},
  [27] = {.lex_state = 145},
  [28] = {.lex_state = 144},
  [29] = {.lex_state = 145},
  [30] = {.lex_state = 146},
  [31] = {.lex_state = 145},
  [32] = {.lex_state = 134},
  [33] = {.lex_state = 134},
  [34] = {.lex_state = 145},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 144},
  [37] = {.lex_state = 45},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 144},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 145},
  [43] = {.lex_state = 132},
  [44] = {.lex_state = 144},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 145},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 45},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 45},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_DB] = ACTIONS(1),
    [anon_sym_WORKFLOW] = ACTIONS(1),
    [anon_sym_NBA] = ACTIONS(1),
    [anon_sym_VALIDATION] = ACTIONS(1),
    [anon_sym_CALLOUT] = ACTIONS(1),
    [anon_sym_APEX_CODE] = ACTIONS(1),
    [anon_sym_APEX_PROFILING] = ACTIONS(1),
    [anon_sym_VISUALFORCE] = ACTIONS(1),
    [anon_sym_SYSTEM] = ACTIONS(1),
    [anon_sym_WAVE] = ACTIONS(1),
    [anon_sym_DATA_ACCESS] = ACTIONS(1),
    [anon_sym_NONE] = ACTIONS(1),
    [anon_sym_ERROR] = ACTIONS(1),
    [anon_sym_WARN] = ACTIONS(1),
    [anon_sym_INFO] = ACTIONS(1),
    [anon_sym_DEBUG] = ACTIONS(1),
    [anon_sym_FINE] = ACTIONS(1),
    [anon_sym_FINER] = ACTIONS(1),
    [anon_sym_FINEST] = ACTIONS(1),
    [anon_sym_ExecuteAnonymous_COLON] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_PIPE_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_PIPE_LPAREN] = ACTIONS(1),
    [anon_sym_EXTERNAL] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_outof] = ACTIONS(1),
    [sym_time] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(35),
    [sym_log_header] = STATE(8),
    [sym_version] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    STATE(48), 1,
      sym_log_level_settings,
    STATE(50), 1,
      sym_component,
    STATE(4), 2,
      sym_log_level_setting,
      aux_sym_log_level_settings_repeat1,
    ACTIONS(5), 11,
      anon_sym_DB,
      anon_sym_WORKFLOW,
      anon_sym_NBA,
      anon_sym_VALIDATION,
      anon_sym_CALLOUT,
      anon_sym_APEX_CODE,
      anon_sym_APEX_PROFILING,
      anon_sym_VISUALFORCE,
      anon_sym_SYSTEM,
      anon_sym_WAVE,
      anon_sym_DATA_ACCESS,
  [24] = 4,
    ACTIONS(7), 1,
      anon_sym_LF,
    STATE(50), 1,
      sym_component,
    STATE(3), 2,
      sym_log_level_setting,
      aux_sym_log_level_settings_repeat1,
    ACTIONS(9), 11,
      anon_sym_DB,
      anon_sym_WORKFLOW,
      anon_sym_NBA,
      anon_sym_VALIDATION,
      anon_sym_CALLOUT,
      anon_sym_APEX_CODE,
      anon_sym_APEX_PROFILING,
      anon_sym_VISUALFORCE,
      anon_sym_SYSTEM,
      anon_sym_WAVE,
      anon_sym_DATA_ACCESS,
  [48] = 4,
    ACTIONS(12), 1,
      anon_sym_LF,
    STATE(50), 1,
      sym_component,
    STATE(3), 2,
      sym_log_level_setting,
      aux_sym_log_level_settings_repeat1,
    ACTIONS(14), 11,
      anon_sym_DB,
      anon_sym_WORKFLOW,
      anon_sym_NBA,
      anon_sym_VALIDATION,
      anon_sym_CALLOUT,
      anon_sym_APEX_CODE,
      anon_sym_APEX_PROFILING,
      anon_sym_VISUALFORCE,
      anon_sym_SYSTEM,
      anon_sym_WAVE,
      anon_sym_DATA_ACCESS,
  [72] = 2,
    ACTIONS(16), 1,
      anon_sym_LF,
    ACTIONS(18), 12,
      anon_sym_SEMI,
      anon_sym_DB,
      anon_sym_WORKFLOW,
      anon_sym_NBA,
      anon_sym_VALIDATION,
      anon_sym_CALLOUT,
      anon_sym_APEX_CODE,
      anon_sym_APEX_PROFILING,
      anon_sym_VISUALFORCE,
      anon_sym_SYSTEM,
      anon_sym_WAVE,
      anon_sym_DATA_ACCESS,
  [90] = 3,
    ACTIONS(20), 1,
      anon_sym_LF,
    ACTIONS(22), 1,
      anon_sym_SEMI,
    ACTIONS(24), 11,
      anon_sym_DB,
      anon_sym_WORKFLOW,
      anon_sym_NBA,
      anon_sym_VALIDATION,
      anon_sym_CALLOUT,
      anon_sym_APEX_CODE,
      anon_sym_APEX_PROFILING,
      anon_sym_VISUALFORCE,
      anon_sym_SYSTEM,
      anon_sym_WAVE,
      anon_sym_DATA_ACCESS,
  [110] = 2,
    ACTIONS(26), 1,
      anon_sym_LF,
    ACTIONS(28), 11,
      anon_sym_DB,
      anon_sym_WORKFLOW,
      anon_sym_NBA,
      anon_sym_VALIDATION,
      anon_sym_CALLOUT,
      anon_sym_APEX_CODE,
      anon_sym_APEX_PROFILING,
      anon_sym_VISUALFORCE,
      anon_sym_SYSTEM,
      anon_sym_WAVE,
      anon_sym_DATA_ACCESS,
  [127] = 8,
    ACTIONS(30), 1,
      ts_builtin_sym_end,
    ACTIONS(32), 1,
      anon_sym_ExecuteAnonymous_COLON,
    ACTIONS(34), 1,
      sym_time,
    STATE(13), 1,
      aux_sym_anonymous_block_repeat1,
    STATE(18), 1,
      sym_anonymous_block,
    STATE(43), 1,
      sym__anonymous_label,
    STATE(44), 1,
      sym_timestamp,
    STATE(20), 2,
      sym_log_entry,
      aux_sym_source_file_repeat1,
  [153] = 3,
    ACTIONS(38), 1,
      anon_sym_FINE,
    STATE(6), 1,
      sym_log_level,
    ACTIONS(36), 7,
      anon_sym_NONE,
      anon_sym_ERROR,
      anon_sym_WARN,
      anon_sym_INFO,
      anon_sym_DEBUG,
      anon_sym_FINER,
      anon_sym_FINEST,
  [169] = 6,
    ACTIONS(42), 1,
      anon_sym_PIPE,
    ACTIONS(44), 1,
      anon_sym_PIPE_LBRACK,
    ACTIONS(46), 1,
      anon_sym_PIPE_LPAREN,
    STATE(31), 1,
      sym_event_details,
    ACTIONS(40), 2,
      ts_builtin_sym_end,
      sym_time,
    STATE(19), 2,
      sym_event_detail,
      aux_sym_event_details_repeat1,
  [190] = 4,
    ACTIONS(50), 1,
      anon_sym_PIPE,
    STATE(34), 1,
      sym_event_details,
    ACTIONS(48), 2,
      ts_builtin_sym_end,
      sym_time,
    STATE(19), 2,
      sym_event_detail,
      aux_sym_event_details_repeat1,
  [205] = 3,
    ACTIONS(54), 1,
      anon_sym_PIPE,
    ACTIONS(52), 2,
      ts_builtin_sym_end,
      sym_time,
    STATE(12), 2,
      sym_event_detail,
      aux_sym_event_details_repeat1,
  [217] = 4,
    ACTIONS(32), 1,
      anon_sym_ExecuteAnonymous_COLON,
    STATE(16), 1,
      aux_sym_anonymous_block_repeat1,
    STATE(43), 1,
      sym__anonymous_label,
    ACTIONS(57), 2,
      ts_builtin_sym_end,
      sym_time,
  [231] = 4,
    ACTIONS(34), 1,
      sym_time,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    STATE(44), 1,
      sym_timestamp,
    STATE(15), 2,
      sym_log_entry,
      aux_sym_source_file_repeat1,
  [245] = 4,
    ACTIONS(61), 1,
      ts_builtin_sym_end,
    ACTIONS(63), 1,
      sym_time,
    STATE(44), 1,
      sym_timestamp,
    STATE(15), 2,
      sym_log_entry,
      aux_sym_source_file_repeat1,
  [259] = 4,
    ACTIONS(68), 1,
      anon_sym_ExecuteAnonymous_COLON,
    STATE(16), 1,
      aux_sym_anonymous_block_repeat1,
    STATE(43), 1,
      sym__anonymous_label,
    ACTIONS(66), 2,
      ts_builtin_sym_end,
      sym_time,
  [273] = 2,
    ACTIONS(73), 1,
      anon_sym_PIPE,
    ACTIONS(71), 4,
      ts_builtin_sym_end,
      anon_sym_PIPE_LBRACK,
      anon_sym_PIPE_LPAREN,
      sym_time,
  [283] = 4,
    ACTIONS(34), 1,
      sym_time,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
    STATE(44), 1,
      sym_timestamp,
    STATE(14), 2,
      sym_log_entry,
      aux_sym_source_file_repeat1,
  [297] = 3,
    ACTIONS(50), 1,
      anon_sym_PIPE,
    ACTIONS(77), 2,
      ts_builtin_sym_end,
      sym_time,
    STATE(12), 2,
      sym_event_detail,
      aux_sym_event_details_repeat1,
  [309] = 4,
    ACTIONS(34), 1,
      sym_time,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
    STATE(44), 1,
      sym_timestamp,
    STATE(15), 2,
      sym_log_entry,
      aux_sym_source_file_repeat1,
  [323] = 4,
    ACTIONS(79), 1,
      ts_builtin_sym_end,
    ACTIONS(81), 1,
      aux_sym_limit_token1,
    ACTIONS(83), 1,
      sym_time,
    STATE(22), 2,
      sym_limit,
      aux_sym_limit_usage_repeat1,
  [337] = 4,
    ACTIONS(85), 1,
      ts_builtin_sym_end,
    ACTIONS(87), 1,
      aux_sym_limit_token1,
    ACTIONS(90), 1,
      sym_time,
    STATE(22), 2,
      sym_limit,
      aux_sym_limit_usage_repeat1,
  [351] = 3,
    ACTIONS(92), 1,
      ts_builtin_sym_end,
    ACTIONS(96), 1,
      sym_event_detail_value,
    ACTIONS(94), 2,
      anon_sym_PIPE,
      sym_time,
  [362] = 3,
    ACTIONS(98), 1,
      aux_sym_limit_token1,
    STATE(34), 1,
      sym_limit_usage,
    STATE(21), 2,
      sym_limit,
      aux_sym_limit_usage_repeat1,
  [373] = 2,
    STATE(41), 1,
      sym_location,
    ACTIONS(100), 2,
      anon_sym_EXTERNAL,
      sym_number,
  [381] = 1,
    ACTIONS(102), 3,
      ts_builtin_sym_end,
      anon_sym_PIPE,
      sym_time,
  [387] = 1,
    ACTIONS(104), 3,
      ts_builtin_sym_end,
      anon_sym_ExecuteAnonymous_COLON,
      sym_time,
  [393] = 3,
    ACTIONS(106), 1,
      anon_sym_PIPE,
    ACTIONS(108), 1,
      anon_sym_LPAREN,
    STATE(36), 1,
      sym_duration,
  [403] = 1,
    ACTIONS(66), 3,
      ts_builtin_sym_end,
      anon_sym_ExecuteAnonymous_COLON,
      sym_time,
  [409] = 2,
    ACTIONS(110), 1,
      ts_builtin_sym_end,
    ACTIONS(112), 2,
      aux_sym_limit_token1,
      sym_time,
  [417] = 1,
    ACTIONS(114), 2,
      ts_builtin_sym_end,
      sym_time,
  [422] = 2,
    ACTIONS(116), 1,
      sym_identifier,
    STATE(10), 1,
      sym_event_identifier,
  [429] = 2,
    ACTIONS(118), 1,
      sym_identifier,
    STATE(42), 1,
      sym_namespace,
  [436] = 1,
    ACTIONS(120), 2,
      ts_builtin_sym_end,
      sym_time,
  [441] = 1,
    ACTIONS(122), 1,
      ts_builtin_sym_end,
  [445] = 1,
    ACTIONS(124), 1,
      anon_sym_PIPE,
  [449] = 1,
    ACTIONS(126), 1,
      sym_number,
  [453] = 1,
    ACTIONS(128), 1,
      anon_sym_RPAREN,
  [457] = 1,
    ACTIONS(130), 1,
      anon_sym_PIPE,
  [461] = 1,
    ACTIONS(132), 1,
      anon_sym_RBRACK,
  [465] = 1,
    ACTIONS(134), 1,
      anon_sym_RBRACK,
  [469] = 1,
    ACTIONS(136), 1,
      anon_sym_RPAREN_PIPE,
  [473] = 1,
    ACTIONS(138), 1,
      sym_apex_code,
  [477] = 1,
    ACTIONS(140), 1,
      anon_sym_PIPE,
  [481] = 1,
    ACTIONS(142), 1,
      anon_sym_COMMA,
  [485] = 1,
    ACTIONS(144), 1,
      anon_sym_RPAREN_PIPE,
  [489] = 1,
    ACTIONS(146), 1,
      anon_sym_COLON,
  [493] = 1,
    ACTIONS(148), 1,
      anon_sym_LF,
  [497] = 1,
    ACTIONS(150), 1,
      sym_number,
  [501] = 1,
    ACTIONS(152), 1,
      anon_sym_COMMA,
  [505] = 1,
    ACTIONS(154), 1,
      anon_sym_outof,
  [509] = 1,
    ACTIONS(156), 1,
      sym_number,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 72,
  [SMALL_STATE(6)] = 90,
  [SMALL_STATE(7)] = 110,
  [SMALL_STATE(8)] = 127,
  [SMALL_STATE(9)] = 153,
  [SMALL_STATE(10)] = 169,
  [SMALL_STATE(11)] = 190,
  [SMALL_STATE(12)] = 205,
  [SMALL_STATE(13)] = 217,
  [SMALL_STATE(14)] = 231,
  [SMALL_STATE(15)] = 245,
  [SMALL_STATE(16)] = 259,
  [SMALL_STATE(17)] = 273,
  [SMALL_STATE(18)] = 283,
  [SMALL_STATE(19)] = 297,
  [SMALL_STATE(20)] = 309,
  [SMALL_STATE(21)] = 323,
  [SMALL_STATE(22)] = 337,
  [SMALL_STATE(23)] = 351,
  [SMALL_STATE(24)] = 362,
  [SMALL_STATE(25)] = 373,
  [SMALL_STATE(26)] = 381,
  [SMALL_STATE(27)] = 387,
  [SMALL_STATE(28)] = 393,
  [SMALL_STATE(29)] = 403,
  [SMALL_STATE(30)] = 409,
  [SMALL_STATE(31)] = 417,
  [SMALL_STATE(32)] = 422,
  [SMALL_STATE(33)] = 429,
  [SMALL_STATE(34)] = 436,
  [SMALL_STATE(35)] = 441,
  [SMALL_STATE(36)] = 445,
  [SMALL_STATE(37)] = 449,
  [SMALL_STATE(38)] = 453,
  [SMALL_STATE(39)] = 457,
  [SMALL_STATE(40)] = 461,
  [SMALL_STATE(41)] = 465,
  [SMALL_STATE(42)] = 469,
  [SMALL_STATE(43)] = 473,
  [SMALL_STATE(44)] = 477,
  [SMALL_STATE(45)] = 481,
  [SMALL_STATE(46)] = 485,
  [SMALL_STATE(47)] = 489,
  [SMALL_STATE(48)] = 493,
  [SMALL_STATE(49)] = 497,
  [SMALL_STATE(50)] = 501,
  [SMALL_STATE(51)] = 505,
  [SMALL_STATE(52)] = 509,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_log_level_settings_repeat1, 2, 0, 0),
  [9] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_log_level_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [12] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_log_level_settings, 1, 0, 0),
  [14] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [16] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_log_level, 1, 0, 0),
  [18] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_log_level, 1, 0, 0),
  [20] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_log_level_setting, 3, 0, 0),
  [22] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [24] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_log_level_setting, 3, 0, 0),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_log_level_setting, 4, 0, 0),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_log_level_setting, 4, 0, 0),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [38] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_log_entry, 3, 0, 0),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_log_entry, 6, 0, 0),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_event_details_repeat1, 2, 0, 0),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_event_details_repeat1, 2, 0, 0), SHIFT_REPEAT(23),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anonymous_block, 1, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_anonymous_block_repeat1, 2, 0, 0),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_anonymous_block_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event_identifier, 1, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event_identifier, 1, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event_details, 1, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_usage, 1, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_limit_usage, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_limit_usage_repeat1, 2, 0, 0),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_limit_usage_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_limit_usage_repeat1, 2, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event_detail, 1, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_event_detail, 1, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event_detail, 2, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_log_header, 3, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timestamp, 1, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit, 5, 0, 1),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_limit, 5, 0, 1),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_log_entry, 4, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_log_entry, 7, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timestamp, 2, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 3, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_location, 1, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_component, 1, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace, 1, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_sflog(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
