#include <console.h>

void
printCell (int address, enum colors fg, enum colors bg)
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;

  sc_memoryGet (address, &value);
  sc_commandDecode (value, &sign, &command, &operand);

  mt_setfgcolor (fg);
  mt_setbgcolor (bg);

  char string[50];
  int length = snprintf (string, 50, "%c%.2x%.2x", (sign) ? '-' : '+', command,
                         operand);

  int y = address % 10 * 6 + 2;
  int x = address / 10 + 2;
  mt_gotoXY (x, y);
  write (1, string, length);

  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}