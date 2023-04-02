#ifndef UNITTESTJUNITXML_H
#define UNITTESTJUNITXML_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "UnitTestDefinitions.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UnitTestJUnitXML_TEST_SUITE_BEGIN_TAG_LINE 2

FILE *UnitTestJUnitXML_begin_test_suite_result_file(char *suite_result_path, UnitTestDefinitions_TestSuite_t *suite, char *timestamp, char *host_name);

FILE *UnitTestJUnitXML_resume_test_suite_result_file(char *suite_result_path, UnitTestDefinitions_TestSuite_t *suite);

void UnitTestJUnitXML_begin_test_case_result(FILE *suite_result_file, UnitTestDefinitions_TestCase_t *caze);

void UnitTestJUnitXML_append_failure_info(FILE *suite_result_file, char const *message, char const *type, char const *model_id, char const *node_id);

void UnitTestJUnitXML_append_error_info(FILE *suite_result_file, char const *message, char const *type);

void UnitTestJUnitXML_append_default_error_info(FILE *suite_result_file, char *test_case_name);

void UnitTestJUnitXML_append_skipped_info(FILE *suite_result_file);

bool UnitTestJUnitXML_append_std_stream_capture(FILE *suite_result_file, UnitTestDefinitions_TestCase_t *caze, char *std_stream_capture_path, FILE *std_stream);

void UnitTestJUnitXML_end_test_case_result(FILE *suite_result_file);

void UnitTestJUnitXML_suspend_test_suite_result_file(FILE *suite_result_file);

void UnitTestJUnitXML_end_test_suite_result_file(FILE *suite_result_file);

bool UnitTestJUnitXML_finalize_test_suite_result_file(char *suite_result_path, UnitTestDefinitions_TestSuite_t *suite);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
