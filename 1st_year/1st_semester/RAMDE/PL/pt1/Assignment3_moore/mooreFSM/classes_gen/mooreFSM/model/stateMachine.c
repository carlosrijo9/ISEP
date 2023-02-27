#include "stateMachine.h"

#include <stdio.h>

static inline void stateMachine_mooreLightSwitch_lightOFF_EntryAction(stateMachine_mooreLightSwitch__data_t *instance);

static inline void stateMachine_mooreLightSwitch_lightOFF_DoAction2(stateMachine_mooreLightSwitch__data_t *instance);

static inline void stateMachine_mooreLightSwitch_lightONdim_EntryAction(stateMachine_mooreLightSwitch__data_t *instance);

static inline void stateMachine_mooreLightSwitch_lightONdim_DoAction3(stateMachine_mooreLightSwitch__data_t *instance);

static inline void stateMachine_mooreLightSwitch_lightONmedium_EntryAction(stateMachine_mooreLightSwitch__data_t *instance);

static inline void stateMachine_mooreLightSwitch_lightONmedium_DoAction3(stateMachine_mooreLightSwitch__data_t *instance);

static inline void stateMachine_mooreLightSwitch_lightONbright_EntryAction(stateMachine_mooreLightSwitch__data_t *instance);

static inline void stateMachine_mooreLightSwitch_lightONbright_DoAction3(stateMachine_mooreLightSwitch__data_t *instance);

void stateMachine_mooreLightSwitch__init(stateMachine_mooreLightSwitch__data_t *instance, bool postponeInitialExecution)
{
  if (!postponeInitialExecution) 
  {
    instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightOFF__state;
    stateMachine_mooreLightSwitch_lightOFF_EntryAction(instance);
    stateMachine_mooreLightSwitch_lightOFF_DoAction2(instance);
  }
  else
  {
    instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch___initializing__state;
  }
}

bool stateMachine_mooreLightSwitch__execute(stateMachine_mooreLightSwitch__data_t *instance, stateMachine_mooreLightSwitch__inevents_t event, void **arguments)
{
  bool __outstandingEvent;
  do {
    __outstandingEvent = false;
    switch (instance->__currentState)
    {
      case stateMachine_mooreLightSwitch__states__mooreLightSwitch___initializing__state:
      {
        /* 
         * enter initial state
         */
        instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightOFF__state;
        stateMachine_mooreLightSwitch_lightOFF_EntryAction(instance);
        stateMachine_mooreLightSwitch_lightOFF_DoAction2(instance);
        __outstandingEvent = true;
        break;
      }
      case stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightOFF__state:
      {
        stateMachine_mooreLightSwitch_lightOFF_DoAction2(instance);
        switch (event)
        {
          case stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_onPressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_8084837768086245330:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONdim__state;
            stateMachine_mooreLightSwitch_lightONdim_EntryAction(instance);
            stateMachine_mooreLightSwitch_lightONdim_DoAction3(instance);
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONdim__state:
      {
        stateMachine_mooreLightSwitch_lightONdim_DoAction3(instance);
        switch (event)
        {
          case stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_offPressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_8084837768086245345:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightOFF__state;
            stateMachine_mooreLightSwitch_lightOFF_EntryAction(instance);
            stateMachine_mooreLightSwitch_lightOFF_DoAction2(instance);
            break;
          }
          case stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_onPressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_8084837768086245509:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONmedium__state;
            stateMachine_mooreLightSwitch_lightONmedium_EntryAction(instance);
            stateMachine_mooreLightSwitch_lightONmedium_DoAction3(instance);
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONmedium__state:
      {
        stateMachine_mooreLightSwitch_lightONmedium_DoAction3(instance);
        switch (event)
        {
          case stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_offPressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_8084837768086245528:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightOFF__state;
            stateMachine_mooreLightSwitch_lightOFF_EntryAction(instance);
            stateMachine_mooreLightSwitch_lightOFF_DoAction2(instance);
            break;
          }
          case stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_onPressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_8084837768086245547:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONbright__state;
            stateMachine_mooreLightSwitch_lightONbright_EntryAction(instance);
            stateMachine_mooreLightSwitch_lightONbright_DoAction3(instance);
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONbright__state:
      {
        stateMachine_mooreLightSwitch_lightONbright_DoAction3(instance);
        switch (event)
        {
          case stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_offPressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_8084837768086245578:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightOFF__state;
            stateMachine_mooreLightSwitch_lightOFF_EntryAction(instance);
            stateMachine_mooreLightSwitch_lightOFF_DoAction2(instance);
            break;
          }
          case stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_onPressed__event:
          {
            /* 
             * transition actions
             */
            {
              label_transition_fireable_8084837768086245594:

              (void)0;
            }

            
            /* 
             * enter target state
             */
            instance->__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONdim__state;
            stateMachine_mooreLightSwitch_lightONdim_EntryAction(instance);
            stateMachine_mooreLightSwitch_lightONdim_DoAction3(instance);
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

static inline void stateMachine_mooreLightSwitch_lightOFF_EntryAction(stateMachine_mooreLightSwitch__data_t *instance)
{
  label_state_reachable_8084837768086245204:

  (void)0;
  printf("Entering lightOFF State\n");
}

static inline void stateMachine_mooreLightSwitch_lightOFF_DoAction2(stateMachine_mooreLightSwitch__data_t *instance)
{
  printf("set brightnessOff\n");
}

static inline void stateMachine_mooreLightSwitch_lightONdim_EntryAction(stateMachine_mooreLightSwitch__data_t *instance)
{
  label_state_reachable_8084837768086245263:

  (void)0;
  printf("Entering lightONdim State\n");
}

static inline void stateMachine_mooreLightSwitch_lightONdim_DoAction3(stateMachine_mooreLightSwitch__data_t *instance)
{
  printf("set brightnessLow\n");
}

static inline void stateMachine_mooreLightSwitch_lightONmedium_EntryAction(stateMachine_mooreLightSwitch__data_t *instance)
{
  label_state_reachable_8084837768086245374:

  (void)0;
  printf("Entering lightONmedium State\n");
}

static inline void stateMachine_mooreLightSwitch_lightONmedium_DoAction3(stateMachine_mooreLightSwitch__data_t *instance)
{
  printf("set brightnessMedium\n");
}

static inline void stateMachine_mooreLightSwitch_lightONbright_EntryAction(stateMachine_mooreLightSwitch__data_t *instance)
{
  label_state_reachable_8084837768086245465:

  (void)0;
  printf("Entering lightONbright State\n");
}

static inline void stateMachine_mooreLightSwitch_lightONbright_DoAction3(stateMachine_mooreLightSwitch__data_t *instance)
{
  printf("set brightnessHigh\n");
}
