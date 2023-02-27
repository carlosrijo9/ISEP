#include "StateMachine.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static inline void StateMachine_SystemInstance_liftControl__wire(void);

static inline void StateMachine_SystemInstance_callLiftControl__wire(void);

static inline void StateMachine_SystemInstance_timeOutControl__wire(void);

static inline void StateMachine_SystemInstance_motorCloseControl__wire(void);

static inline void StateMachine_SystemInstance_motorDownControl__wire(void);

static inline void StateMachine_SystemInstance_motorOpenControl__wire(void);

static inline void StateMachine_SystemInstance_motorUpControl__wire(void);

static inline void StateMachine_SystemInstance_emergencyAlarmControl__wire(void);

static inline void StateMachine_SystemInstance_maxWeightAlarmControl__wire(void);

static inline void StateMachine_SystemInstance_ambientlightControl__wire(void);

static void StateMachine_SystemInstance__init(void);

static void StateMachine_doCallLiftTrigger(void);

static void StateMachine_doEmergencyTrigger(void);

static void StateMachine_doEmergencyReleaseTrigger(void);

static void StateMachine_doMaxWeightTrigger(void);

static void StateMachine_doDetectionBarrierTrigger(void);

static void StateMachine_doDoorEOLTrigger(void);

static void StateMachine_doTargetFloorUpTrigger(void);

static void StateMachine_doTargetFloorDownTrigger(void);

static void StateMachine_doInTargetFloorTrigger(void);

static void StateMachine_doOpenDoorButtonTrigger(void);

static void StateMachine_doCloseDoorButtonTrigger(void);

static void StateMachine_dotargetFloorCallOkTrigger(void);

static void StateMachine_doTimeOutReleaseTrigger(void);

static void StateMachine_doTimeoutNoActionLTrigger(void);

static void StateMachine_doTimeoutOpenDoorsTrigger(void);

static void StateMachine_doCallEmergencyTeam(void);

static void StateMachine_doMotorUpOn(void);

static void StateMachine_doMotorUpOff(void);

static void StateMachine_doMotorDownOn(void);

static void StateMachine_doMotorDownOff(void);

static void StateMachine_doMotorOpenOn(void);

static void StateMachine_doMotorOpenOff(void);

static void StateMachine_doMotorCloseOn(void);

static void StateMachine_doMotorCloseOff(void);

static void StateMachine_doEmergencyAlarmOn(void);

static void StateMachine_doEmergencyAlarmOff(void);

static void StateMachine_doMaxWeightAlarmOn(void);

static void StateMachine_doMaxWeightAlarmOff(void);

static void StateMachine_doAmbientLightOn(void);

static void StateMachine_doAmbientLightOff(void);

static inline void StateMachine_liftFSM_standby_EntryAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_prepare_EntryAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_moveUP_EntryAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_moveUP_ExitAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_moveDown_EntryAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_moveDown_ExitAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_release_EntryAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_openDoor_EntryAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_openDoor_ExitAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_closeDoor_EntryAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_closeDoor_ExitAction(StateMachine_liftFSM__data_t *instance);

static inline void StateMachine_liftFSM_emergency_EntryAction(StateMachine_liftFSM__data_t *instance);

static bool StateMachine_ambientLights;

static bool StateMachine_inTargetFloor;

static bool StateMachine_motorOpen;

static bool StateMachine_motorClose;

static bool StateMachine_weightAlarm;

static bool StateMachine_emergencyAlarm;

static bool StateMachine_callSecurityTeam;

static char *StateMachine_movementDisplay;

static bool StateMachine_motorUp;

static bool StateMachine_motorDown;

static int8_t StateMachine_motorUpSpeed;

static int8_t StateMachine_motorDownSpeed;

static char *StateMachine_doorStatus;

/* 
 * comp instance data
 */
static StateMachine_liftControl__cdata_t StateMachine_SystemInstance_liftControl__instance = { 0 };

static StateMachine_liftInterface__idata_t StateMachine_SystemInstance_liftControl_liftInterface__ops = { 0 };

/* 
 * comp instance data
 */
static StateMachine_callLiftControl__cdata_t StateMachine_SystemInstance_callLiftControl__instance = { 0 };

static StateMachine_callLiftInterface__idata_t StateMachine_SystemInstance_callLiftControl_callLiftInterface__ops = { 0 };

/* 
 * comp instance data
 */
static StateMachine_timeOutControl__cdata_t StateMachine_SystemInstance_timeOutControl__instance = { 0 };

static StateMachine_TimeOuts__idata_t StateMachine_SystemInstance_timeOutControl_TimeOutInterface__ops = { 0 };

/* 
 * comp instance data
 */
static StateMachine_motorCloseControl__cdata_t StateMachine_SystemInstance_motorCloseControl__instance = { 0 };

static StateMachine_MotorClose__idata_t StateMachine_SystemInstance_motorCloseControl_MotorClose__ops = { 0 };

/* 
 * comp instance data
 */
static StateMachine_motorDownControl__cdata_t StateMachine_SystemInstance_motorDownControl__instance = { 0 };

static StateMachine_MotorDown__idata_t StateMachine_SystemInstance_motorDownControl_MotorDown__ops = { 0 };

/* 
 * comp instance data
 */
static StateMachine_motorOpenControl__cdata_t StateMachine_SystemInstance_motorOpenControl__instance = { 0 };

static StateMachine_MotorOpen__idata_t StateMachine_SystemInstance_motorOpenControl_MotorOpen__ops = { 0 };

/* 
 * comp instance data
 */
static StateMachine_motorUpControl__cdata_t StateMachine_SystemInstance_motorUpControl__instance = { 0 };

static StateMachine_MotorUp__idata_t StateMachine_SystemInstance_motorUpControl_MotorUp__ops = { 0 };

/* 
 * comp instance data
 */
static StateMachine_emergencyAlarmControl__cdata_t StateMachine_SystemInstance_emergencyAlarmControl__instance = { 0 };

static StateMachine_EmergencyAlarm__idata_t StateMachine_SystemInstance_emergencyAlarmControl_emergencyAlarm__ops = { 0 };

/* 
 * comp instance data
 */
static StateMachine_MaxWeightAlarmControl__cdata_t StateMachine_SystemInstance_maxWeightAlarmControl__instance = { 0 };

static StateMachine_MaxWeightAlarm__idata_t StateMachine_SystemInstance_maxWeightAlarmControl_MaxWeightAlarm__ops = { 0 };

/* 
 * comp instance data
 */
static StateMachine_ambientlightControl__cdata_t StateMachine_SystemInstance_ambientlightControl__instance = { 0 };

static StateMachine_ambientLightsInterface__idata_t StateMachine_SystemInstance_ambientlightControl_ambientLightsInterface__ops = { 0 };

void StateMachine_liftFSM__init(StateMachine_liftFSM__data_t *instance, bool postponeInitialExecution)
{
  if (!postponeInitialExecution) 
  {
    instance->__currentState = StateMachine_liftFSM__states__liftFSM_standby__state;
    StateMachine_liftFSM_standby_EntryAction(instance);
  }
  else
  {
    instance->__currentState = StateMachine_liftFSM__states__liftFSM___initializing__state;
  }
}

bool StateMachine_liftFSM__execute(StateMachine_liftFSM__data_t *instance, StateMachine_liftFSM__inevents_t event, void **arguments)
{
  bool __outstandingEvent;
  do {
    __outstandingEvent = false;
    switch (instance->__currentState)
    {
      case StateMachine_liftFSM__states__liftFSM___initializing__state:
      {
        /* 
         * enter initial state
         */
        instance->__currentState = StateMachine_liftFSM__states__liftFSM_standby__state;
        StateMachine_liftFSM_standby_EntryAction(instance);
        __outstandingEvent = true;
        break;
      }
      case StateMachine_liftFSM__states__liftFSM_standby__state:
      {
        switch (event)
        {
          case StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081264797:

              (void)0;
              StateMachine_doAmbientLightOn();
              printf("Waking up...");
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_prepare__state;
            StateMachine_liftFSM_prepare_EntryAction(instance);
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266186:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_emergency__state;
            StateMachine_liftFSM_emergency_EntryAction(instance);
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_liftFSM__states__liftFSM_prepare__state:
      {
        switch (event)
        {
          case StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266221:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_emergency__state;
            StateMachine_liftFSM_emergency_EntryAction(instance);
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266486:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_moveUP__state;
            StateMachine_liftFSM_moveUP_EntryAction(instance);
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266515:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_moveDown__state;
            StateMachine_liftFSM_moveDown_EntryAction(instance);
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266614:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_openDoor__state;
            StateMachine_liftFSM_openDoor_EntryAction(instance);
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_timeoutNoAction__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266648:

              (void)0;
              StateMachine_doAmbientLightOff();
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_standby__state;
            StateMachine_liftFSM_standby_EntryAction(instance);
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_liftFSM__states__liftFSM_moveUP__state:
      {
        switch (event)
        {
          case StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_moveUP_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266676:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_emergency__state;
              StateMachine_liftFSM_emergency_EntryAction(instance);
            }
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_moveUP_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266746:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_release__state;
              StateMachine_liftFSM_release_EntryAction(instance);
            }
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_liftFSM__states__liftFSM_moveDown__state:
      {
        switch (event)
        {
          case StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_moveDown_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266686:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_moveDown__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_emergency__state;
              StateMachine_liftFSM_emergency_EntryAction(instance);
            }
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_moveDown_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266769:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_moveDown__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_release__state;
              StateMachine_liftFSM_release_EntryAction(instance);
            }
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_liftFSM__states__liftFSM_release__state:
      {
        switch (event)
        {
          case StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266696:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_emergency__state;
            StateMachine_liftFSM_emergency_EntryAction(instance);
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266799:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_openDoor__state;
            StateMachine_liftFSM_openDoor_EntryAction(instance);
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_liftFSM__states__liftFSM_openDoor__state:
      {
        switch (event)
        {
          case StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_openDoor_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_8732702970037503408:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_closeDoor__state;
              StateMachine_liftFSM_closeDoor_EntryAction(instance);
            }
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_openDoor_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266706:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_emergency__state;
              StateMachine_liftFSM_emergency_EntryAction(instance);
            }
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_openDoor_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266814:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_closeDoor__state;
              StateMachine_liftFSM_closeDoor_EntryAction(instance);
            }
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_weightMaxNOK_trigger__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_openDoor_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266205:

              (void)0;
              StateMachine_doMaxWeightAlarmOn();
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) 
            {
              /* 
               * enter target state
               */
              StateMachine_liftFSM_openDoor_EntryAction(instance);
            }
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_liftFSM__states__liftFSM_closeDoor__state:
      {
        switch (event)
        {
          case StateMachine_liftFSM__inevents__liftFSM_detectionBarrier_trigger__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_closeDoor_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266828:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_openDoor__state;
              StateMachine_liftFSM_openDoor_EntryAction(instance);
            }
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_closeDoor_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266848:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_prepare__state;
              StateMachine_liftFSM_prepare_EntryAction(instance);
            }
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_closeDoor_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266716:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_emergency__state;
              StateMachine_liftFSM_emergency_EntryAction(instance);
            }
            break;
          }
          case StateMachine_liftFSM__inevents__liftFSM_openDoorButton_pressed__event:
          {
            /* 
             * exit current state
             */
            StateMachine_liftFSM_closeDoor_ExitAction(instance);
            
            /* 
             * transition actions
             */
            {
              label_transition_fireable_8732702970037504072:

              (void)0;
            }

            
            if (instance->__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_liftFSM__states__liftFSM_openDoor__state;
              StateMachine_liftFSM_openDoor_EntryAction(instance);
            }
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_liftFSM__states__liftFSM_emergency__state:
      {
        switch (event)
        {
          case StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_5831586151081266883:

              (void)0;
              StateMachine_doAmbientLightOff();
              StateMachine_doEmergencyAlarmOff();
              StateMachine_doEmergencyAlarmOff();
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = StateMachine_liftFSM__states__liftFSM_standby__state;
            StateMachine_liftFSM_standby_EntryAction(instance);
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      default: {
        break;
      }
    }
  }
  while (__outstandingEvent);
  return true;
}

static inline void StateMachine_SystemInstance_liftControl__wire(void)
{
  /* 
   * INSTANCE: liftControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.targetFloorUp = &StateMachine_liftControl_liftInterface_targetFloorUp;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.targetFloorDown = &StateMachine_liftControl_liftInterface_targetFloorDown;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.maxWeightTrigger = &StateMachine_liftControl_liftInterface_maxWeightTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.detectionBarrierTrigger = &StateMachine_liftControl_liftInterface_detectionBarrierTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.doorEOLTrigger = &StateMachine_liftControl_liftInterface_doorEOLTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.emergencyTrigger = &StateMachine_liftControl_liftInterface_emergencyTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.emergencyReleaseTrigger = &StateMachine_liftControl_liftInterface_emergencyReleaseTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.inTargetFloorTrigger = &StateMachine_liftControl_liftInterface_inTargetFloorTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.openDoorButtonTrigger = &StateMachine_liftControl_liftInterface_openDoorButtonTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.closeDoorButtonTrigger = &StateMachine_liftControl_liftInterface_closeDoorButtonTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.targetFloorCallOkTrigger = &StateMachine_liftControl_liftInterface_targetFloorCallOkTrigger;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_liftControl_liftInterface__ops.__instance = &StateMachine_SystemInstance_liftControl__instance;
  
}

static inline void StateMachine_SystemInstance_callLiftControl__wire(void)
{
  /* 
   * INSTANCE: callLiftControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_callLiftControl_callLiftInterface__ops.targetFloorCall = &StateMachine_callLiftControl_callLiftInterface_targetFloorCall;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_callLiftControl_callLiftInterface__ops.__instance = &StateMachine_SystemInstance_callLiftControl__instance;
  /* 
   * required port ops
   */
  StateMachine_SystemInstance_callLiftControl__instance.liftInterface__ops = &StateMachine_SystemInstance_liftControl_liftInterface__ops;
  
}

static inline void StateMachine_SystemInstance_timeOutControl__wire(void)
{
  /* 
   * INSTANCE: timeOutControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_timeOutControl_TimeOutInterface__ops.timeOutReleaseTrigger = &StateMachine_timeOutControl_TimeOutInterface_timeOutReleaseTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_timeOutControl_TimeOutInterface__ops.timeoutOpenDoorsTrigger = &StateMachine_timeOutControl_TimeOutInterface_timeoutOpenDoorsTrigger;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_timeOutControl_TimeOutInterface__ops.timeoutNoActionLTrigger = &StateMachine_timeOutControl_TimeOutInterface_timeoutNoActionLTrigger;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_timeOutControl_TimeOutInterface__ops.__instance = &StateMachine_SystemInstance_timeOutControl__instance;
  /* 
   * required port ops
   */
  StateMachine_SystemInstance_timeOutControl__instance.liftInterface__ops = &StateMachine_SystemInstance_liftControl_liftInterface__ops;
  
}

static inline void StateMachine_SystemInstance_motorCloseControl__wire(void)
{
  /* 
   * INSTANCE: motorCloseControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_motorCloseControl_MotorClose__ops.on = &StateMachine_motorCloseControl_MotorClose_on;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_motorCloseControl_MotorClose__ops.off = &StateMachine_motorCloseControl_MotorClose_off;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_motorCloseControl_MotorClose__ops.__instance = &StateMachine_SystemInstance_motorCloseControl__instance;
  /* 
   * required port ops
   */
  StateMachine_SystemInstance_motorCloseControl__instance.liftInterface__ops = &StateMachine_SystemInstance_liftControl_liftInterface__ops;
  
}

static inline void StateMachine_SystemInstance_motorDownControl__wire(void)
{
  /* 
   * INSTANCE: motorDownControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_motorDownControl_MotorDown__ops.on = &StateMachine_motorDownControl_MotorDown_on;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_motorDownControl_MotorDown__ops.off = &StateMachine_motorDownControl_MotorDown_off;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_motorDownControl_MotorDown__ops.__instance = &StateMachine_SystemInstance_motorDownControl__instance;
  /* 
   * required port ops
   */
  StateMachine_SystemInstance_motorDownControl__instance.liftInterface__ops = &StateMachine_SystemInstance_liftControl_liftInterface__ops;
  
}

static inline void StateMachine_SystemInstance_motorOpenControl__wire(void)
{
  /* 
   * INSTANCE: motorOpenControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_motorOpenControl_MotorOpen__ops.on = &StateMachine_motorOpenControl_MotorOpen_on;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_motorOpenControl_MotorOpen__ops.off = &StateMachine_motorOpenControl_MotorOpen_off;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_motorOpenControl_MotorOpen__ops.__instance = &StateMachine_SystemInstance_motorOpenControl__instance;
  /* 
   * required port ops
   */
  StateMachine_SystemInstance_motorOpenControl__instance.liftInterface__ops = &StateMachine_SystemInstance_liftControl_liftInterface__ops;
  
}

static inline void StateMachine_SystemInstance_motorUpControl__wire(void)
{
  /* 
   * INSTANCE: motorUpControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_motorUpControl_MotorUp__ops.on = &StateMachine_motorUpControl_MotorUp_on;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_motorUpControl_MotorUp__ops.off = &StateMachine_motorUpControl_MotorUp_off;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_motorUpControl_MotorUp__ops.__instance = &StateMachine_SystemInstance_motorUpControl__instance;
  /* 
   * required port ops
   */
  StateMachine_SystemInstance_motorUpControl__instance.liftInterface__ops = &StateMachine_SystemInstance_liftControl_liftInterface__ops;
  
}

static inline void StateMachine_SystemInstance_emergencyAlarmControl__wire(void)
{
  /* 
   * INSTANCE: emergencyAlarmControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_emergencyAlarmControl_emergencyAlarm__ops.on = &StateMachine_emergencyAlarmControl_emergencyAlarm_on;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_emergencyAlarmControl_emergencyAlarm__ops.off = &StateMachine_emergencyAlarmControl_emergencyAlarm_off;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_emergencyAlarmControl_emergencyAlarm__ops.callEmergencyTeam = &StateMachine_emergencyAlarmControl_emergencyAlarm_callEmergencyTeam;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_emergencyAlarmControl_emergencyAlarm__ops.__instance = &StateMachine_SystemInstance_emergencyAlarmControl__instance;
  /* 
   * required port ops
   */
  StateMachine_SystemInstance_emergencyAlarmControl__instance.liftInterface__ops = &StateMachine_SystemInstance_liftControl_liftInterface__ops;
  
}

static inline void StateMachine_SystemInstance_maxWeightAlarmControl__wire(void)
{
  /* 
   * INSTANCE: maxWeightAlarmControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_maxWeightAlarmControl_MaxWeightAlarm__ops.on = &StateMachine_MaxWeightAlarmControl_MaxWeightAlarm_on;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_maxWeightAlarmControl_MaxWeightAlarm__ops.off = &StateMachine_MaxWeightAlarmControl_MaxWeightAlarm_off;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_maxWeightAlarmControl_MaxWeightAlarm__ops.__instance = &StateMachine_SystemInstance_maxWeightAlarmControl__instance;
  /* 
   * required port ops
   */
  StateMachine_SystemInstance_maxWeightAlarmControl__instance.liftInterface__ops = &StateMachine_SystemInstance_liftControl_liftInterface__ops;
  
}

static inline void StateMachine_SystemInstance_ambientlightControl__wire(void)
{
  /* 
   * INSTANCE: ambientlightControl
   */
  /* 
   * prov port
   */
  StateMachine_SystemInstance_ambientlightControl_ambientLightsInterface__ops.on = &StateMachine_ambientlightControl_ambientLightsInterface_on;
  /* 
   * prov port
   */
  StateMachine_SystemInstance_ambientlightControl_ambientLightsInterface__ops.off = &StateMachine_ambientlightControl_ambientLightsInterface_off;
  /* 
   * prov port owning instance
   */
  StateMachine_SystemInstance_ambientlightControl_ambientLightsInterface__ops.__instance = &StateMachine_SystemInstance_ambientlightControl__instance;
  /* 
   * required port ops
   */
  StateMachine_SystemInstance_ambientlightControl__instance.liftInterface__ops = &StateMachine_SystemInstance_liftControl_liftInterface__ops;
  
}

static void StateMachine_SystemInstance__init(void)
{
  StateMachine_SystemInstance_liftControl__wire();
  StateMachine_SystemInstance_callLiftControl__wire();
  StateMachine_SystemInstance_timeOutControl__wire();
  StateMachine_SystemInstance_motorCloseControl__wire();
  StateMachine_SystemInstance_motorDownControl__wire();
  StateMachine_SystemInstance_motorOpenControl__wire();
  StateMachine_SystemInstance_motorUpControl__wire();
  StateMachine_SystemInstance_emergencyAlarmControl__wire();
  StateMachine_SystemInstance_maxWeightAlarmControl__wire();
  StateMachine_SystemInstance_ambientlightControl__wire();
}

int32_t StateMachine_testComp(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testComp", "StateMachine:testComp?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#1085275269403442472");
  StateMachine_SystemInstance__init();
  StateMachine_callLiftControl_callLiftInterface_targetFloorCall(&StateMachine_SystemInstance_callLiftControl__instance);
  return ___failuresVal;
}

static void StateMachine_doCallLiftTrigger(void)
{
  StateMachine_callLiftControl_callLiftInterface_targetFloorCall(&StateMachine_SystemInstance_callLiftControl__instance);
}

static void StateMachine_doEmergencyTrigger(void)
{
  StateMachine_liftControl_liftInterface_emergencyTrigger(&StateMachine_SystemInstance_liftControl__instance);
  printf("Emergency Detected\n");
}

static void StateMachine_doEmergencyReleaseTrigger(void)
{
  StateMachine_liftControl_liftInterface_emergencyReleaseTrigger(&StateMachine_SystemInstance_liftControl__instance);
  printf("Emergency Resolved!\n");
}

static void StateMachine_doMaxWeightTrigger(void)
{
  StateMachine_liftControl_liftInterface_maxWeightTrigger(&StateMachine_SystemInstance_liftControl__instance);
}

static void StateMachine_doDetectionBarrierTrigger(void)
{
  StateMachine_liftControl_liftInterface_detectionBarrierTrigger(&StateMachine_SystemInstance_liftControl__instance);
  printf("Object Deteted.\n");
}

static void StateMachine_doDoorEOLTrigger(void)
{
  StateMachine_liftControl_liftInterface_doorEOLTrigger(&StateMachine_SystemInstance_liftControl__instance);
}

static void StateMachine_doTargetFloorUpTrigger(void)
{
  StateMachine_liftControl_liftInterface_targetFloorUp(&StateMachine_SystemInstance_liftControl__instance);
  printf("Current Floor is bellow Target Floor");
}

static void StateMachine_doTargetFloorDownTrigger(void)
{
  StateMachine_liftControl_liftInterface_targetFloorDown(&StateMachine_SystemInstance_liftControl__instance);
  printf("Current Floor is Above Target Floor");
}

static void StateMachine_doInTargetFloorTrigger(void)
{
  StateMachine_liftControl_liftInterface_inTargetFloorTrigger(&StateMachine_SystemInstance_liftControl__instance);
  printf("Arrived to target Floor\n");
}

static void StateMachine_doOpenDoorButtonTrigger(void)
{
  StateMachine_liftControl_liftInterface_openDoorButtonTrigger(&StateMachine_SystemInstance_liftControl__instance);
  printf("Open Door Button Pressed.\n");
  printf("Doors %s\n", StateMachine_doorStatus);
}

static void StateMachine_doCloseDoorButtonTrigger(void)
{
  StateMachine_liftControl_liftInterface_closeDoorButtonTrigger(&StateMachine_SystemInstance_liftControl__instance);
  printf("Close Door Button Pressed.\n");
  printf("Doors %s\n", StateMachine_doorStatus);
}

static void StateMachine_dotargetFloorCallOkTrigger(void)
{
  StateMachine_liftControl_liftInterface_targetFloorCallOkTrigger(&StateMachine_SystemInstance_liftControl__instance);
  printf("Current Floor is the same as Target Floor");
}

static void StateMachine_doTimeOutReleaseTrigger(void)
{
  StateMachine_timeOutControl_TimeOutInterface_timeOutReleaseTrigger(&StateMachine_SystemInstance_timeOutControl__instance);
}

static void StateMachine_doTimeoutNoActionLTrigger(void)
{
  StateMachine_timeOutControl_TimeOutInterface_timeoutNoActionLTrigger(&StateMachine_SystemInstance_timeOutControl__instance);
  printf("No Action detected\n");
}

static void StateMachine_doTimeoutOpenDoorsTrigger(void)
{
  StateMachine_timeOutControl_TimeOutInterface_timeoutOpenDoorsTrigger(&StateMachine_SystemInstance_timeOutControl__instance);
  printf("Doors %s\n", StateMachine_doorStatus);
}

static void StateMachine_doCallEmergencyTeam(void)
{
  StateMachine_emergencyAlarmControl_emergencyAlarm_callEmergencyTeam(&StateMachine_SystemInstance_emergencyAlarmControl__instance);
}

static void StateMachine_doMotorUpOn(void)
{
  StateMachine_motorUpControl_MotorUp_on(&StateMachine_SystemInstance_motorUpControl__instance);
  StateMachine_motorUp = true;
}

static void StateMachine_doMotorUpOff(void)
{
  StateMachine_motorUpControl_MotorUp_off(&StateMachine_SystemInstance_motorUpControl__instance);
  StateMachine_motorUp = false;
}

static void StateMachine_doMotorDownOn(void)
{
  StateMachine_motorDownControl_MotorDown_on(&StateMachine_SystemInstance_motorDownControl__instance);
  StateMachine_motorDown = true;
}

static void StateMachine_doMotorDownOff(void)
{
  StateMachine_motorDownControl_MotorDown_off(&StateMachine_SystemInstance_motorDownControl__instance);
  StateMachine_motorDown = false;
}

static void StateMachine_doMotorOpenOn(void)
{
  printf("Opening Doors...\n");
  StateMachine_motorOpenControl_MotorOpen_on(&StateMachine_SystemInstance_motorOpenControl__instance);
  StateMachine_motorOpen = true;
  printf("Doors %s\n", StateMachine_doorStatus);
}

static void StateMachine_doMotorOpenOff(void)
{
  StateMachine_motorOpenControl_MotorOpen_off(&StateMachine_SystemInstance_motorOpenControl__instance);
  StateMachine_motorOpen = false;
  printf("Doors %s\n", StateMachine_doorStatus);
}

static void StateMachine_doMotorCloseOn(void)
{
  printf("Closing Doors...\n");
  StateMachine_motorCloseControl_MotorClose_on(&StateMachine_SystemInstance_motorCloseControl__instance);
  StateMachine_motorClose = true;
  printf("Doors %s\n", StateMachine_doorStatus);
}

static void StateMachine_doMotorCloseOff(void)
{
  StateMachine_motorCloseControl_MotorClose_off(&StateMachine_SystemInstance_motorCloseControl__instance);
  StateMachine_motorClose = false;
  printf("Doors %s\n", StateMachine_doorStatus);
}

static void StateMachine_doEmergencyAlarmOn(void)
{
  StateMachine_emergencyAlarmControl_emergencyAlarm_on(&StateMachine_SystemInstance_emergencyAlarmControl__instance);
  StateMachine_emergencyAlarm = true;
}

static void StateMachine_doEmergencyAlarmOff(void)
{
  StateMachine_emergencyAlarmControl_emergencyAlarm_off(&StateMachine_SystemInstance_emergencyAlarmControl__instance);
  StateMachine_emergencyAlarm = false;
}

static void StateMachine_doMaxWeightAlarmOn(void)
{
  StateMachine_MaxWeightAlarmControl_MaxWeightAlarm_on(&StateMachine_SystemInstance_maxWeightAlarmControl__instance);
  StateMachine_weightAlarm = true;
  printf("Warning - Weight to high\n");
}

static void StateMachine_doMaxWeightAlarmOff(void)
{
  StateMachine_MaxWeightAlarmControl_MaxWeightAlarm_off(&StateMachine_SystemInstance_maxWeightAlarmControl__instance);
  StateMachine_weightAlarm = false;
}

static void StateMachine_doAmbientLightOn(void)
{
  StateMachine_ambientlightControl_ambientLightsInterface_on(&StateMachine_SystemInstance_ambientlightControl__instance);
  StateMachine_ambientLights = true;
  printf("Ambient Lights status: %s\n", (StateMachine_ambientLights) ? ("on") : ("off"));
}

static void StateMachine_doAmbientLightOff(void)
{
  StateMachine_ambientlightControl_ambientLightsInterface_off(&StateMachine_SystemInstance_ambientlightControl__instance);
  StateMachine_ambientLights = false;
  printf("Ambient Lights status: %s\n", (StateMachine_ambientLights) ? ("on") : ("off"));
}

void StateMachine_liftControl_main(void *___id)
{
}

void StateMachine_liftControl_liftInterface_targetFloorUp(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
}

void StateMachine_liftControl_liftInterface_targetFloorDown(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event, NULL);
}

void StateMachine_liftControl_liftInterface_emergencyTrigger(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
}

void StateMachine_liftControl_liftInterface_maxWeightTrigger(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_weightMaxNOK_trigger__event, NULL);
}

void StateMachine_liftControl_liftInterface_detectionBarrierTrigger(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_detectionBarrier_trigger__event, NULL);
}

void StateMachine_liftControl_liftInterface_doorEOLTrigger(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
}

void StateMachine_liftControl_liftInterface_inTargetFloorTrigger(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
}

void StateMachine_liftControl_liftInterface_emergencyReleaseTrigger(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
}

void StateMachine_liftControl_liftInterface_openDoorButtonTrigger(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_openDoorButton_pressed__event, NULL);
}

void StateMachine_liftControl_liftInterface_closeDoorButtonTrigger(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
}

void StateMachine_liftControl_liftInterface_targetFloorCallOkTrigger(void *___id)
{
  StateMachine_liftControl__cdata_t *___cid = ((StateMachine_liftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
}

void StateMachine_callLiftControl_main(void *___id)
{
  
}

void StateMachine_callLiftControl_callLiftInterface_targetFloorCall(void *___id)
{
  StateMachine_callLiftControl__cdata_t *___cid = ((StateMachine_callLiftControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
}

void StateMachine_timeOutControl_main(void *___id)
{
  
}

void StateMachine_timeOutControl_TimeOutInterface_timeOutReleaseTrigger(void *___id)
{
  StateMachine_timeOutControl__cdata_t *___cid = ((StateMachine_timeOutControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
}

void StateMachine_timeOutControl_TimeOutInterface_timeoutNoActionLTrigger(void *___id)
{
  StateMachine_timeOutControl__cdata_t *___cid = ((StateMachine_timeOutControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_timeoutNoAction__event, NULL);
}

void StateMachine_timeOutControl_TimeOutInterface_timeoutOpenDoorsTrigger(void *___id)
{
  StateMachine_timeOutControl__cdata_t *___cid = ((StateMachine_timeOutControl__cdata_t *) ___id);
  StateMachine_liftFSM__execute(&___cid->theLiftFSM__field, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
}

void StateMachine_motorUpControl_MotorUp_on(void *___id)
{
  printf("Motor Up On\n");
}

void StateMachine_motorUpControl_MotorUp_off(void *___id)
{
  printf("Motor Up Off\n");
}

void StateMachine_motorDownControl_MotorDown_on(void *___id)
{
  printf("Motor Down On\n");
}

void StateMachine_motorDownControl_MotorDown_off(void *___id)
{
  printf("Motor Down Off\n");
}

void StateMachine_motorOpenControl_MotorOpen_on(void *___id)
{
  printf("Motor Open Doors On\n");
}

void StateMachine_motorOpenControl_MotorOpen_off(void *___id)
{
  printf("Motor Open Doors Off\n");
}

void StateMachine_motorCloseControl_MotorClose_on(void *___id)
{
  printf("Motor Close Doors On\n");
}

void StateMachine_motorCloseControl_MotorClose_off(void *___id)
{
  printf("Motor Close Doors Off\n");
}

void StateMachine_emergencyAlarmControl_emergencyAlarm_on(void *___id)
{
  printf("Emergency Alarm On\n");
}

void StateMachine_emergencyAlarmControl_emergencyAlarm_off(void *___id)
{
  printf("Emergency Alarm Off\n");
}

void StateMachine_emergencyAlarmControl_emergencyAlarm_callEmergencyTeam(void *___id)
{
  printf("Calling Emergency Team\n");
}

void StateMachine_MaxWeightAlarmControl_MaxWeightAlarm_on(void *___id)
{
  printf("Max weight Alarm On\n");
}

void StateMachine_MaxWeightAlarmControl_MaxWeightAlarm_off(void *___id)
{
  printf("Max weight Alarm Off\n");
}

void StateMachine_ambientlightControl_ambientLightsInterface_on(void *___id)
{
  printf("Max weight Alarm On\n");
}

void StateMachine_ambientlightControl_ambientLightsInterface_off(void *___id)
{
  printf("Max weight Alarm Off\n");
}

static inline void StateMachine_liftFSM_standby_EntryAction(StateMachine_liftFSM__data_t *instance)
{
  label_state_reachable_5831586151081264756:

  (void)0;
  printf("Lift in StandBy\n");
  StateMachine_doMotorCloseOff();
}

static inline void StateMachine_liftFSM_prepare_EntryAction(StateMachine_liftFSM__data_t *instance)
{
  label_state_reachable_5831586151081264816:

  (void)0;
  printf("Preparing Lift...\n");
}

static inline void StateMachine_liftFSM_moveUP_EntryAction(StateMachine_liftFSM__data_t *instance)
{
  label_state_reachable_5831586151081264937:

  (void)0;
  printf("Moving Up...\n");
  StateMachine_doMotorUpOn();
  StateMachine_motorUpSpeed = 100;
  StateMachine_doMotorDownOff();
}

static inline void StateMachine_liftFSM_moveUP_ExitAction(StateMachine_liftFSM__data_t *instance)
{
  printf("Slowing down...\n");
  StateMachine_motorUpSpeed = 50;
}

static inline void StateMachine_liftFSM_moveDown_EntryAction(StateMachine_liftFSM__data_t *instance)
{
  label_state_reachable_5831586151081264979:

  (void)0;
  printf("Moving Down...\n");
  StateMachine_doMotorUpOff();
  StateMachine_doMotorDownOn();
  StateMachine_motorDownSpeed = 100;
}

static inline void StateMachine_liftFSM_moveDown_ExitAction(StateMachine_liftFSM__data_t *instance)
{
  printf("Slowing down...\n");
  StateMachine_motorDownSpeed = 50;
}

static inline void StateMachine_liftFSM_release_EntryAction(StateMachine_liftFSM__data_t *instance)
{
  label_state_reachable_5831586151081265032:

  (void)0;
  printf("Stopping...\n");
  StateMachine_doMotorUpOn();
  StateMachine_motorUpSpeed = 0;
  StateMachine_doMotorDownOff();
  StateMachine_motorDownSpeed = 0;
  StateMachine_movementDisplay = "NULL";
}

static inline void StateMachine_liftFSM_openDoor_EntryAction(StateMachine_liftFSM__data_t *instance)
{
  label_state_reachable_5831586151081265127:

  (void)0;
  StateMachine_doMotorOpenOn();
  StateMachine_doMotorCloseOff();
  StateMachine_doMaxWeightAlarmOff();
}

static inline void StateMachine_liftFSM_openDoor_ExitAction(StateMachine_liftFSM__data_t *instance)
{
  StateMachine_doMotorOpenOff();
  StateMachine_doMotorCloseOff();
}

static inline void StateMachine_liftFSM_closeDoor_EntryAction(StateMachine_liftFSM__data_t *instance)
{
  label_state_reachable_5831586151081265196:

  (void)0;
  StateMachine_doMotorOpenOff();
  StateMachine_doMotorCloseOn();
}

static inline void StateMachine_liftFSM_closeDoor_ExitAction(StateMachine_liftFSM__data_t *instance)
{
  StateMachine_doMotorOpenOff();
  StateMachine_doMotorCloseOff();
}

static inline void StateMachine_liftFSM_emergency_EntryAction(StateMachine_liftFSM__data_t *instance)
{
  label_state_reachable_5831586151081265355:

  (void)0;
  StateMachine_doEmergencyAlarmOn();
  StateMachine_doMotorUpOff();
  StateMachine_doMotorDownOff();
  StateMachine_motorUpSpeed = 0;
  StateMachine_motorDownSpeed = 0;
  StateMachine_doCallEmergencyTeam();
}
