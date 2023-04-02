#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

enum stateMachine_mooreLightSwitch__inevents {
  stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_onPressed__event,
  stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_offPressed__event
};
typedef enum stateMachine_mooreLightSwitch__inevents stateMachine_mooreLightSwitch__inevents_t;

enum stateMachine_mooreLightSwitch__states {
  stateMachine_mooreLightSwitch__states__mooreLightSwitch___initializing__state = -2,
  stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightOFF__state = 0,
  stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONdim__state,
  stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONmedium__state,
  stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONbright__state
};
typedef enum stateMachine_mooreLightSwitch__states stateMachine_mooreLightSwitch__states_t;

struct stateMachine_mooreLightSwitch__data {
  stateMachine_mooreLightSwitch__states_t __currentState;
};
typedef struct stateMachine_mooreLightSwitch__data stateMachine_mooreLightSwitch__data_t;

void stateMachine_mooreLightSwitch__init(stateMachine_mooreLightSwitch__data_t *instance, bool postponeInitialExecution);

bool stateMachine_mooreLightSwitch__execute(stateMachine_mooreLightSwitch__data_t *instance, stateMachine_mooreLightSwitch__inevents_t event, void **arguments);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
