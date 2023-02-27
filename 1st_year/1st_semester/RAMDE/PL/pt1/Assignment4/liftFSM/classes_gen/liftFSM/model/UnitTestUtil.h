#ifndef UNITTESTUTIL_H
#define UNITTESTUTIL_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool UnitTestUtil_isPrintableUTF8Char(uint8_t ch);

char *UnitTestUtil_strrsep(char const *str);

int32_t UnitTestUtil_strreplchr(char *str, char oldchr, char newchr);

char const *UnitTestUtil_getSimpleProgramName(char const *program_name);

int32_t UnitTestUtil_mkpath(char const *path);

bool UnitTestUtil_isAbsolutePath(char const *path);

char *UnitTestUtil_convertToAbsolutePath(char const *relative_path, char *absolute_path, size_t absolute_path_size);

char *UnitTestUtil_normalizePath(char *path);

static inline char *UnitTestUtil_boolToStr(bool b);

static inline char *UnitTestUtil_boolToStr(bool b)
{
  return (b) ? ("true") : ("false");
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
