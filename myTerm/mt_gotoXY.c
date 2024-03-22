#include <myTerm.h>

int
mt_gotoXY (int x, int y)
{
  char string[16];
  int length = sprintf (string, "\E[%d;%dH", x, y);
  int result = write (1, string, length);

  return result > 0 ? 0 : -1;
}