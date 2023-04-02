#ifndef UNITTESTDEFINITIONS_H
#define UNITTESTDEFINITIONS_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UnitTestDefinitions_MAX_TEST_CASES_PER_TEST_SUITE_COUNT 256

#define UnitTestDefinitions_MAX_TAGS_COUNT 10

#define UnitTestDefinitions_MAX_NAME_LENGTH 127

#define UnitTestDefinitions_MAX_PATH_LENGTH 511

#define UnitTestDefinitions_MAX_TEST_RUN_COMMAND_LENGTH (UnitTestDefinitions_MAX_PATH_LENGTH)

#define UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH 255

#define UnitTestDefinitions_MAX_TEST_ERROR_TYPE_LENGTH 31

#define UnitTestDefinitions_MAX_TEST_ERROR_MESSAGE_LENGTH 255

#define UnitTestDefinitions_DEFAULT_BUILD_PATH "./build"

#define UnitTestDefinitions_TMP_DIR_NAME "tmp"

#define UnitTestDefinitions_TEST_RESULTS_DIR_NAME "test-results"

#define UnitTestDefinitions_STDOUT_POSTFIX "out"

#define UnitTestDefinitions_STDERR_POSTFIX "err"

#define UnitTestDefinitions_EXIT_SKIPPED 2

#define UnitTestDefinitions_USAGE_ERROR "USAGE ERROR"

#define UnitTestDefinitions_EXIT_USAGE_ERROR 3

#define UnitTestDefinitions_IO_ERROR "I/O ERROR"

#define UnitTestDefinitions_EXIT_IO_ERROR 4

#define UnitTestDefinitions_INTERNAL_ERROR "INTERNAL ERROR"

#define UnitTestDefinitions_EXIT_INTERNAL_ERROR 5

enum UnitTestDefinitions_TestState {
  UnitTestDefinitions_TestState__TEST_STATE_NONE,
  UnitTestDefinitions_TestState__TEST_STATE_SKIPPED,
  UnitTestDefinitions_TestState__TEST_STATE_SUCCESS,
  UnitTestDefinitions_TestState__TEST_STATE_FAILURE,
  UnitTestDefinitions_TestState__TEST_STATE_ERROR
};
typedef enum UnitTestDefinitions_TestState UnitTestDefinitions_TestState_t;

struct UnitTestDefinitions_TestCase {
  uint8_t id;
  char *name;
  char *class_name;
  char *model_id;
  char *node_id;
  UnitTestDefinitions_TestState_t state;
};
typedef struct UnitTestDefinitions_TestCase UnitTestDefinitions_TestCase_t;

struct UnitTestDefinitions_TestSuite {
  char *name;
  char *module_name;
  char *model_name;
  uint8_t test_case_count;
  UnitTestDefinitions_TestCase_t test_cases[UnitTestDefinitions_MAX_TEST_CASES_PER_TEST_SUITE_COUNT];
  uint8_t required_tag_count;
  char const *required_tags[UnitTestDefinitions_MAX_TAGS_COUNT];
  uint8_t skipped_count;
  uint8_t failure_count;
  uint8_t error_count;
  void ((*(init))());
  int32_t ((*(invoke_test_case))(UnitTestDefinitions_TestCase_t *));
};
typedef struct UnitTestDefinitions_TestSuite UnitTestDefinitions_TestSuite_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
