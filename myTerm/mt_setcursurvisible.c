#include <myTerm.h>

int
mt_setcursorvisible (int value)
{
  char string[16];
  int result;

  if (value == 0)
    {
      int length = snprintf (string, 16, "\E[?25l");
      result = write (1, string, length);
    }
  else if (value == 1)
    {
      int length = snprintf (string, 16, "\E[?12h");
      result = write (1, string, length);
    }
  else
    {
      return -1;
    }

  return result > 0 ? 0 : -1;
}