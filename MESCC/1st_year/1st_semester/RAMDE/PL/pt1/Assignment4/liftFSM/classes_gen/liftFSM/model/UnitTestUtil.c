#include "UnitTestUtil.h"

#if defined(_WIN32)
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>

bool UnitTestUtil_isPrintableUTF8Char(uint8_t ch)
{
  return isprint(ch) != 0 || ch == ((uint8_t) '\r') || ch == ((uint8_t) '\n') || ch == ((uint8_t) '\t');
}

char *UnitTestUtil_strrsep(char const *str)
{
  char *last_separator = NULL;
  char *separator = strrchr(str, '/');
  if (separator != NULL) 
  {
    last_separator = separator;
  }
  separator = strrchr(str, '\\');
  if (separator != NULL) 
  {
    if (last_separator == NULL || separator > last_separator) 
    {
      last_separator = separator;
    }
  }
  return last_separator;
}

int32_t UnitTestUtil_strreplchr(char *str, char oldchr, char newchr)
{
  char *pos = str;
  int32_t n = 0;
  while ((pos = strchr(pos, oldchr)) != NULL)
  {
    *pos = newchr;
    n++;
  }
  return n;
}

char const *UnitTestUtil_getSimpleProgramName(char const *program_name)
{
  char *last_separator = UnitTestUtil_strrsep(program_name);
  if (last_separator != NULL) 
  {
    return last_separator + 1;
  }
  return program_name;
}

int32_t UnitTestUtil_mkpath(char const *path)
{
  if (path == NULL) 
  {
    return 1;
  }
  if (strlen(path) == 0) 
  {
    return 1;
  }
  /* 
   * Path referring to current directory of file system root?
   */
  if (strcmp(path, ".") == 0 || strcmp(path, "/") == 0) 
  {
    return 0;
  }
  struct stat sb;
  /* 
   * All directories of given path already existing?
   */
  if (stat(path, &sb) == 0) 
  {
    return 0;
  }
  /* 
   * Extract parent directory of given path
   */
  char *parent_path = ((char *)(malloc(strlen(path) + 1)));
  if (parent_path == NULL) 
  {
    return 1;
  }
  char *last_separator = UnitTestUtil_strrsep(path);
  if (last_separator != NULL) 
  {
    uint32_t parent_path_len = last_separator - path;
    strncpy(parent_path, path, parent_path_len);
    parent_path[parent_path_len] = '\0';
  }
  else
  {
    strcpy(parent_path, ".");
  }
  /* 
   * Make sure that parent directory of given path exists
   */
  if (UnitTestUtil_mkpath(parent_path) != 0) 
  {
    free(parent_path);
    return 1;
  }
  free(parent_path);
  /* 
   * Create last directory of given path
   */
  #if defined(_WIN32)
  return mkdir(path);
  #else /* defined(_WIN32) */
  return mkdir(path, S_IRWXU);
  #endif /* defined(_WIN32) */

}

bool UnitTestUtil_isAbsolutePath(char const *path)
{
  if (path == NULL) 
  {
    return false;
  }
  if (strlen(path) >= 1 && path[0] == '/') 
  {
    return true;
  }
  if (strlen(path) >= 2 && path[1] == ':') 
  {
    return true;
  }
  return false;
}

char *UnitTestUtil_convertToAbsolutePath(char const *relative_path, char *absolute_path, size_t absolute_path_size)
{
  if (UnitTestUtil_isAbsolutePath(relative_path)) 
  {
    strncpy(absolute_path, relative_path, absolute_path_size);
  }
  else
  {
    getcwd(absolute_path, ((uint32_t) absolute_path_size));
    
    char const *appendable_relative_path = relative_path;
    if (strncmp(relative_path, "./", 2) == 0) 
    {
      appendable_relative_path = &relative_path[2];
    }
    if (strncmp(relative_path, ".\\", 2) == 0) 
    {
      appendable_relative_path = &relative_path[2];
    }
    
    snprintf(absolute_path + strlen(absolute_path), absolute_path_size - strlen(absolute_path), "/%s", appendable_relative_path);
  }
  return absolute_path;
}

char *UnitTestUtil_normalizePath(char *path)
{
  /* 
   * Path containing Linux and Windows path separators?
   */
  if (strchr(path, '/') != NULL && strchr(path, '\\') != NULL) 
  {
    /* 
     * Convert path to a pure Windows path
     */
    UnitTestUtil_strreplchr(path, '/', '\\');
  }
  return path;
}
