#include <myTerm.h>

int
mt_delline (void)
{
  char string[16];
  int length = snprintf (string, 16, "\E[M");
  int result = write (1, string, length);

  return result > 0 ? 0 : -1;
}