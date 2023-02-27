#include "StateMachine.h"

#include <stdio.h>

static inline void StateMachine_mealyLightSwitch_lightOFF_EntryAction(StateMachine_mealyLightSwitch__data_t *instance);

static inline void StateMachine_mealyLightSwitch_lightONdim_EntryAction(StateMachine_mealyLightSwitch__data_t *instance);

static inline void StateMachine_mealyLightSwitch_lightONmedium_EntryAction(StateMachine_mealyLightSwitch__data_t *instance);

void StateMachine_mealyLightSwitch__init(StateMachine_mealyLightSwitch__data_t *instance, bool postponeInitialExecution)
{
  if (!postponeInitialExecution) 
  {
    instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightOFF__state;
    StateMachine_mealyLightSwitch_lightOFF_EntryAction(instance);
  }
  else
  {
    instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch___initializing__state;
  }
}

bool StateMachine_mealyLightSwitch__execute(StateMachine_mealyLightSwitch__data_t *instance, StateMachine_mealyLightSwitch__inevents_t event, void **arguments)
{
  bool __outstandingEvent;
  do {
    __outstandingEvent = false;
    switch (instance->__currentState)
    {
      case StateMachine_mealyLightSwitch__states__mealyLightSwitch___initializing__state:
      {
        /* 
         * enter initial state
         */
        instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightOFF__state;
        StateMachine_mealyLightSwitch_lightOFF_EntryAction(instance);
        __outstandingEvent = true;
        break;
      }
      case StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightOFF__state:
      {
        switch (event)
        {
          case StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_onPressed__event:
          {
            /* 
             * transition actions
             */
            printf("set brightnessOnLow\n");
            
            if (instance->__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightOFF__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONdim__state;
              StateMachine_mealyLightSwitch_lightONdim_EntryAction(instance);
            }
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONdim__state:
      {
        switch (event)
        {
          case StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_offPressed__event:
          {
            /* 
             * transition actions
             */
            printf("set brightnessOFF\n");
            
            if (instance->__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONdim__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightOFF__state;
              StateMachine_mealyLightSwitch_lightOFF_EntryAction(instance);
            }
            break;
          }
          case StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_onPressed__event:
          {
            /* 
             * transition actions
             */
            printf("set brightnessOnMedium\n");
            
            if (instance->__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONdim__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONmedium__state;
              StateMachine_mealyLightSwitch_lightONmedium_EntryAction(instance);
            }
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONmedium__state:
      {
        switch (event)
        {
          case StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_offPressed__event:
          {
            /* 
             * transition actions
             */
            printf("set brightnessOff\n");
            
            if (instance->__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONmedium__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightOFF__state;
              StateMachine_mealyLightSwitch_lightOFF_EntryAction(instance);
            }
            break;
          }
          case StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_onPressed__event:
          {
            /* 
             * transition actions
             */
            printf("set brightnessOnHigh\n");
            
            if (instance->__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONmedium__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONbright__state;
            }
            break;
          }
          default: {
            break;
          }
        }
        break;
      }
      case StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONbright__state:
      {
        switch (event)
        {
          case StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_offPressed__event:
          {
            /* 
             * transition actions
             */
            printf("set brightnessOff\n");
            
            if (instance->__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONbright__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightOFF__state;
              StateMachine_mealyLightSwitch_lightOFF_EntryAction(instance);
            }
            break;
          }
          case StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_onPressed__event:
          {
            /* 
             * transition actions
             */
            printf("set brightnessOnLow\n");
            
            if (instance->__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONbright__state) 
            {
              /* 
               * enter target state
               */
              instance->__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONdim__state;
              StateMachine_mealyLightSwitch_lightONdim_EntryAction(instance);
            }
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

static inline void StateMachine_mealyLightSwitch_lightOFF_EntryAction(StateMachine_mealyLightSwitch__data_t *instance)
{
  printf("Entering lightOFF State\n");
}

static inline void StateMachine_mealyLightSwitch_lightONdim_EntryAction(StateMachine_mealyLightSwitch__data_t *instance)
{
  printf("Entering lightONdim State\n");
}

static inline void StateMachine_mealyLightSwitch_lightONmedium_EntryAction(StateMachine_mealyLightSwitch__data_t *instance)
{
  printf("Entering lightONmedium State\n");
}
