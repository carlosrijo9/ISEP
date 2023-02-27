#include "HelloWorld.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "StateMachine.h"

static int32_t HelloWorld_testCol_invoke_test_case(UnitTestDefinitions_TestCase_t *caze);

static void HelloWorld_closure_a01a2(void);

static UnitTestDefinitions_TestSuite_t HelloWorld_testCol_testsuite = 
{
  .name = "testCol", 
  .module_name = "HelloWorld", 
  .model_name = "mealyFSM.model", 
  .test_case_count = 1, 
  .test_cases = 
  {
    
    {
      .id = 0, 
      .name = "testMain", 
      .class_name = "testCol", 
      .model_id = "r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)", 
      .node_id = "8084837768086075844", 
      .state = UnitTestDefinitions_TestState__TEST_STATE_NONE
    }
  }, 
  .required_tag_count = 0, 
  .required_tags = { 0 }, 
  .skipped_count = 0, 
  .failure_count = 0, 
  .error_count = 0, 
  .init = &HelloWorld_closure_a01a2, 
  .invoke_test_case = &HelloWorld_testCol_invoke_test_case
};

int32_t HelloWorld_testMain(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testMain", "HelloWorld:testMain?r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)#8084837768086075844");
  StateMachine_mealyLightSwitch__data_t FSM1;
  printf("Start of flow testMain\n");
  StateMachine_mealyLightSwitch__init(&FSM1, false);
  
  StateMachine_mealyLightSwitch__execute(&FSM1, StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_onPressed__event, NULL);
  if (!((FSM1.__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONdim__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)", "8084837768086510665");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testMain?r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)#8084837768086510665");
  }
  
  StateMachine_mealyLightSwitch__execute(&FSM1, StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_onPressed__event, NULL);
  if (!((FSM1.__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONmedium__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)", "8084837768088079290");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testMain:1?r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)#8084837768088079290");
  }
  
  StateMachine_mealyLightSwitch__execute(&FSM1, StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_onPressed__event, NULL);
  if (!((FSM1.__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONbright__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)", "8084837768088079560");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testMain:2?r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)#8084837768088079560");
  }
  
  StateMachine_mealyLightSwitch__execute(&FSM1, StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_offPressed__event, NULL);
  if (!((FSM1.__currentState == StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightOFF__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)", "8084837768086624613");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testMain:3?r:e5f6772f-48aa-422d-99e0-bb9f3bf86eb4(mealyFSM.model)#8084837768086624613");
  }
  
  FSM1.__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONdim__state;
  StateMachine_mealyLightSwitch__execute(&FSM1, StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_offPressed__event, NULL);
  
  FSM1.__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONmedium__state;
  StateMachine_mealyLightSwitch__execute(&FSM1, StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_offPressed__event, NULL);
  
  FSM1.__currentState = StateMachine_mealyLightSwitch__states__mealyLightSwitch_lightONbright__state;
  StateMachine_mealyLightSwitch__execute(&FSM1, StateMachine_mealyLightSwitch__inevents__mealyLightSwitch_onPressed__event, NULL);
  
  printf("End of flow testMain\n");
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
    default: {
      return -1;
    }
  }
}

static void HelloWorld_closure_a01a2(void)
{
}
