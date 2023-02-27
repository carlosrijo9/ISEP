#include "HelloWorld.h"

#include <stdio.h>
#include "StateMachine.h"
#include <stdlib.h>
#include <time.h>

static int32_t HelloWorld_testCol_invoke_test_case(UnitTestDefinitions_TestCase_t *caze);

static void HelloWorld_closure_a01a31(void);

static UnitTestDefinitions_TestSuite_t HelloWorld_testCol_testsuite = 
{
  .name = "testCol", 
  .module_name = "HelloWorld", 
  .model_name = "liftFSM.model", 
  .test_case_count = 12, 
  .test_cases = 
  {
    
    {
      .id = 0, 
      .name = "testMain", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "5831586151081228859", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 1, 
      .name = "testEmergencyMovingUP", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970036363640", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 2, 
      .name = "testEmergencyMovingDOWN", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970037229558", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 3, 
      .name = "testEmergencyRelease", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970037239824", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 4, 
      .name = "testEmergencyOpenDoors", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970037254987", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 5, 
      .name = "testEmergencyCloseDoors", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970037308413", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 6, 
      .name = "testEmergencyPrepare", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970037332328", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 7, 
      .name = "testEmergencyStandBy", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970037351725", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 8, 
      .name = "testWeightError", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970036365521", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 9, 
      .name = "testClosingDoor", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970036552741", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 10, 
      .name = "testMovingUP", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970037178500", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }, 
    
    {
      .id = 11, 
      .name = "testMovingDOWN", 
      .class_name = "testCol", 
      .model_id = "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", 
      .node_id = "8732702970037216016", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }
  }, 
  .required_tag_count = 0, 
  .required_tags = { 0 }, 
  .skipped_count = 0, 
  .failure_count = 0, 
  .error_count = 0, 
  .init = &HelloWorld_closure_a01a31, 
  .invoke_test_case = &HelloWorld_testCol_invoke_test_case
};

int32_t HelloWorld_testMain(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testMain", "HelloWorld:testMain?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#5831586151081228859");
  printf("Lift State Machine - Main Test\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463014");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testMain?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463014");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveDown__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463025");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testMain:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463025");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463036");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testMain:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463036");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463047");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testMain:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463047");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_weightMaxNOK_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 4, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037545651");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(4, "HelloWorld:testMain:4?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037545651");
  }
  printf("The extra person left the lift\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 5, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463058");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(5, "HelloWorld:testMain:5?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463058");
  }
  printf("Open door button pressed\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_openDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 6, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037548281");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(6, "HelloWorld:testMain:6?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037548281");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 7, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037548292");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(7, "HelloWorld:testMain:7?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037548292");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 8, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463069");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(8, "HelloWorld:testMain:8?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463069");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 9, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463080");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(9, "HelloWorld:testMain:9?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463080");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 10, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463091");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(10, "HelloWorld:testMain:10?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463091");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 11, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463102");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(11, "HelloWorld:testMain:11?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463102");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 12, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463113");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(12, "HelloWorld:testMain:12?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463113");
  }
  printf("An object passes throught the closing door\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_detectionBarrier_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 13, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037552651");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(13, "HelloWorld:testMain:13?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037552651");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 14, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037552662");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(14, "HelloWorld:testMain:14?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037552662");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 15, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463124");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(15, "HelloWorld:testMain:15?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463124");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutNoAction__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 16, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037463135");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(16, "HelloWorld:testMain:16?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037463135");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 17, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037997460");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(17, "HelloWorld:testMain:17?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037997460");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 18, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037997471");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(18, "HelloWorld:testMain:18?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037997471");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 19, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037997482");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(19, "HelloWorld:testMain:19?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037997482");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 20, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037997493");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(20, "HelloWorld:testMain:20?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037997493");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 21, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037997507");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(21, "HelloWorld:testMain:21?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037997507");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 22, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037997521");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(22, "HelloWorld:testMain:22?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037997521");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 23, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037997535");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(23, "HelloWorld:testMain:23?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037997535");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 24, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038006558");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(24, "HelloWorld:testMain:24?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038006558");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 25, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038006569");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(25, "HelloWorld:testMain:25?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038006569");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 26, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038006580");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(26, "HelloWorld:testMain:26?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038006580");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 27, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038006591");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(27, "HelloWorld:testMain:27?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038006591");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveDown__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 28, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038006602");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(28, "HelloWorld:testMain:28?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038006602");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 29, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038006616");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(29, "HelloWorld:testMain:29?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038006616");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 30, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038006630");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(30, "HelloWorld:testMain:30?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038006630");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 31, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038012087");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(31, "HelloWorld:testMain:31?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038012087");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 32, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038012098");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(32, "HelloWorld:testMain:32?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038012098");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 33, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038012109");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(33, "HelloWorld:testMain:33?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038012109");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 34, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038012120");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(34, "HelloWorld:testMain:34?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038012120");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 35, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038012131");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(35, "HelloWorld:testMain:35?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038012131");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 36, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038012142");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(36, "HelloWorld:testMain:36?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038012142");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 37, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038012156");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(37, "HelloWorld:testMain:37?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038012156");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 38, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038012170");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(38, "HelloWorld:testMain:38?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038012170");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 39, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038020620");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(39, "HelloWorld:testMain:39?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038020620");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 40, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038020631");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(40, "HelloWorld:testMain:40?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038020631");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 41, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038020645");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(41, "HelloWorld:testMain:41?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038020645");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 42, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038020659");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(42, "HelloWorld:testMain:42?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038020659");
  }
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 43, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026537");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(43, "HelloWorld:testMain:43?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026537");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 44, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026548");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(44, "HelloWorld:testMain:44?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026548");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 45, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026559");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(45, "HelloWorld:testMain:45?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026559");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 46, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026570");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(46, "HelloWorld:testMain:46?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026570");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 47, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026581");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(47, "HelloWorld:testMain:47?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026581");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 48, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026592");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(48, "HelloWorld:testMain:48?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026592");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 49, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026603");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(49, "HelloWorld:testMain:49?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026603");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 50, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026614");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(50, "HelloWorld:testMain:50?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026614");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 51, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026628");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(51, "HelloWorld:testMain:51?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026628");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 52, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038026642");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(52, "HelloWorld:testMain:52?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038026642");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 53, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038040946");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(53, "HelloWorld:testMain:53?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038040946");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 54, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038040960");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(54, "HelloWorld:testMain:54?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038040960");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 55, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038040974");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(55, "HelloWorld:testMain:55?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038040974");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 56, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038050977");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(56, "HelloWorld:testMain:56?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038050977");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 57, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970038050991");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(57, "HelloWorld:testMain:57?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970038050991");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testMovingUP(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testMovingUP", "HelloWorld:testMovingUP?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037178500");
  printf("Lift State Machine - Moving Up Test\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037201345");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testMovingUP?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037201345");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveDown__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037201554");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testMovingUP:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037201554");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037202018");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testMovingUP:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037202018");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037202538");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testMovingUP:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037202538");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 4, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037203078");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(4, "HelloWorld:testMovingUP:4?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037203078");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 5, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037204966");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(5, "HelloWorld:testMovingUP:5?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037204966");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 6, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037205480");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(6, "HelloWorld:testMovingUP:6?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037205480");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 7, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037206243");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(7, "HelloWorld:testMovingUP:7?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037206243");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 8, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037206254");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(8, "HelloWorld:testMovingUP:8?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037206254");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 9, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037206265");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(9, "HelloWorld:testMovingUP:9?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037206265");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 10, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037206276");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(10, "HelloWorld:testMovingUP:10?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037206276");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutNoAction__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 11, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037206287");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(11, "HelloWorld:testMovingUP:11?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037206287");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testMovingDOWN(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testMovingDOWN", "HelloWorld:testMovingDOWN?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216016");
  printf("Lift State Machine - Moving Down Test\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216032");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testMovingDOWN?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216032");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216043");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testMovingDOWN:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216043");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216054");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testMovingDOWN:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216054");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216065");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testMovingDOWN:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216065");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 4, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216076");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(4, "HelloWorld:testMovingDOWN:4?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216076");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 5, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216087");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(5, "HelloWorld:testMovingDOWN:5?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216087");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveDown__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 6, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216098");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(6, "HelloWorld:testMovingDOWN:6?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216098");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 7, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216109");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(7, "HelloWorld:testMovingDOWN:7?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216109");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 8, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216120");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(8, "HelloWorld:testMovingDOWN:8?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216120");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 9, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216131");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(9, "HelloWorld:testMovingDOWN:9?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216131");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 10, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216142");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(10, "HelloWorld:testMovingDOWN:10?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216142");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutNoAction__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 11, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037216153");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(11, "HelloWorld:testMovingDOWN:11?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037216153");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testEmergencyMovingUP(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testEmergencyMovingUP", "HelloWorld:testEmergencyMovingUP?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970036363640");
  printf("Lift State Machine - Emergency Test\n");
  printf("This test will simulate a Emergency call when the Lift is Moving Up and simulate the transition when the Emergency is fixed.\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037180588");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testEmergencyMovingUP?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037180588");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037180819");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testEmergencyMovingUP:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037180819");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037181209");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testEmergencyMovingUP:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037181209");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037181675");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testEmergencyMovingUP:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037181675");
  }
  printf("Selecting a floor above the current floor\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 4, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037182966");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(4, "HelloWorld:testEmergencyMovingUP:4?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037182966");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 5, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037182102");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(5, "HelloWorld:testEmergencyMovingUP:5?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037182102");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 6, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037184095");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(6, "HelloWorld:testEmergencyMovingUP:6?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037184095");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testEmergencyMovingDOWN(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testEmergencyMovingDOWN", "HelloWorld:testEmergencyMovingDOWN?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037229558");
  printf("Lift State Machine - Emergency Test\n");
  printf("This test will simulate a Emergency call when the Lift is Moving Down and simulate the transition when the Emergency is fixed.\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037229577");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testEmergencyMovingDOWN?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037229577");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037229588");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testEmergencyMovingDOWN:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037229588");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037229599");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testEmergencyMovingDOWN:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037229599");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037229610");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testEmergencyMovingDOWN:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037229610");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveDown__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 4, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037229624");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(4, "HelloWorld:testEmergencyMovingDOWN:4?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037229624");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 5, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037229638");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(5, "HelloWorld:testEmergencyMovingDOWN:5?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037229638");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 6, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037229652");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(6, "HelloWorld:testEmergencyMovingDOWN:6?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037229652");
  }
  
  return ___failuresVal;
}

int32_t HelloWorld_testEmergencyRelease(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testEmergencyRelease", "HelloWorld:testEmergencyRelease?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037239824");
  printf("Lift State Machine - Emergency Test\n");
  printf("This test will simulate a Emergency call when the Lift is Stopping and simulate the transition when the Emergency is fixed.\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037239843");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testEmergencyRelease?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037239843");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037239854");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testEmergencyRelease:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037239854");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037239865");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testEmergencyRelease:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037239865");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037239876");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testEmergencyRelease:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037239876");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 4, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037239890");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(4, "HelloWorld:testEmergencyRelease:4?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037239890");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 5, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037250549");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(5, "HelloWorld:testEmergencyRelease:5?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037250549");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 6, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037239904");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(6, "HelloWorld:testEmergencyRelease:6?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037239904");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 7, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037239918");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(7, "HelloWorld:testEmergencyRelease:7?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037239918");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testEmergencyOpenDoors(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testEmergencyOpenDoors", "HelloWorld:testEmergencyOpenDoors?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037254987");
  printf("Lift State Machine - Emergency Test\n");
  printf("This test will simulate a Emergency call when the Lift is Opening the Doros and simulate the transition when the Emergency is fixed.\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037255006");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testEmergencyOpenDoors?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037255006");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037255017");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testEmergencyOpenDoors:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037255017");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037255078");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testEmergencyOpenDoors:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037255078");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037255092");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testEmergencyOpenDoors:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037255092");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testEmergencyCloseDoors(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testEmergencyCloseDoors", "HelloWorld:testEmergencyCloseDoors?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037308413");
  printf("Lift State Machine - Emergency Test\n");
  printf("This test will simulate a Emergency call when the Lift is Closing the Doros and simulate the transition when the Emergency is fixed.\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037308432");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testEmergencyCloseDoors?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037308432");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037308443");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testEmergencyCloseDoors:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037308443");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037308454");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testEmergencyCloseDoors:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037308454");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037308465");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testEmergencyCloseDoors:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037308465");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorAbove__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveUP__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 4, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037308479");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(4, "HelloWorld:testEmergencyCloseDoors:4?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037308479");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 5, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037308490");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(5, "HelloWorld:testEmergencyCloseDoors:5?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037308490");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 6, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037328858");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(6, "HelloWorld:testEmergencyCloseDoors:6?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037328858");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 7, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037329923");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(7, "HelloWorld:testEmergencyCloseDoors:7?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037329923");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 8, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037308504");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(8, "HelloWorld:testEmergencyCloseDoors:8?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037308504");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 9, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037308518");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(9, "HelloWorld:testEmergencyCloseDoors:9?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037308518");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testEmergencyPrepare(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testEmergencyPrepare", "HelloWorld:testEmergencyPrepare?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037332328");
  printf("Lift State Machine - Emergency Test\n");
  printf("This test will simulate a Emergency call when the Lift is in Prepare and simulate the transition when the Emergency is fixed.\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037332347");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testEmergencyPrepare?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037332347");
  }
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037332438");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testEmergencyPrepare:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037332438");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037332452");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testEmergencyPrepare:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037332452");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testEmergencyStandBy(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testEmergencyStandBy", "HelloWorld:testEmergencyStandBy?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037351725");
  printf("Lift State Machine - Emergency Test\n");
  printf("This test will simulate a Emergency call when the Lift is on StandBy and simulate the transition when the Emergency is fixed.\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  printf("Triggering the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_emergency__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037351758");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testEmergencyStandBy?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037351758");
  }
  printf("Releasing the Emergency Button\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_emergencyButton_released__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037351772");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testEmergencyStandBy:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037351772");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testWeightError(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testWeightError", "HelloWorld:testWeightError?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970036365521");
  printf("Lift State Machine - Error Test\n");
  printf("This test will simulate an Weight error when there are one or more extra people inside the lift.\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037184983");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testWeightError?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037184983");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037185302");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testWeightError:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037185302");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_weightMaxNOK_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037185777");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testWeightError:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037185777");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_weightMaxNOK_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037186220");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testWeightError:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037186220");
  }
  printf("The extra person left the lift\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 4, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037186635");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(4, "HelloWorld:testWeightError:4?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037186635");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 5, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037188047");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(5, "HelloWorld:testWeightError:5?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037188047");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveDown__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 6, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037188802");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(6, "HelloWorld:testWeightError:6?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037188802");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 7, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037189686");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(7, "HelloWorld:testWeightError:7?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037189686");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 8, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037190437");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(8, "HelloWorld:testWeightError:8?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037190437");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 9, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037191300");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(9, "HelloWorld:testWeightError:9?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037191300");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 10, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037188460");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(10, "HelloWorld:testWeightError:10?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037188460");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutNoAction__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 11, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037191858");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(11, "HelloWorld:testWeightError:11?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037191858");
  }
  return ___failuresVal;
}

int32_t HelloWorld_testClosingDoor(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testClosingDoor", "HelloWorld:testClosingDoor?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970036552741");
  printf("Lift State Machine - Barrier Detection Test\n");
  printf("This test will simulate an object passing throught the doors when they are closing and the press of openDoor button when the doors are closing\n");
  StateMachine_liftFSM__data_t fsm;
  StateMachine_liftFSM__init(&fsm, false);
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_callLiftButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037192447");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testClosingDoor?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037192447");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorCallOk__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037193521");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testClosingDoor:1?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037193521");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037194440");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testClosingDoor:2?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037194440");
  }
  printf("An object passes throught the closing door\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_detectionBarrier_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037194865");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testClosingDoor:3?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037194865");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_closeDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 4, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037195481");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(4, "HelloWorld:testClosingDoor:4?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037195481");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 5, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037196135");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(5, "HelloWorld:testClosingDoor:5?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037196135");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_targetFloorBellow__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_moveDown__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 6, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037196712");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(6, "HelloWorld:testClosingDoor:6?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037196712");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_inTargetFloor__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_release__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 7, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037197432");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(7, "HelloWorld:testClosingDoor:7?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037197432");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeOutRelease__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 8, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037198007");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(8, "HelloWorld:testClosingDoor:8?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037198007");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 9, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037198791");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(9, "HelloWorld:testClosingDoor:9?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037198791");
  }
  printf("Open door button pressed\n");
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_openDoorButton_pressed__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_openDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 10, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037199610");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(10, "HelloWorld:testClosingDoor:10?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037199610");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutOpenDoors__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_closeDoor__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 11, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037200457");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(11, "HelloWorld:testClosingDoor:11?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037200457");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_doorEOL_trigger__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_prepare__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 12, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037192763");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(12, "HelloWorld:testClosingDoor:12?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037192763");
  }
  StateMachine_liftFSM__execute(&fsm, StateMachine_liftFSM__inevents__liftFSM_timeoutNoAction__event, NULL);
  if (!((fsm.__currentState == StateMachine_liftFSM__states__liftFSM_standby__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 13, true, false, "r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)", "8732702970037192997");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(13, "HelloWorld:testClosingDoor:13?r:b0227cd8-062f-4d7f-9699-1148c0176730(liftFSM.model)#8732702970037192997");
  }
  return ___failuresVal;
}

int32_t main(int32_t argc, char *argv[])
{
  UnitTestDefinitions_TestSuite_t *all_suites[1] = { &HelloWorld_testCol_testsuite };
  uint32_t suite_count = 1;
  
  UnitTestCLI_parse_cli_options(argc, argv, all_suites, suite_count);
  
  atexit(&UnitTestRunner_cleanup_system_resources);
  
  if (UnitTestCLI_options.suite == NULL || UnitTestCLI_options.caze == NULL) 
  {
    /* 
     * Parent process that acts as test harness, invokes every test case in a separate child process 
     * and processes the result of the same (success, failure or error)
     */
    UnitTestRunner_init_test_campaign(all_suites, suite_count);
    UnitTestRunner_run_test_campaign(all_suites, suite_count);
    return UnitTestRunner_finalize_test_campaign(all_suites, suite_count);
  }
  else
  {
    /* 
     * Child process that runs an individual test case as per the specified command line arguments
     */
    return UnitTestRunner_init_test_suite_and_run_test_case(UnitTestCLI_options.suite, UnitTestCLI_options.caze);
  }
}

static int32_t HelloWorld_testCol_invoke_test_case(UnitTestDefinitions_TestCase_t *caze)
{
  if (caze == NULL) 
  {
    return -1;
  }
  
  switch (caze->id)
  {
    case 0:
    {
      return HelloWorld_testMain();
    }
    case 1:
    {
      return HelloWorld_testEmergencyMovingUP();
    }
    case 2:
    {
      return HelloWorld_testEmergencyMovingDOWN();
    }
    case 3:
    {
      return HelloWorld_testEmergencyRelease();
    }
    case 4:
    {
      return HelloWorld_testEmergencyOpenDoors();
    }
    case 5:
    {
      return HelloWorld_testEmergencyCloseDoors();
    }
    case 6:
    {
      return HelloWorld_testEmergencyPrepare();
    }
    case 7:
    {
      return HelloWorld_testEmergencyStandBy();
    }
    case 8:
    {
      return HelloWorld_testWeightError();
    }
    case 9:
    {
      return HelloWorld_testClosingDoor();
    }
    case 10:
    {
      return HelloWorld_testMovingUP();
    }
    case 11:
    {
      return HelloWorld_testMovingDOWN();
    }
    default: {
      return -1;
    }
  }
}

static void HelloWorld_closure_a01a31(void)
{
}
