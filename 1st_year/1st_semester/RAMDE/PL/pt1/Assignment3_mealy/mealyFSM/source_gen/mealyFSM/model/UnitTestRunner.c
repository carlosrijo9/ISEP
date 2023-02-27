#include "UnitTestRunner.h"

#if defined(_WIN32)
#include <io.h>
#else
#include <unistd.h>
#endif
#if defined(_WIN32)
#include <winsock2.h>
#else
#include <unistd.h>
#endif
#if defined(_WIN32)
#include <windows.h>
#else
#include <sys/wait.h>
#endif
#include "UnitTestCLI.h"
#include "UnitTestJUnitXML.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>

static bool UnitTestRunner_test_suite_tags_honored(UnitTestDefinitions_TestSuite_t *suite);

static int32_t UnitTestRunner_run_test_case(UnitTestDefinitions_TestSuite_t *suite, UnitTestDefinitions_TestCase_t *caze, char *stdout_capture_path, char *stderr_capture_path);

static int32_t UnitTestRunner_convert_to_test_case_result_status(int32_t test_case_result_value);

static void UnitTestRunner_get_test_results_path(char *test_results_path, size_t test_results_path_size, bool absolute);

static void UnitTestRunner_get_test_suite_result_path(char *test_suite_result_path, size_t test_suite_result_path_size, UnitTestDefinitions_TestSuite_t *suite);

static void UnitTestRunner_get_tmp_path(char *tmp_path, size_t tmp_path_size);

static void UnitTestRunner_get_std_stream_capture_path(char *std_stream_capture_path, size_t std_stream_capture_path_size, UnitTestDefinitions_TestCase_t *caze, char const *std_stream_postfix);

static void UnitTestRunner_process_test_case_result_status(int32_t result, UnitTestDefinitions_TestCase_t *caze, char *error_type, size_t error_type_size, char *error_message, size_t error_message_size);

static void UnitTestRunner_process_test_case_error_status(int32_t error_status, char *case_name, char *error_type, size_t error_type_size, char *error_message, size_t error_message_size);

static void UnitTestRunner_process_test_case_exit_status(int32_t exit_status, UnitTestDefinitions_TestCase_t *caze, char *error_type, size_t error_type_size, char *error_message, size_t error_message_size);

static FILE *UnitTestRunner_suite_result_file = NULL;

void UnitTestRunner_init_test_campaign(UnitTestDefinitions_TestSuite_t *suites[], uint32_t suiteCount)
{
  char test_results_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
  UnitTestRunner_get_test_results_path(test_results_path, sizeof(test_results_path), false);
  if (UnitTestUtil_mkpath(test_results_path) != 0) 
  {
    printf("%s: Failed to create '%s' directory!\n", UnitTestDefinitions_IO_ERROR, test_results_path);
    exit(UnitTestDefinitions_EXIT_IO_ERROR);
  }
  
  char tmp_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
  UnitTestRunner_get_tmp_path(tmp_path, sizeof(tmp_path));
  if (UnitTestUtil_mkpath(tmp_path) != 0) 
  {
    printf("%s: Failed to create '%s' directory!\n", UnitTestDefinitions_IO_ERROR, tmp_path);
    exit(UnitTestDefinitions_EXIT_IO_ERROR);
  }
  
  for ( uint32_t i = 0 ; i < suiteCount; i++ )
  {
    UnitTestDefinitions_TestSuite_t *suite = suites[i];
    if (UnitTestRunner_test_suite_tags_honored(suite)) 
    {
      (*suite->init)();
    }
    else
    {
      for ( uint32_t j = 0 ; j < suite->test_case_count; j++ )
      {
        UnitTestDefinitions_TestCase_t *caze = &suite->test_cases[j];
        caze->state = UnitTestDefinitions_TestState__TEST_STATE_SKIPPED;
      }
    }
  }
}

void UnitTestRunner_run_test_campaign(UnitTestDefinitions_TestSuite_t *suites[], uint32_t suite_count)
{
  char timestamp[sizeof("2018-09-14T15:58:24")];
  time_t now;
  time(&now);
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%dT%H:%M:%S", localtime(&now));
  
  char host_name[UnitTestDefinitions_MAX_NAME_LENGTH + 1] = "";
  #if defined(_WIN32)
  WSADATA wsaData;
  WSAStartup(MAKEWORD(2, 2), &wsaData);
  gethostname(host_name, sizeof(host_name));
  /* 
   * !!! Important Note !!! Do not call WSACleanup() directly from here, but in 
   * cleanup_system_resources() exit handler instead. Otherwise it may become impossible to debug
   * the rest of the application in a reliable manner using Visual Studio Code (and potentially also 
   * other tools) due to errors like "Exception has occurred. Debugger was unable to continue the 
   * process.".
   */
  #else /* defined(_WIN32) */
  gethostname(host_name, sizeof(host_name));
  #endif /* defined(_WIN32) */

  
  for ( uint32_t i = 0 ; i < suite_count; i++ )
  {
    UnitTestDefinitions_TestSuite_t *suite = suites[i];
    if (suite->test_case_count == 0) 
    {
      continue;
    }
    
    char suite_result_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
    UnitTestRunner_get_test_suite_result_path(suite_result_path, sizeof(suite_result_path), suite);
    UnitTestRunner_suite_result_file = UnitTestJUnitXML_begin_test_suite_result_file(suite_result_path, suite, timestamp, host_name);
    if (UnitTestRunner_suite_result_file == NULL) 
    {
      exit(UnitTestDefinitions_EXIT_IO_ERROR);
    }
    
    for ( uint8_t j = 0 ; j < suite->test_case_count; j++ )
    {
      UnitTestDefinitions_TestCase_t *caze = &suite->test_cases[j];
      UnitTestJUnitXML_begin_test_case_result(UnitTestRunner_suite_result_file, caze);
      
      char stdout_capture_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
      UnitTestRunner_get_std_stream_capture_path(stdout_capture_path, sizeof(stdout_capture_path), caze, UnitTestDefinitions_STDOUT_POSTFIX);
      char stderr_capture_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
      UnitTestRunner_get_std_stream_capture_path(stderr_capture_path, sizeof(stderr_capture_path), caze, UnitTestDefinitions_STDERR_POSTFIX);
      
      char error_type[UnitTestDefinitions_MAX_TEST_ERROR_TYPE_LENGTH + 1] = "";
      char error_message[UnitTestDefinitions_MAX_TEST_ERROR_MESSAGE_LENGTH + 1] = "";
      
      if (!UnitTestCLI_options.isolated_mode) 
      {
        int32_t result_status = UnitTestRunner_run_test_case(suite, caze, stdout_capture_path, stderr_capture_path);
        
        UnitTestRunner_process_test_case_result_status(result_status, caze, error_type, sizeof(error_type), error_message, sizeof(error_message));
      }
      else
      {
        UnitTestJUnitXML_suspend_test_suite_result_file(UnitTestRunner_suite_result_file);
        
        char run_test_case_command[UnitTestDefinitions_MAX_TEST_RUN_COMMAND_LENGTH + 1] = "";
        UnitTestCLI_build_run_test_case_command(run_test_case_command, sizeof(run_test_case_command), i, j);
        
        int32_t exit_status = system(run_test_case_command);
        if (exit_status == -1) 
        {
          printf("%s: Failed to spawn child process for running '%s':!\n", UnitTestDefinitions_INTERNAL_ERROR, caze->name);
          exit_status = UnitTestDefinitions_EXIT_INTERNAL_ERROR;
        }
        
        UnitTestRunner_suite_result_file = UnitTestJUnitXML_resume_test_suite_result_file(suite_result_path, suite);
        if (UnitTestRunner_suite_result_file == NULL) 
        {
          exit_status = UnitTestDefinitions_EXIT_IO_ERROR;
        }
        
        UnitTestRunner_process_test_case_exit_status(exit_status, caze, error_type, sizeof(error_type), error_message, sizeof(error_message));
      }
      
      switch (caze->state)
      {
        case UnitTestDefinitions_TestState__TEST_STATE_SUCCESS:
        {
          /* 
           * test passed - nothing to
           */
          break;
        }
        case UnitTestDefinitions_TestState__TEST_STATE_SKIPPED:
        {
          /* 
           * test skipped - nothing to do here, skipped info has already been added during test run
           */
          suite->skipped_count++;
          break;
        }
        case UnitTestDefinitions_TestState__TEST_STATE_FAILURE:
        {
          /* 
           * expectations failed - nothing to do here, failure info has already been added during test run
           */
          suite->failure_count++;
          break;
        }
        case UnitTestDefinitions_TestState__TEST_STATE_ERROR:
        {
          /* 
           * unexpected error like segfault
           */
          printf("ERROR: ***ERROR*** (test case=%s, message=%s type=%s\n", caze->name, error_message, error_type);
          UnitTestJUnitXML_append_error_info(UnitTestRunner_suite_result_file, error_message, error_type);
          suite->error_count++;
          break;
        }
      }
      
      if (!UnitTestJUnitXML_append_std_stream_capture(UnitTestRunner_suite_result_file, caze, stdout_capture_path, stdout)) 
      {
        exit(UnitTestDefinitions_EXIT_IO_ERROR);
      }
      if (!UnitTestJUnitXML_append_std_stream_capture(UnitTestRunner_suite_result_file, caze, stderr_capture_path, stderr)) 
      {
        exit(UnitTestDefinitions_EXIT_IO_ERROR);
      }
      
      UnitTestJUnitXML_end_test_case_result(UnitTestRunner_suite_result_file);
    }
    
    UnitTestJUnitXML_end_test_suite_result_file(UnitTestRunner_suite_result_file);
    
    if (!UnitTestJUnitXML_finalize_test_suite_result_file(suite_result_path, suite)) 
    {
      exit(UnitTestDefinitions_EXIT_IO_ERROR);
    }
  }
}

int32_t UnitTestRunner_init_test_suite_and_run_test_case(UnitTestDefinitions_TestSuite_t *suite, UnitTestDefinitions_TestCase_t *caze)
{
  if (UnitTestRunner_test_suite_tags_honored(suite)) 
  {
    (*suite->init)();
  }
  else
  {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_SKIPPED;
  }
  
  char suite_result_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
  UnitTestRunner_get_test_suite_result_path(suite_result_path, sizeof(suite_result_path), suite);
  UnitTestRunner_suite_result_file = UnitTestJUnitXML_resume_test_suite_result_file(suite_result_path, suite);
  if (UnitTestRunner_suite_result_file == NULL) 
  {
    exit(UnitTestDefinitions_EXIT_IO_ERROR);
  }
  
  char stdout_capture_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
  UnitTestRunner_get_std_stream_capture_path(stdout_capture_path, sizeof(stdout_capture_path), caze, UnitTestDefinitions_STDOUT_POSTFIX);
  char stderr_capture_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
  UnitTestRunner_get_std_stream_capture_path(stderr_capture_path, sizeof(stderr_capture_path), caze, UnitTestDefinitions_STDERR_POSTFIX);
  
  int32_t result_status = UnitTestRunner_run_test_case(suite, caze, stdout_capture_path, stderr_capture_path);
  
  UnitTestJUnitXML_suspend_test_suite_result_file(UnitTestRunner_suite_result_file);
  
  return result_status;
}

static bool UnitTestRunner_test_suite_tags_honored(UnitTestDefinitions_TestSuite_t *suite)
{
  for ( uint8_t i = 0 ; i < suite->required_tag_count; i++ )
  {
    char const *required_tag = suite->required_tags[i];
    bool required_tag_found = false;
    
    uint8_t j = 0;
    char const *host_tag = UnitTestCLI_options.host_tags[j++];
    while (host_tag != NULL)
    {
      if (strcmp(host_tag, required_tag) == 0) 
      {
        required_tag_found = true;
        break;
      }
      host_tag = UnitTestCLI_options.host_tags[j++];
    }
    if (!required_tag_found) 
    {
      return false;
    }
  }
  return true;
}

static int32_t UnitTestRunner_run_test_case(UnitTestDefinitions_TestSuite_t *suite, UnitTestDefinitions_TestCase_t *caze, char *stdout_capture_path, char *stderr_capture_path)
{
  if (caze->state != UnitTestDefinitions_TestState__TEST_STATE_SKIPPED) 
  {
    /* 
     * Flush all unrelated stdout/stderr output that may have been accumulated up to here to make sure that it doesn't 
     * get mixed into the stdout/stderr output being captured when running given test case
     */
    fflush(stdout);
    fflush(stderr);
    
    /* 
     * Redirect all stdout/stderr output to stdout/stderr capture files
     * See https://www.unix.com/programming/268879-c-unix-how-redirect-stdout-file-c-code.html for details
     */
    FILE *stdout_capture_file = fopen(stdout_capture_path, "w");
    if (stdout_capture_file == NULL) 
    {
      printf("%s: Failed to create '%s' file for writing!\n", UnitTestDefinitions_IO_ERROR, stdout_capture_path);
      exit(UnitTestDefinitions_EXIT_IO_ERROR);
    }
    FILE *stderr_capture_file = fopen(stderr_capture_path, "w");
    if (stderr_capture_file == NULL) 
    {
      printf("%s: Failed to create '%s' file for writing!\n", UnitTestDefinitions_IO_ERROR, stderr_capture_path);
      exit(UnitTestDefinitions_EXIT_IO_ERROR);
    }
    int32_t old_stdout_state = dup(fileno(stdout));
    int32_t old_stderr_state = dup(fileno(stderr));
    if (dup2(fileno(stdout_capture_file), fileno(stdout)) < 0) 
    {
      printf("%s: Failed to redirect stdout to '%s' file!\n", UnitTestDefinitions_IO_ERROR, stdout_capture_path);
    }
    if (dup2(fileno(stderr_capture_file), fileno(stderr)) < 0) 
    {
      printf("%s: Failed to redirect stderr to '%s' file!\n", UnitTestDefinitions_IO_ERROR, stderr_capture_path);
    }
    
    /* 
     * Run given test case and compute result status
     */
    int32_t result_value = (*suite->invoke_test_case)(caze);
    int32_t result_status = UnitTestRunner_convert_to_test_case_result_status(result_value);
    
    /* 
     * Close up stdout/stderr capture files and redirect all stdout/stderr output back to console
     * See https://www.unix.com/programming/268879-c-unix-how-redirect-stdout-file-c-code.html for details
     */
    fflush(stdout);
    fflush(stderr);
    fclose(stdout_capture_file);
    fclose(stderr_capture_file);
    dup2(old_stdout_state, fileno(stdout));
    dup2(old_stderr_state, fileno(stderr));
    close(old_stdout_state);
    close(old_stderr_state);
    
    /* 
     * Re-adjust stdout/stderr buffering to keep up performance of printf/fprintf operations 
     * (which might go down by factor 6 otherwise)
     */
    setvbuf(stdout, NULL, _IOLBF, 1024);
    setvbuf(stderr, NULL, _IOLBF, 1024);
    
    return result_status;
  }
  else
  {
    UnitTestJUnitXML_append_skipped_info(UnitTestRunner_suite_result_file);
    return UnitTestDefinitions_EXIT_SKIPPED;
  }
}

static int32_t UnitTestRunner_convert_to_test_case_result_status(int32_t test_case_result_value)
{
  if (test_case_result_value == 0) 
  {
    return EXIT_SUCCESS;
  }
  else if (test_case_result_value > 0) {
    return EXIT_FAILURE;
  }
  else
  {
    return UnitTestDefinitions_EXIT_INTERNAL_ERROR;
  }
}

static void UnitTestRunner_get_test_results_path(char *test_results_path, size_t test_results_path_size, bool absolute)
{
  if (absolute) 
  {
    UnitTestUtil_convertToAbsolutePath(UnitTestCLI_options.build_dir, test_results_path, test_results_path_size);
  }
  else
  {
    strncpy(test_results_path, UnitTestCLI_options.build_dir, test_results_path_size);
  }
  
  if (!UnitTestCLI_options.flat_layout) 
  {
    snprintf(test_results_path + strlen(test_results_path), test_results_path_size - strlen(test_results_path), "/%s", UnitTestDefinitions_TEST_RESULTS_DIR_NAME);
  }
}

static void UnitTestRunner_get_test_suite_result_path(char *test_suite_result_path, size_t test_suite_result_path_size, UnitTestDefinitions_TestSuite_t *suite)
{
  UnitTestRunner_get_test_results_path(test_suite_result_path, test_suite_result_path_size, false);
  
  /* 
   * Append test result file name using the following format: TEST-[<test-suite-module-name>.]<test-suite-name>.xml
   * Use short test result file name format when enforced via CLI option or when test suite name is sufficiently long so to be considered as globally unique
   * (e.g., 
   * "runTests" -> other test suites with this very name might exist
   * "runMyExtraordinaryNonRegressionTests" -> low probability that there is another test suite with exactly the same name)
   */
  strncat(test_suite_result_path, "/TEST-", test_suite_result_path_size - strlen(test_suite_result_path) - 1);
  if (!UnitTestCLI_options.short_names && strlen(suite->name) < 10) 
  {
    snprintf(test_suite_result_path + strlen(test_suite_result_path), test_suite_result_path_size - strlen(test_suite_result_path), "%s.", suite->module_name);
  }
  snprintf(test_suite_result_path + strlen(test_suite_result_path), test_suite_result_path_size - strlen(test_suite_result_path), "%s.xml", suite->name);
}

static void UnitTestRunner_get_tmp_path(char *tmp_path, size_t tmp_path_size)
{
  snprintf(tmp_path, tmp_path_size, "%s/%s", UnitTestCLI_options.build_dir, UnitTestDefinitions_TMP_DIR_NAME);
}

static void UnitTestRunner_get_std_stream_capture_path(char *std_stream_capture_path, size_t std_stream_capture_path_size, UnitTestDefinitions_TestCase_t *caze, char const *std_stream_postfix)
{
  UnitTestRunner_get_tmp_path(std_stream_capture_path, std_stream_capture_path_size);
  
  /* 
   * Append std stream capture file name using the following format: .<test-case-class-name>#<test-case-name>.(out|err)
   */
  snprintf(std_stream_capture_path + strlen(std_stream_capture_path), std_stream_capture_path_size - strlen(std_stream_capture_path), "/.%s#%d.%s", caze->class_name, caze->id, std_stream_postfix);
}

void UnitTestRunner_log_assert_fail_int_int(char const *messageFormat, char const *assertType, uint8_t assertId, int64_t expected, int64_t actual, char const *modelId, char const *nodeId)
{
  char message[UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), messageFormat, assertType, assertId, expected, actual);
  UnitTestJUnitXML_append_failure_info(UnitTestRunner_suite_result_file, message, assertType, modelId, nodeId);
}

void UnitTestRunner_log_assert_fail_double_int(char const *messageFormat, char const *assertType, uint8_t assertId, double expected, int64_t actual, char const *modelId, char const *nodeId)
{
  char message[UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), messageFormat, assertType, assertId, expected, actual);
  UnitTestJUnitXML_append_failure_info(UnitTestRunner_suite_result_file, message, assertType, modelId, nodeId);
}

void UnitTestRunner_log_assert_fail_range_int(char const *messageFormat, char const *assertType, uint8_t assertId, char const *expected, int64_t actual, char const *modelId, char const *nodeId)
{
  char message[UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), messageFormat, assertType, assertId, expected, actual);
  UnitTestJUnitXML_append_failure_info(UnitTestRunner_suite_result_file, message, assertType, modelId, nodeId);
}

void UnitTestRunner_log_assert_fail_double_double(char const *messageFormat, char const *assertType, uint8_t assertId, double expected, double actual, char const *modelId, char const *nodeId)
{
  char message[UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), messageFormat, assertType, assertId, expected, actual);
  UnitTestJUnitXML_append_failure_info(UnitTestRunner_suite_result_file, message, assertType, modelId, nodeId);
}

void UnitTestRunner_log_assert_fail_int_double(char const *messageFormat, char const *assertType, uint8_t assertId, int64_t expected, double actual, char const *modelId, char const *nodeId)
{
  char message[UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), messageFormat, assertType, assertId, expected, actual);
  UnitTestJUnitXML_append_failure_info(UnitTestRunner_suite_result_file, message, assertType, modelId, nodeId);
}

void UnitTestRunner_log_assert_fail_range_double(char const *messageFormat, char const *assertType, uint8_t assertId, char const *expected, double actual, char const *modelId, char const *nodeId)
{
  char message[UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), messageFormat, assertType, assertId, expected, actual);
  UnitTestJUnitXML_append_failure_info(UnitTestRunner_suite_result_file, message, assertType, modelId, nodeId);
}

void UnitTestRunner_log_assert_fail_bool_bool(char const *messageFormat, char const *assertType, uint8_t assertId, bool expected, bool actual, char const *modelId, char const *nodeId)
{
  char message[UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), messageFormat, assertType, assertId, UnitTestUtil_boolToStr(expected), UnitTestUtil_boolToStr(actual));
  UnitTestJUnitXML_append_failure_info(UnitTestRunner_suite_result_file, message, assertType, modelId, nodeId);
}

void UnitTestRunner_log_assert_fail_ptr_ptr(char const *messageFormat, char const *assertType, uint8_t assertId, void const *expected, void const *actual, char const *modelId, char const *nodeId)
{
  char message[UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), messageFormat, assertType, assertId, expected, actual);
  UnitTestJUnitXML_append_failure_info(UnitTestRunner_suite_result_file, message, assertType, modelId, nodeId);
}

void UnitTestRunner_log_assert_fail_range_ptr(char const *messageFormat, char const *assertType, uint8_t assertId, char const *expected, void const *actual, char const *modelId, char const *nodeId)
{
  char message[UnitTestDefinitions_MAX_TEST_FAILURE_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), messageFormat, assertType, assertId, expected, actual);
  UnitTestJUnitXML_append_failure_info(UnitTestRunner_suite_result_file, message, assertType, modelId, nodeId);
}

static void UnitTestRunner_process_test_case_result_status(int32_t result, UnitTestDefinitions_TestCase_t *caze, char *error_type, size_t error_type_size, char *error_message, size_t error_message_size)
{
  if (result == EXIT_SUCCESS) 
  {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_SUCCESS;
  }
  else if (result == UnitTestDefinitions_EXIT_SKIPPED) {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_SKIPPED;
  }
  else if (result == EXIT_FAILURE) {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_FAILURE;
  }
  else
  {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_ERROR;
    UnitTestRunner_process_test_case_error_status(result, caze->name, error_type, error_type_size, error_message, error_message_size);
  }
}

static void UnitTestRunner_process_test_case_error_status(int32_t error_status, char *case_name, char *error_type, size_t error_type_size, char *error_message, size_t error_message_size)
{
  switch (error_status)
  {
    case UnitTestDefinitions_EXIT_USAGE_ERROR:
    {
      strncpy(error_type, "usage error", error_type_size);
      snprintf(error_message, error_message_size, "%s: %s has been terminated due to a usage error", error_type, case_name);
      break;
    }
    case UnitTestDefinitions_EXIT_IO_ERROR:
    {
      strncpy(error_type, "I/O error", error_type_size);
      snprintf(error_message, error_message_size, "%s: %s has been terminated due to an I/O error", error_type, case_name);
      break;
    }
    case UnitTestDefinitions_EXIT_INTERNAL_ERROR:
    {
      strncpy(error_type, "internal error", error_type_size);
      snprintf(error_message, error_message_size, "%s: %s has been terminated due to an internal error", error_type, case_name);
      break;
    }
    default: {
      strncpy(error_type, "unknown error", error_type_size);
      snprintf(error_message, error_message_size, "%s: %s has been terminated for an unknown reason (exit/result status %d)", error_type, case_name, error_status);
      break;
    }
  }
}

static void UnitTestRunner_process_test_case_exit_status(int32_t exit_status, UnitTestDefinitions_TestCase_t *caze, char *error_type, size_t error_type_size, char *error_message, size_t error_message_size)
{
  #if defined(_WIN32)
  if (exit_status == EXIT_SUCCESS) 
  {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_SUCCESS;
  }
  else if (exit_status == UnitTestDefinitions_EXIT_SKIPPED) {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_SKIPPED;
  }
  else if (exit_status == EXIT_FAILURE) {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_FAILURE;
  }
  else
  {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_ERROR;
    
    switch (exit_status)
    {
      case EXCEPTION_ACCESS_VIOLATION:
      {
        strncpy(error_type, "segmentation fault", error_type_size);
        snprintf(error_message, error_message_size, "%s: %s has been terminated by a segmentation fault (access violation)", error_type, caze->name);
        break;
      }
      case EXCEPTION_PRIV_INSTRUCTION:
      case EXCEPTION_ILLEGAL_INSTRUCTION:
      {
        strncpy(error_type, "illegal instruction", error_type_size);
        snprintf(error_message, error_message_size, "%s: %s has been terminated due to an illegal instruction", error_type, caze->name);
        break;
      }
      case EXCEPTION_FLT_DENORMAL_OPERAND:
      case EXCEPTION_FLT_DIVIDE_BY_ZERO:
      case EXCEPTION_FLT_INEXACT_RESULT:
      case EXCEPTION_FLT_INVALID_OPERATION:
      case EXCEPTION_FLT_OVERFLOW:
      case EXCEPTION_FLT_STACK_CHECK:
      case EXCEPTION_FLT_UNDERFLOW:
      case EXCEPTION_INT_DIVIDE_BY_ZERO:
      case EXCEPTION_INT_OVERFLOW:
      {
        strncpy(error_type, "arithmetic error", error_type_size);
        snprintf(error_message, error_message_size, "%s: %s has been terminated due to an erroneous arithmetic operation", error_type, caze->name);
        break;
      }
      case CONTROL_C_EXIT:
      {
        strncpy(error_type, "termination request", error_type_size);
        snprintf(error_message, error_message_size, "%s: %s has been terminated due to a termination request", error_type, caze->name);
        break;
      }
      default: {
        UnitTestRunner_process_test_case_error_status(exit_status, caze->name, error_type, error_type_size, error_message, error_message_size);
        break;
      }
    }
  }
  #else /* defined(_WIN32) */
  /* 
   * See https://www.gnu.org/software/libc/manual/html_node/Exit-Status.html
   * and https://stackoverflow.com/a/8654562/2926305 
   * and http://tldp.org/LDP/abs/html/exitcodes.html  
   * for details
   */
  uint8_t command_exit_status = WEXITSTATUS(exit_status);
  if (command_exit_status == EXIT_SUCCESS) 
  {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_SUCCESS;
  }
  else if (command_exit_status == UnitTestDefinitions_EXIT_SKIPPED) {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_SKIPPED;
  }
  else if (command_exit_status == EXIT_FAILURE) {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_FAILURE;
  }
  else
  {
    caze->state = UnitTestDefinitions_TestState__TEST_STATE_ERROR;
    
    if (command_exit_status >= 128) 
    {
      int32_t zignal = command_exit_status - 128;
      switch (zignal)
      {
        case SIGSEGV:
        {
          strncpy(error_type, "segmentation fault", error_type_size);
          snprintf(error_message, error_message_size, "%s: %s has been terminated by a segmentation fault (access violation)", error_type, caze->name);
          break;
        }
        case SIGILL:
        {
          strncpy(error_type, "illegal instruction", error_type_size);
          snprintf(error_message, error_message_size, "%s: %s has been terminated due to an illegal instruction", error_type, caze->name);
          break;
        }
        case SIGABRT:
        {
          strncpy(error_type, "abnormal termination", error_type_size);
          snprintf(error_message, error_message_size, "%s: %s has been terminated abnormally", error_type, caze->name);
          break;
        }
        case SIGFPE:
        {
          strncpy(error_type, "arithmetic error", error_type_size);
          snprintf(error_message, error_message_size, "%s: %s has been terminated due to an erroneous arithmetic operation", error_type, caze->name);
          break;
        }
        case SIGINT:
        {
          strncpy(error_type, "interrupt signal", error_type_size);
          snprintf(error_message, error_message_size, "%s: %s has been terminated by an interactive attention signal", error_type, caze->name);
          break;
        }
        case SIGTERM:
        {
          strncpy(error_type, "termination request", error_type_size);
          snprintf(error_message, error_message_size, "%s: %s has been terminated due to a termination request", error_type, caze->name);
          break;
        }
        default: {
          strncpy(error_type, "signal", error_type_size);
          snprintf(error_message, error_message_size, "%s: %s has been terminated by signal %d", error_type, caze->name, zignal);
        }
      }
    }
    else
    {
      UnitTestRunner_process_test_case_error_status(command_exit_status, caze->name, error_type, error_type_size, error_message, error_message_size);
    }
  }
  #endif /* defined(_WIN32) */

}

int32_t UnitTestRunner_finalize_test_campaign(UnitTestDefinitions_TestSuite_t *suites[], uint32_t suite_count)
{
  /* 
   * Collect test execution statistics
   */
  int32_t total_test_case_count = 0;
  int32_t total_skipped_count = 0;
  int32_t total_failure_count = 0;
  int32_t total_error_count = 0;
  for ( uint32_t i = 0 ; i < suite_count; i++ )
  {
    UnitTestDefinitions_TestSuite_t *suite = suites[i];
    total_test_case_count += suite->test_case_count;
    total_skipped_count += suite->skipped_count;
    total_failure_count += suite->failure_count;
    total_error_count += suite->error_count;
  }
  
  /* 
   * Print test execution summary to stdout
   */
  printf("\nTest execution completed.\n");
  if (total_failure_count > 0 || total_error_count > 0) 
  {
    printf("!!! FAILURE !!! %d of %d test(s) failed, %d test(s) terminated with errors, %d test(s) skipped.\n", total_failure_count, total_test_case_count, total_error_count, total_skipped_count);
  }
  else
  {
    printf("SUCCESS: %d of %d test(s) passed, %d test(s) skipped.\n", total_test_case_count - total_skipped_count, total_test_case_count, total_skipped_count);
  }
  
  char abs_test_results_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
  UnitTestRunner_get_test_results_path(abs_test_results_path, sizeof(abs_test_results_path), true);
  printf("Detailed test results are available in:\n\t%s\n", UnitTestUtil_normalizePath(abs_test_results_path));
  return (total_failure_count == 0 && total_error_count == 0) ? (EXIT_SUCCESS) : (EXIT_FAILURE);
}

void UnitTestRunner_cleanup_system_resources(void)
{
  #if defined(_WIN32)
  WSACleanup();
  #else /* defined(_WIN32) */
  #endif /* defined(_WIN32) */

}
