#include <myTerm.h>

int
mt_gotoXY (int x, int y)
{
  if (x > 27 || y > 108)
    {
      return -1;
    }

  char string[16];
  int length = snprintf (string, 16, "\E[%d;%dH", x, y);
  int result = write (1, string, length);

  return result > 0 ? 0 : -1;
}