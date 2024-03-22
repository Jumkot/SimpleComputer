#include <myTerm.h>

int
mt_setbgcolor (enum colors color)
{
  if (((color < 1) || (color > 7)) && (color != 16))
    {
      return -1;
    }

  char string[16];
  int length = sprintf (string, "\E[48;5;%dm", color);
  int result = write (1, string, length);

  return result > 0 ? 0 : -1;
}