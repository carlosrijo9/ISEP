#ifndef UNITTESTRUNNER_H
#define UNITTESTRUNNER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "UnitTestDefinitions.h"
#include "UnitTestUtil.h"

#ifdef __cplusplus
extern "C" {
#endif

void UnitTestRunner_init_test_campaign(UnitTestDefinitions_TestSuite_t *suites[], uint32_t suiteCount);

void UnitTestRunner_run_test_campaign(UnitTestDefinitions_TestSuite_t *suites[], uint32_t suite_count);

int32_t UnitTestRunner_init_test_suite_and_run_test_case(UnitTestDefinitions_TestSuite_t *suite, UnitTestDefinitions_TestCase_t *caze);

void UnitTestRunner_log_assert_fail_int_int(char const *messageFormat, char const *assertType, uint8_t assertId, int64_t expected, int64_t actual, char const *modelId, char const *nodeId);

void UnitTestRunner_log_assert_fail_double_int(char const *messageFormat, char const *assertType, uint8_t assertId, double expected, int64_t actual, char const *modelId, char const *nodeId);

void UnitTestRunner_log_assert_fail_range_int(char const *messageFormat, char const *assertType, uint8_t assertId, char const *expected, int64_t actual, char const *modelId, char const *nodeId);

void UnitTestRunner_log_assert_fail_double_double(char const *messageFormat, char const *assertType, uint8_t assertId, double expected, double actual, char const *modelId, char const *nodeId);

void UnitTestRunner_log_assert_fail_int_double(char const *messageFormat, char const *assertType, uint8_t assertId, int64_t expected, double actual, char const *modelId, char const *nodeId);

void UnitTestRunner_log_assert_fail_range_double(char const *messageFormat, char const *assertType, uint8_t assertId, char const *expected, double actual, char const *modelId, char const *nodeId);

void UnitTestRunner_log_assert_fail_bool_bool(char const *messageFormat, char const *assertType, uint8_t assertId, bool expected, bool actual, char const *modelId, char const *nodeId);

void UnitTestRunner_log_assert_fail_ptr_ptr(char const *messageFormat, char const *assertType, uint8_t assertId, void const *expected, void const *actual, char const *modelId, char const *nodeId);

void UnitTestRunner_log_assert_fail_range_ptr(char const *messageFormat, char const *assertType, uint8_t assertId, char const *expected, void const *actual, char const *modelId, char const *nodeId);

int32_t UnitTestRunner_finalize_test_campaign(UnitTestDefinitions_TestSuite_t *suites[], uint32_t suite_count);

void UnitTestRunner_cleanup_system_resources(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
