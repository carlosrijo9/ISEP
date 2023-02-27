#include "UnitTestJUnitXML.h"

#if defined(_WIN32)
#include <io.h>
#else
#include <unistd.h>
#endif
#include "UnitTestUtil.h"
#include <stdlib.h>
#include <string.h>

FILE *UnitTestJUnitXML_begin_test_suite_result_file(char *suite_result_path, UnitTestDefinitions_TestSuite_t *suite, char *timestamp, char *host_name)
{
  FILE *suite_result_file = fopen(suite_result_path, "w");
  if (suite_result_file == NULL) 
  {
    printf("%s: Failed to create '%s' file for writing!\n", UnitTestDefinitions_IO_ERROR, suite_result_path);
    return NULL;
  }
  fprintf(suite_result_file, "<\?xml version=\"1.0\" encoding=\"UTF-8\"\?>");
  fprintf(suite_result_file, "\n");
  fprintf(suite_result_file, "<testsuite name=\"%s.%s::%s\" tests=\"%d\" skipped=\"%d\" failures=\"%%d\" errors=\"%%d\" timestamp=\"%s\" hostname=\"%s\">", suite->model_name, suite->module_name, suite->name, suite->test_case_count, suite->skipped_count, timestamp, host_name);
  fprintf(suite_result_file, "\n");
  fprintf(suite_result_file, "<properties />");
  fprintf(suite_result_file, "\n");
  return suite_result_file;
}

FILE *UnitTestJUnitXML_resume_test_suite_result_file(char *suite_result_path, UnitTestDefinitions_TestSuite_t *suite)
{
  FILE *suite_result_file = fopen(suite_result_path, "a");
  if (suite_result_file == NULL) 
  {
    printf("%s: Failed to open '%s' file for appending!\n", UnitTestDefinitions_IO_ERROR, suite_result_path);
    return NULL;
  }
  return suite_result_file;
}

void UnitTestJUnitXML_begin_test_case_result(FILE *suite_result_file, UnitTestDefinitions_TestCase_t *caze)
{
  fprintf(suite_result_file, "<testcase name=\"%s\" classname=\"%s\" modelId=\"%s\" nodeId=\"%s\">", caze->name, caze->class_name, caze->model_id, caze->node_id);
  fprintf(suite_result_file, "\n");
}

void UnitTestJUnitXML_append_failure_info(FILE *suite_result_file, char const *message, char const *type, char const *model_id, char const *node_id)
{
  fprintf(suite_result_file, "<failure message=\"%s\" type=\"%s failure\" modelId=\"%s\" nodeId=\"%s\">%s</failure>", message, type, model_id, node_id, "");
  fprintf(suite_result_file, "\n");
}

void UnitTestJUnitXML_append_error_info(FILE *suite_result_file, char const *message, char const *type)
{
  fprintf(suite_result_file, "<error message=\"%s\" type=\"%s\">%s</error>", message, type, "");
  fprintf(suite_result_file, "\n");
}

void UnitTestJUnitXML_append_default_error_info(FILE *suite_result_file, char *test_case_name)
{
  char message[UnitTestDefinitions_MAX_TEST_ERROR_MESSAGE_LENGTH + 1] = "";
  snprintf(message, sizeof(message), "error: %s has been terminated due to an unexpected fatal error", test_case_name);
  UnitTestJUnitXML_append_error_info(suite_result_file, message, "error");
}

void UnitTestJUnitXML_append_skipped_info(FILE *suite_result_file)
{
  fprintf(suite_result_file, "<skipped />");
  fprintf(suite_result_file, "\n");
}

bool UnitTestJUnitXML_append_std_stream_capture(FILE *suite_result_file, UnitTestDefinitions_TestCase_t *caze, char *std_stream_capture_path, FILE *std_stream)
{
  if (access(std_stream_capture_path, F_OK) == -1) 
  {
    /* 
     * No stdout/stderr capture file - nothing to do
     */
    return true;
  }
  
  char *std_stream_postfix = (std_stream == stdout) ? (UnitTestDefinitions_STDOUT_POSTFIX) : (UnitTestDefinitions_STDERR_POSTFIX);
  fprintf(suite_result_file, "<system-%s><![CDATA[", std_stream_postfix);
  fprintf(suite_result_file, "\n");
  
  /* 
   * Open stdout/stderr capture file
   */
  FILE *std_stream_capture_file = fopen(std_stream_capture_path, "r");
  if (std_stream_capture_file == NULL) 
  {
    printf("%s: Failed to open '%s' file for reading!\n", UnitTestDefinitions_IO_ERROR, std_stream_capture_path);
    return false;
  }
  
  /* 
   * Copy captured stdout/stderr content to both the JUnit XML result file and stdout/stderr itself
   */
  uint8_t buf[256] = { 0 };
  size_t n;
  while ((n = fread(buf, 1, sizeof(buf), std_stream_capture_file)) > 0)
  {
    for ( int64_t __i = 0 ; __i < n; __i++ )
    {
      /* 
       * Printable UTF8 character?
       */
      uint8_t ch = buf[__i];
      if (UnitTestUtil_isPrintableUTF8Char(ch)) 
      {
        /* 
         * Write character as is
         */
        fwrite(&ch, 1, 1, suite_result_file);
        fwrite(&ch, 1, 1, std_stream);
      }
      else
      {
        /* 
         * Write printable character representation
         */
        fprintf(suite_result_file, "{%02X}", ch);
        fprintf(std_stream, "{%02X}", ch);
      }
    }
  }
  
  /* 
   * Close stdout/stderr capture file
   */
  fclose(std_stream_capture_file);
  /* 
   * !! Important Note !! Do not delete stdout/stderr capture file because it slows down the test execution by up to 20%.
   */
  
  fprintf(suite_result_file, "]]></system-%s>", std_stream_postfix);
  fprintf(suite_result_file, "\n");
  return true;
}

void UnitTestJUnitXML_end_test_case_result(FILE *suite_result_file)
{
  fprintf(suite_result_file, "</testcase>");
  fprintf(suite_result_file, "\n");
}

void UnitTestJUnitXML_suspend_test_suite_result_file(FILE *suite_result_file)
{
  fclose(suite_result_file);
}

void UnitTestJUnitXML_end_test_suite_result_file(FILE *suite_result_file)
{
  fprintf(suite_result_file, "</testsuite>");
  fprintf(suite_result_file, "\n");
  fclose(suite_result_file);
}

bool UnitTestJUnitXML_finalize_test_suite_result_file(char *suite_result_path, UnitTestDefinitions_TestSuite_t *suite)
{
  FILE *suite_result_file = fopen(suite_result_path, "r");
  if (suite_result_file == NULL) 
  {
    printf("%s: Failed to open '%s' file for reading!\n", UnitTestDefinitions_IO_ERROR, suite_result_path);
    return false;
  }
  char temp_suite_result_path[UnitTestDefinitions_MAX_PATH_LENGTH + 1] = "";
  strncpy(temp_suite_result_path, suite_result_path, sizeof(temp_suite_result_path));
  size_t extension_offset = strlen(temp_suite_result_path) - 4;
  strncpy(temp_suite_result_path + extension_offset, ".tmp", sizeof(temp_suite_result_path) - extension_offset);
  FILE *temp_suite_result_file = fopen(temp_suite_result_path, "w");
  if (temp_suite_result_file == NULL) 
  {
    printf("%s: Failed to create '%s' file for writing!\n", UnitTestDefinitions_IO_ERROR, temp_suite_result_path);
    return false;
  }
  
  char buf[255 + 1] = "";
  uint32_t line = 0;
  while (feof(suite_result_file) == 0)
  {
    fgets(buf, ((int32_t)(sizeof(buf))), suite_result_file);
    if (feof(suite_result_file) == 0) 
    {
      line++;
      if (line == UnitTestJUnitXML_TEST_SUITE_BEGIN_TAG_LINE) 
      {
        fprintf(temp_suite_result_file, buf, suite->failure_count, suite->failure_count, suite->error_count);
      }
      else
      {
        fprintf(temp_suite_result_file, "%s", buf);
      }
    }
  }
  
  fclose(temp_suite_result_file);
  fclose(suite_result_file);
  
  remove(suite_result_path);
  rename(temp_suite_result_path, suite_result_path);
  return true;
}
