#ifndef UNITTESTMESSAGES_H
#define UNITTESTMESSAGES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void UnitTestMessages____testing_runningTestCase(char *name, char *loc);

void UnitTestMessages____testing_FAILURE(uint8_t assertId, char *loc);

void UnitTestMessages____testing_FAILURE_INT(uint8_t assertId, int64_t act, char *loc);

void UnitTestMessages____testing_FAILURE_INT_STR(uint8_t assertId, int64_t act, char *exp, char *loc);

void UnitTestMessages____testing_FAILURE_INT_INT(uint8_t assertId, int64_t act, char *op, int64_t exp, char *loc);

void UnitTestMessages____testing_FAILURE_INT_DOUBLE(uint8_t assertId, int64_t act, char *op, double exp, char *loc);

void UnitTestMessages____testing_FAILURE_DOUBLE(uint8_t assertId, double act, char *loc);

void UnitTestMessages____testing_FAILURE_DOUBLE_STR(uint8_t assertId, double act, char *exp, char *loc);

void UnitTestMessages____testing_FAILURE_DOUBLE_DOUBLE(uint8_t assertId, double act, char *op, double exp, char *loc);

void UnitTestMessages____testing_FAILURE_DOUBLE_INT(uint8_t assertId, double act, char *op, int64_t exp, char *loc);

void UnitTestMessages____testing_FAILURE_BOOL_BOOL(uint8_t assertId, bool act, char *op, bool exp, char *loc);

void UnitTestMessages____testing_FAILURE_RANGE(uint8_t assertId, double act, char *op, double val1, double val2, char *loc);

void UnitTestMessages____testing_FAILURE_PTR_STR(uint8_t assertId, void const *act, char *op, char *exp, char *loc);

void UnitTestMessages____testing_FAILURE_PTR_PTR(uint8_t assertId, void const *act, char *op, void const *exp, char *loc);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
