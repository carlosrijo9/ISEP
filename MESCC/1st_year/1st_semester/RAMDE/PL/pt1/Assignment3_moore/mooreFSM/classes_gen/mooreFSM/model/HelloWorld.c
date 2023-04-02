#include "HelloWorld.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "stateMachine.h"

static int32_t HelloWorld_testCol_invoke_test_case(UnitTestDefinitions_TestCase_t *caze);

static void HelloWorld_closure_a01a2(void);

static UnitTestDefinitions_TestSuite_t HelloWorld_testCol_testsuite = 
{
  .name = "testCol", 
  .module_name = "HelloWorld", 
  .model_name = "mooreFSM.model", 
  .test_case_count = 1, 
  .test_cases = 
  {
    
    {
      .id = 0, 
      .name = "testA", 
      .class_name = "testCol", 
      .model_id = "r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)", 
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

int32_t HelloWorld_testA(void)
{
  int32_t ___failuresVal = 0;
  int32_t *___failures = &___failuresVal;
  UnitTestMessages____testing_runningTestCase("testA", "HelloWorld:testA?r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)#8084837768086075844");
  stateMachine_mooreLightSwitch__data_t FSM1;
  printf("Start of flow test\n");
  stateMachine_mooreLightSwitch__init(&FSM1, false);
  
  stateMachine_mooreLightSwitch__execute(&FSM1, stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_onPressed__event, NULL);
  if (!((FSM1.__currentState == stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONdim__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 0, true, false, "r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)", "8084837768086510665");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(0, "HelloWorld:testA?r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)#8084837768086510665");
  }
  
  stateMachine_mooreLightSwitch__execute(&FSM1, stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_onPressed__event, NULL);
  if (!((FSM1.__currentState == stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONmedium__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 1, true, false, "r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)", "8084837768088079290");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(1, "HelloWorld:testA:1?r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)#8084837768088079290");
  }
  
  stateMachine_mooreLightSwitch__execute(&FSM1, stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_onPressed__event, NULL);
  if (!((FSM1.__currentState == stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONbright__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 2, true, false, "r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)", "8084837768088079560");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(2, "HelloWorld:testA:2?r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)#8084837768088079560");
  }
  
  stateMachine_mooreLightSwitch__execute(&FSM1, stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_offPressed__event, NULL);
  if (!((FSM1.__currentState == stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightOFF__state) == true)) 
  {
    UnitTestRunner_log_assert_fail_bool_bool("%s failure (id: %d): expected: [%s], but was: [%s]", "assert", 3, true, false, "r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)", "8084837768086624613");
    (*___failures)++;
    UnitTestMessages____testing_FAILURE(3, "HelloWorld:testA:3?r:392d0784-cf09-4442-b6b7-fb17319ad574(mooreFSM.model)#8084837768086624613");
  }
  
  FSM1.__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONdim__state;
  stateMachine_mooreLightSwitch__execute(&FSM1, stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_offPressed__event, NULL);
  
  FSM1.__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONmedium__state;
  stateMachine_mooreLightSwitch__execute(&FSM1, stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_offPressed__event, NULL);
  
  FSM1.__currentState = stateMachine_mooreLightSwitch__states__mooreLightSwitch_lightONbright__state;
  stateMachine_mooreLightSwitch__execute(&FSM1, stateMachine_mooreLightSwitch__inevents__mooreLightSwitch_onPressed__event, NULL);
  
  printf("End of flow test\n");
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
      return HelloWorld_testA();
    }
    default: {
      return -1;
    }
  }
}

static void HelloWorld_closure_a01a2(void)
{
}
