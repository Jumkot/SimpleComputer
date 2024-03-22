#include <myTerm.h>

int
mt_delline (void)
{
  char string[16];
  int length = sprintf (string, "\E[M");
  int result = write (1, string, length);

  return result > 0 ? 0 : -1;
}