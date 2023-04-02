#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "UnitTestRunner.h"
#include "UnitTestMessages.h"
#include "UnitTestCLI.h"

#ifdef __cplusplus
extern "C" {
#endif

int32_t HelloWorld_testA(void);

int32_t HelloWorld_main(int32_t argc, char *argv[]);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
