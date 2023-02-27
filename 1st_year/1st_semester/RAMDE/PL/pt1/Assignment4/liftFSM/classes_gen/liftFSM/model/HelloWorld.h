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

int32_t HelloWorld_testMain(void);

int32_t HelloWorld_testMovingUP(void);

int32_t HelloWorld_testMovingDOWN(void);

int32_t HelloWorld_testEmergencyMovingUP(void);

int32_t HelloWorld_testEmergencyMovingDOWN(void);

int32_t HelloWorld_testEmergencyRelease(void);

int32_t HelloWorld_testEmergencyOpenDoors(void);

int32_t HelloWorld_testEmergencyCloseDoors(void);

int32_t HelloWorld_testEmergencyPrepare(void);

int32_t HelloWorld_testEmergencyStandBy(void);

int32_t HelloWorld_testWeightError(void);

int32_t HelloWorld_testClosingDoor(void);

int32_t HelloWorld_main(int32_t argc, char *argv[]);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
