
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

char *__hostname = NULL;

int gethostname(char *__name, size_t __len)
{
  if (__hostname == NULL) {
    return -1; // no hostname
  } else {
    strncpy(__name, __hostname, __len);
    return 0;
  }
}