#include <console.h>

void
printKeys ()
{
  int x = 20;
  int y = 79;

  char string[80];
  int length = 0;

  length = snprintf (string, 80, "l - load  s - save  i - reset");
  mt_gotoXY (x, y);
  write (1, string, length);

  length = snprintf (string, 80, "r - run  t - step");
  mt_gotoXY (x + 1, y);
  write (1, string, length);

  length = snprintf (string, 80, "ESC - выход");
  mt_gotoXY (x + 2, y);
  write (1, string, length);

  length = snprintf (string, 80, "F5 - accumulator");
  mt_gotoXY (x + 3, y);
  write (1, string, length);

  length = snprintf (string, 80, "F6 - instruction counter");
  mt_gotoXY (x + 4, y);
  write (1, string, length);

  mt_gotoXY (26, 1);
}