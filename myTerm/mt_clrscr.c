#include <myTerm.h>

int
mt_clrscr (void)
{
  char string[16];
  int length = snprintf (string, 16, "\E[H\E[2J");
  int result = write (1, string, length);

  return result > 0 ? 0 : -1;
}