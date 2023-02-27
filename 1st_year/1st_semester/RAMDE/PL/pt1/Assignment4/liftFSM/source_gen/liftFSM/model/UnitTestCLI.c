#include "UnitTestCLI.h"

#include "UnitTestUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void UnitTestCLI_validate_cli_options(void);

UnitTestCLI_UnitTestCLIOptions_t UnitTestCLI_options = 
{
  .program_name = NULL, 
  .build_dir = UnitTestDefinitions_DEFAULT_BUILD_PATH, 
  .flat_layout = false, 
  .short_names = false, 
  .host_tags = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }, 
  .isolated_mode = false, 
  .suite = NULL, 
  .caze = NULL
};

void UnitTestCLI_parse_cli_options(int32_t argc, char *argv[], UnitTestDefinitions_TestSuite_t *suites[], uint32_t suite_count)
{
  UnitTestCLI_options.program_name = argv[0];
  
  uint32_t recogized_option_count = 0;
  for ( int64_t __i = 1 ; __i < ((uint32_t) argc); __i++ )
  {
    char *arg = argv[__i];
    if (arg[0] == '-') 
    {
      /* 
       * Handle option
       */
      if ((strncmp(arg, "-b", strlen("-b")) == 0 || strncmp(arg, "--build-dir", strlen("--build-dir")) == 0)) 
      {
        strtok(arg, "=");
        char *arg_val = strtok(NULL, "=");
        if (arg_val == NULL) 
        {
          printf("%s: Option '%s' must have a value!\n\n", UnitTestDefinitions_USAGE_ERROR, arg);
          printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
          printf(UnitTestCLI_OPTIONS_MESSAGE);
          exit(UnitTestDefinitions_EXIT_USAGE_ERROR);
        }
        UnitTestCLI_options.build_dir = arg_val;
        recogized_option_count++;
        continue;
      }
      if ((strcmp(arg, "-f") == 0 || strcmp(arg, "--flat-layout") == 0)) 
      {
        UnitTestCLI_options.flat_layout = true;
        recogized_option_count++;
        continue;
      }
      if ((strcmp(arg, "-s") == 0 || strcmp(arg, "--short-names") == 0)) 
      {
        UnitTestCLI_options.short_names = true;
        recogized_option_count++;
        continue;
      }
      if (strncmp(arg, "-t", strlen("-t")) == 0 || strncmp(arg, "--host-tags", strlen("--host-tags")) == 0) 
      {
        strtok(arg, "=");
        char *arg_val = strtok(NULL, "=");
        if (arg_val == NULL) 
        {
          printf("%s: Option '%s' must have a value!\n\n", UnitTestDefinitions_USAGE_ERROR, arg);
          printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
          printf(UnitTestCLI_OPTIONS_MESSAGE);
          exit(UnitTestDefinitions_EXIT_USAGE_ERROR);
        }
        uint8_t i = 0;
        char *tag = strtok(arg_val, ",");
        while (tag != NULL)
        {
          if (i == UnitTestDefinitions_MAX_TAGS_COUNT) 
          {
            printf("%s: The number of comma-separated values for option '%s' must not exceed %d!\n\n", UnitTestDefinitions_USAGE_ERROR, arg, UnitTestDefinitions_MAX_TAGS_COUNT);
            printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
            printf(UnitTestCLI_OPTIONS_MESSAGE);
            exit(UnitTestDefinitions_EXIT_USAGE_ERROR);
          }
          UnitTestCLI_options.host_tags[i++] = tag;
          tag = strtok(NULL, ",");
        }
        recogized_option_count++;
        continue;
      }
      if ((strcmp(arg, "-i") == 0 || strcmp(arg, "--isolated") == 0)) 
      {
        UnitTestCLI_options.isolated_mode = true;
        recogized_option_count++;
        continue;
      }
      if ((strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0)) 
      {
        printf(UnitTestCLI_DESCRIPTION_MESSAGE);
        printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
        printf(UnitTestCLI_OPTIONS_MESSAGE);
        exit(EXIT_SUCCESS);
      }
    }
    else
    {
      /* 
       * Ignore extra arguments injected by Visual Studio Code debugger
       */
      if (strstr(arg, UnitTestCLI_VSCODE_EXTRA_ARG_1) != NULL || strstr(arg, UnitTestCLI_VSCODE_EXTRA_ARG_2) != NULL || strstr(arg, UnitTestCLI_VSCODE_EXTRA_ARG_3) != NULL) 
      {
        continue;
      }
      
      /* 
       * Handle argument
       */
      if (UnitTestCLI_options.suite == NULL) 
      {
        uint32_t suite_idx = ((uint32_t)(strtoul(argv[__i], NULL, 10)));
        if (suite_idx >= suite_count) 
        {
          printf("%s: Test suite index '%d' out of range!\n\n", UnitTestDefinitions_USAGE_ERROR, suite_idx);
          printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
          printf(UnitTestCLI_OPTIONS_MESSAGE);
          exit(UnitTestDefinitions_EXIT_USAGE_ERROR);
        }
        UnitTestCLI_options.suite = suites[suite_idx];
        recogized_option_count++;
        continue;
      }
      else if (UnitTestCLI_options.caze == NULL) {
        uint8_t case_idx = ((uint8_t)(strtoul(argv[__i], NULL, 10)));
        if (case_idx >= UnitTestCLI_options.suite->test_case_count) 
        {
          printf("%s: Test case index '%d' out of range!\n\n", UnitTestDefinitions_USAGE_ERROR, case_idx);
          printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
          printf(UnitTestCLI_OPTIONS_MESSAGE);
          exit(UnitTestDefinitions_EXIT_USAGE_ERROR);
        }
        UnitTestCLI_options.caze = &UnitTestCLI_options.suite->test_cases[case_idx];
        recogized_option_count++;
        continue;
      }
    }
    
    if (recogized_option_count <= 5) 
    {
      printf("%s: Option '%s' is not valid!\n\n", UnitTestDefinitions_USAGE_ERROR, arg);
      printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
      printf(UnitTestCLI_OPTIONS_MESSAGE);
      exit(UnitTestDefinitions_EXIT_USAGE_ERROR);
    }
    else
    {
      printf("%s: Argument list too long!\n\n", UnitTestDefinitions_USAGE_ERROR);
      printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
      printf(UnitTestCLI_OPTIONS_MESSAGE);
      exit(UnitTestDefinitions_EXIT_USAGE_ERROR);
    }
  }
  
  UnitTestCLI_validate_cli_options();
}

static void UnitTestCLI_validate_cli_options(void)
{
  if (UnitTestCLI_options.suite != NULL && UnitTestCLI_options.caze == NULL) 
  {
    printf("%s: Running all test cases of a specific test collection is not supported!\n\n", UnitTestDefinitions_USAGE_ERROR);
    printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
    printf(UnitTestCLI_OPTIONS_MESSAGE);
    exit(UnitTestDefinitions_EXIT_USAGE_ERROR);
  }
  
  if (UnitTestCLI_options.isolated_mode && UnitTestCLI_options.suite != NULL) 
  {
    printf("%s: Running individual test cases in an isolated process is not supported!\n\n", UnitTestDefinitions_USAGE_ERROR);
    printf(UnitTestCLI_USAGE_MESSAGE_FORMAT, UnitTestUtil_getSimpleProgramName(UnitTestCLI_options.program_name));
    printf(UnitTestCLI_OPTIONS_MESSAGE);
    exit(UnitTestDefinitions_EXIT_USAGE_ERROR);
  }
}

void UnitTestCLI_build_run_test_case_command(char *run_test_case_command, size_t run_test_case_command_size, uint32_t suite_idx, uint8_t case_idx)
{
  snprintf(run_test_case_command, run_test_case_command_size, "%s --build-dir=%s ", UnitTestCLI_options.program_name, UnitTestCLI_options.build_dir);
  if (UnitTestCLI_options.flat_layout) 
  {
    strncat(run_test_case_command, "--flat-layout ", run_test_case_command_size - strlen(run_test_case_command) - 1);
  }
  if (UnitTestCLI_options.short_names) 
  {
    strncat(run_test_case_command, "--short-names ", run_test_case_command_size - strlen(run_test_case_command) - 1);
  }
  if (UnitTestCLI_options.host_tags[0] != NULL) 
  {
    strncat(run_test_case_command, "--host-tags=", run_test_case_command_size - strlen(run_test_case_command) - 1);
    for ( uint8_t i = 0 ; UnitTestCLI_options.host_tags[i] != NULL && i < UnitTestDefinitions_MAX_TAGS_COUNT; i++ )
    {
      strncat(run_test_case_command, UnitTestCLI_options.host_tags[i], run_test_case_command_size - strlen(run_test_case_command) - 1);
      if (i < UnitTestDefinitions_MAX_TAGS_COUNT - 1 && UnitTestCLI_options.host_tags[i + 1] != NULL) 
      {
        strncat(run_test_case_command, ",", run_test_case_command_size - strlen(run_test_case_command) - 1);
      }
      else
      {
        strncat(run_test_case_command, " ", run_test_case_command_size - strlen(run_test_case_command) - 1);
      }
    }
  }
  snprintf(run_test_case_command + strlen(run_test_case_command), run_test_case_command_size - strlen(run_test_case_command), " %d %d", suite_idx, case_idx);
}
