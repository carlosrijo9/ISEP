#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "UnitTestRunner.h"
#include "UnitTestMessages.h"

#ifdef __cplusplus
extern "C" {
#endif

struct StateMachine_callLiftInterface__idata {
  void *__instance;
  void ((*(targetFloorCall))(void *));
};
typedef struct StateMachine_callLiftInterface__idata StateMachine_callLiftInterface__idata_t;

struct StateMachine_liftInterface__idata {
  void *__instance;
  void ((*(targetFloorUp))(void *));
  void ((*(targetFloorDown))(void *));
  void ((*(maxWeightTrigger))(void *));
  void ((*(detectionBarrierTrigger))(void *));
  void ((*(doorEOLTrigger))(void *));
  void ((*(emergencyTrigger))(void *));
  void ((*(emergencyReleaseTrigger))(void *));
  void ((*(inTargetFloorTrigger))(void *));
  void ((*(openDoorButtonTrigger))(void *));
  void ((*(closeDoorButtonTrigger))(void *));
  void ((*(targetFloorCallOkTrigger))(void *));
};
typedef struct StateMachine_liftInterface__idata StateMachine_liftInterface__idata_t;

struct StateMachine_TimeOuts__idata {
  void *__instance;
  void ((*(timeOutReleaseTrigger))(void *));
  void ((*(timeoutOpenDoorsTrigger))(void *));
  void ((*(timeoutNoActionLTrigger))(void *));
};
typedef struct StateMachine_TimeOuts__idata StateMachine_TimeOuts__idata_t;

struct StateMachine_MotorUp__idata {
  void *__instance;
  void ((*(on))(void *));
  void ((*(off))(void *));
};
typedef struct StateMachine_MotorUp__idata StateMachine_MotorUp__idata_t;

struct StateMachine_MotorDown__idata {
  void *__instance;
  void ((*(on))(void *));
  void ((*(off))(void *));
};
typedef struct StateMachine_MotorDown__idata StateMachine_MotorDown__idata_t;

struct StateMachine_MotorOpen__idata {
  void *__instance;
  void ((*(on))(void *));
  void ((*(off))(void *));
};
typedef struct StateMachine_MotorOpen__idata StateMachine_MotorOpen__idata_t;

struct StateMachine_MotorClose__idata {
  void *__instance;
  void ((*(on))(void *));
  void ((*(off))(void *));
};
typedef struct StateMachine_MotorClose__idata StateMachine_MotorClose__idata_t;

struct StateMachine_EmergencyAlarm__idata {
  void *__instance;
  void ((*(on))(void *));
  void ((*(off))(void *));
  void ((*(callEmergencyTeam))(void *));
};
typedef struct StateMachine_EmergencyAlarm__idata StateMachine_EmergencyAlarm__idata_t;

struct StateMachine_MaxWeightAlarm__idata {
  void *__instance;
  void ((*(on))(void *));
  void ((*(off))(void *));
};
typedef struct StateMachine_MaxWeightAlarm__idata StateMachine_MaxWeightAlarm__idata_t;

struct StateMachine_ambientLightsInterface__idata {
  void *__instance;
  void ((*(on))(void *));
  void ((*(off))(void *));
};
typedef struct StateMachine_ambientLightsInterface__idata StateMachine_ambientLightsInterface__idata_t;

enum StateMachine_liftFSM__states {
  StateMachine_liftFSM__states__liftFSM___initializing__state = -2,
  StateMachine_liftFSM__states__liftFSM_standby__state = 0,
  StateMachine_liftFSM__states__liftFSM_prepare__state,
  StateMachine_liftFSM__states__liftFSM_moveUP__state,
  StateMachine_liftFSM__states__liftFSM_moveDown__state,
  StateMachine_liftFSM__states__liftFSM_release__state,
  StateMachine_liftFSM__states__liftFSM_openDoor__state,
  StateMachine_liftFSM__states__liftFSM_closeDoor__state,
  StateMachine_liftFSM__states__liftFSM_emergency__state
};
typedef enum StateMachine_liftFSM__states StateMachine_liftFSM__states_t;

struct StateMachine_liftFSM__data {
  StateMachine_liftFSM__states_t __currentState;
};
typedef struct StateMachine_liftFSM__data StateMachine_liftFSM__data_t;

struct StateMachine_liftControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
};
typedef struct StateMachine_liftControl__cdata StateMachine_liftControl__cdata_t;

struct StateMachine_callLiftControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
  /* 
   * Req port ops
   */
  StateMachine_liftInterface__idata_t *liftInterface__ops;
};
typedef struct StateMachine_callLiftControl__cdata StateMachine_callLiftControl__cdata_t;

struct StateMachine_timeOutControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
  /* 
   * Req port ops
   */
  StateMachine_liftInterface__idata_t *liftInterface__ops;
};
typedef struct StateMachine_timeOutControl__cdata StateMachine_timeOutControl__cdata_t;

struct StateMachine_motorUpControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
  /* 
   * Req port ops
   */
  StateMachine_liftInterface__idata_t *liftInterface__ops;
};
typedef struct StateMachine_motorUpControl__cdata StateMachine_motorUpControl__cdata_t;

struct StateMachine_motorDownControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
  /* 
   * Req port ops
   */
  StateMachine_liftInterface__idata_t *liftInterface__ops;
};
typedef struct StateMachine_motorDownControl__cdata StateMachine_motorDownControl__cdata_t;

struct StateMachine_motorOpenControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
  /* 
   * Req port ops
   */
  StateMachine_liftInterface__idata_t *liftInterface__ops;
};
typedef struct StateMachine_motorOpenControl__cdata StateMachine_motorOpenControl__cdata_t;

struct StateMachine_motorCloseControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
  /* 
   * Req port ops
   */
  StateMachine_liftInterface__idata_t *liftInterface__ops;
};
typedef struct StateMachine_motorCloseControl__cdata StateMachine_motorCloseControl__cdata_t;

struct StateMachine_emergencyAlarmControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
  /* 
   * Req port ops
   */
  StateMachine_liftInterface__idata_t *liftInterface__ops;
};
typedef struct StateMachine_emergencyAlarmControl__cdata StateMachine_emergencyAlarmControl__cdata_t;

struct StateMachine_MaxWeightAlarmControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
  /* 
   * Req port ops
   */
  StateMachine_liftInterface__idata_t *liftInterface__ops;
};
typedef struct StateMachine_MaxWeightAlarmControl__cdata StateMachine_MaxWeightAlarmControl__cdata_t;

struct StateMachine_ambientlightControl__cdata {
  /* 
   * fields
   */
  StateMachine_liftFSM__data_t theLiftFSM__field;
  /* 
   * Req port ops
   */
  StateMachine_liftInterface__idata_t *liftInterface__ops;
};
typedef struct StateMachine_ambientlightControl__cdata StateMachine_ambientlightControl__cdata_t;

enum StateMachine_liftFSM__inevents {
  StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event,
  StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event,
  StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event,
  StateMachine_liftFSM__inevents__liftFSM_weightMaxNOK_trigger__event,
  StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event,
  StateMachine_liftFSM__inevents__liftFSM_detectionBarrier_trigger__event,
  StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event,
  StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event,
  StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event,
  StateMachine_liftFSM__inevents__liftFSM_timeoutNoAction__event,
  StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event,
  StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event,
  StateMachine_liftFSM__inevents__liftFSM_openDoorButton_pressed__event,
  StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event,
  StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event
};
typedef enum StateMachine_liftFSM__inevents StateMachine_liftFSM__inevents_t;

void StateMachine_liftFSM__init(StateMachine_liftFSM__data_t *instance, bool postponeInitialExecution);

bool StateMachine_liftFSM__execute(StateMachine_liftFSM__data_t *instance, StateMachine_liftFSM__inevents_t event, void **arguments);

int32_t StateMachine_testComp(void);

void StateMachine_liftControl_main(void *___id);

void StateMachine_liftControl_liftInterface_targetFloorUp(void *___id);

void StateMachine_liftControl_liftInterface_targetFloorDown(void *___id);

void StateMachine_liftControl_liftInterface_emergencyTrigger(void *___id);

void StateMachine_liftControl_liftInterface_maxWeightTrigger(void *___id);

void StateMachine_liftControl_liftInterface_detectionBarrierTrigger(void *___id);

void StateMachine_liftControl_liftInterface_doorEOLTrigger(void *___id);

void StateMachine_liftControl_liftInterface_inTargetFloorTrigger(void *___id);

void StateMachine_liftControl_liftInterface_emergencyReleaseTrigger(void *___id);

void StateMachine_liftControl_liftInterface_openDoorButtonTrigger(void *___id);

void StateMachine_liftControl_liftInterface_closeDoorButtonTrigger(void *___id);

void StateMachine_liftControl_liftInterface_targetFloorCallOkTrigger(void *___id);

void StateMachine_callLiftControl_main(void *___id);

void StateMachine_callLiftControl_callLiftInterface_targetFloorCall(void *___id);

void StateMachine_timeOutControl_main(void *___id);

void StateMachine_timeOutControl_TimeOutInterface_timeOutReleaseTrigger(void *___id);

void StateMachine_timeOutControl_TimeOutInterface_timeoutNoActionLTrigger(void *___id);

void StateMachine_timeOutControl_TimeOutInterface_timeoutOpenDoorsTrigger(void *___id);

void StateMachine_motorUpControl_MotorUp_on(void *___id);

void StateMachine_motorUpControl_MotorUp_off(void *___id);

void StateMachine_motorDownControl_MotorDown_on(void *___id);

void StateMachine_motorDownControl_MotorDown_off(void *___id);

void StateMachine_motorOpenControl_MotorOpen_on(void *___id);

void StateMachine_motorOpenControl_MotorOpen_off(void *___id);

void StateMachine_motorCloseControl_MotorClose_on(void *___id);

void StateMachine_motorCloseControl_MotorClose_off(void *___id);

void StateMachine_emergencyAlarmControl_emergencyAlarm_on(void *___id);

void StateMachine_emergencyAlarmControl_emergencyAlarm_off(void *___id);

void StateMachine_emergencyAlarmControl_emergencyAlarm_callEmergencyTeam(void *___id);

void StateMachine_MaxWeightAlarmControl_MaxWeightAlarm_on(void *___id);

void StateMachine_MaxWeightAlarmControl_MaxWeightAlarm_off(void *___id);

void StateMachine_ambientlightControl_ambientLightsInterface_on(void *___id);

void StateMachine_ambientlightControl_ambientLightsInterface_off(void *___id);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
