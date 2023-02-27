#ifndef UNITTESTCLI_H
#define UNITTESTCLI_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "UnitTestDefinitions.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UnitTestCLI_DESCRIPTION_MESSAGE "Run tests contained in this test runner executable. Include a single test as\nper provided test collection and test case indexes, or all tests otherwise.\n\n"

#define UnitTestCLI_USAGE_MESSAGE_FORMAT "Usage: %s [option ...] [test-collection-index test-case-index]\n\n"

#define UnitTestCLI_OPTIONS_MESSAGE "Options:\n  -b, --build-dir=DIR\tabsolute or relative path to directory in which to\n\t\t\tplace the artifacts produced during the test run \n\t\t\t(defaults to './build')\n  -f, --flat-layout\tplace test result files directly into the build\n\t\t\tdirectory\n  -s, --short-names\tuse short test result file name format\n  -t, --host-tags\tcomma-separated list of tags providing hints\n\t\t\tabout the host platform the tests are being run on\n  -i, --isolated\trun each test case in an isolated process to enable\n\t\t\ttracking of fatal errors (e.g., segfaults)\n  -h, --help\t\tdisplay this help and exit\n\n\n"

#define UnitTestCLI_VSCODE_EXTRA_ARG_1 "2>CON"

#define UnitTestCLI_VSCODE_EXTRA_ARG_2 "1>CON"

#define UnitTestCLI_VSCODE_EXTRA_ARG_3 "<CON"

struct UnitTestCLI_UnitTestCLIOptions {
  /* 
   * Retrieved from argv[0]
   */
  char *program_name;
  /* 
   * Specified by -b, --build-dir option (e.g., --build-dir=/tmp/mbeddr-test-results/my/project)
   */
  char *build_dir;
  /* 
   * Specified by -f, --flat-layout option
   */
  bool flat_layout;
  /* 
   * Specified by -s, --short-names option
   */
  bool short_names;
  /* 
   * Specified by -t, --host-tags option
   */
  char const *host_tags[UnitTestDefinitions_MAX_TAGS_COUNT];
  /* 
   * Specified by -i, --isolated option
   */
  bool isolated_mode;
  /* 
   * Derived from first argument
   */
  UnitTestDefinitions_TestSuite_t *suite;
  /* 
   * Derived from second argument
   */
  UnitTestDefinitions_TestCase_t *caze;
};
typedef struct UnitTestCLI_UnitTestCLIOptions UnitTestCLI_UnitTestCLIOptions_t;

void UnitTestCLI_parse_cli_options(int32_t argc, char *argv[], UnitTestDefinitions_TestSuite_t *suites[], uint32_t suite_count);

void UnitTestCLI_build_run_test_case_command(char *run_test_case_command, size_t run_test_case_command_size, uint32_t suite_idx, uint8_t case_idx);

extern UnitTestCLI_UnitTestCLIOptions_t UnitTestCLI_options;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
