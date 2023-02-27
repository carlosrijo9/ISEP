#include "UnitTestMessages.h"

#include <stdio.h>

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_runningTestCase(char *name, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("runningTestCase: running test case (");
  printf("name=%s", ((char *) name));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE(uint8_t assertId, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_INT(uint8_t assertId, int64_t act, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_INT: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%li", ((int64_t) act));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_INT_STR(uint8_t assertId, int64_t act, char *exp, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_INT_STR: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%li", ((int64_t) act));
  printf(", exp=%s", ((char *) exp));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_INT_INT(uint8_t assertId, int64_t act, char *op, int64_t exp, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_INT_INT: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%li", ((int64_t) act));
  printf(", op=%s", ((char *) op));
  printf(", exp=%li", ((int64_t) exp));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_INT_DOUBLE(uint8_t assertId, int64_t act, char *op, double exp, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_INT_DOUBLE: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%li", ((int64_t) act));
  printf(", op=%s", ((char *) op));
  printf(", exp=%g", ((double) exp));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_DOUBLE(uint8_t assertId, double act, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_DOUBLE: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%g", ((double) act));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_DOUBLE_STR(uint8_t assertId, double act, char *exp, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_DOUBLE_STR: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%g", ((double) act));
  printf(", exp=%s", ((char *) exp));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_DOUBLE_DOUBLE(uint8_t assertId, double act, char *op, double exp, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_DOUBLE_DOUBLE: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%g", ((double) act));
  printf(", op=%s", ((char *) op));
  printf(", exp=%g", ((double) exp));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_DOUBLE_INT(uint8_t assertId, double act, char *op, int64_t exp, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_DOUBLE_INT: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%g", ((double) act));
  printf(", op=%s", ((char *) op));
  printf(", exp=%li", ((int64_t) exp));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_BOOL_BOOL(uint8_t assertId, bool act, char *op, bool exp, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_BOOL_BOOL: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%d", ((bool) act));
  printf(", op=%s", ((char *) op));
  printf(", exp=%d", ((bool) exp));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_RANGE(uint8_t assertId, double act, char *op, double val1, double val2, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_RANGE: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=%g", ((double) act));
  printf(", op=%s", ((char *) op));
  printf(", val1=%g", ((double) val1));
  printf(", val2=%g", ((double) val2));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_PTR_STR(uint8_t assertId, void const *act, char *op, char *exp, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_PTR_STR: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=0x%p", ((void const *) act));
  printf(", op=%s", ((char *) op));
  printf(", exp=%s", ((char *) exp));
  printf(", location=@%s) \n", loc);
}

/* 
 * Message Reporting Function
 */
void UnitTestMessages____testing_FAILURE_PTR_PTR(uint8_t assertId, void const *act, char *op, void const *exp, char *loc)
{
  /* 
   * If this format is changed you also have to take care of the MbeddrStackTraceLoggers code that it can extract the information from the printed string. If you are unsure DON'T touch this code
   */
  printf("FAILURE_PTR_PTR: ***FAILURE*** (");
  printf("assertId=%hhu", ((uint8_t) assertId));
  printf(", act=0x%p", ((void const *) act));
  printf(", op=%s", ((char *) op));
  printf(", exp=0x%p", ((void const *) exp));
  printf(", location=@%s) \n", loc);
}
