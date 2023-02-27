#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

enum StateMachine_mealyLightSwitch__inevents {
  StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_onPressed__event,
  StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_offPressed__event
};
typedef enum StateMachine_mealyLightSwitch__inevents StateMachine_mealyLightSwitch__inevents_t;

enum StateMachine_mealyLightSwitch__states {
  StateMachine_mealyLightSwitch__states__mealyLightSwitch___initializing__state = -2,
  StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightOFF__state = 0,
  StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONdim__state,
  StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONmedium__state,
  StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONbright__state
};
typedef enum StateMachine_mealyLightSwitch__states StateMachine_mealyLightSwitch__states_t;

struct StateMachine_mealyLightSwitch__data {
  StateMachine_mealyLightSwitch__states_t __currentState;
};
typedef struct StateMachine_mealyLightSwitch__data StateMachine_mealyLightSwitch__data_t;

void StateMachine_mealyLightSwitch__init(StateMachine_mealyLightSwitch__data_t *instance, bool postponeInitialExecution);

bool StateMachine_mealyLightSwitch__execute(StateMachine_mealyLightSwitch__data_t *instance, StateMachine_mealyLightSwitch__inevents_t event, void **arguments);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
