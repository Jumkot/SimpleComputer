#include <myTerm.h>

int
mt_clrstr (void)
{
  char string[16];
  int length = snprintf (string, 16, "\E[2K\r");
  int result = write (1, string, length);

  return result > 0 ? 0 : -1;
}