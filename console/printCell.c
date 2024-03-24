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

  char sign_c;
  if (!sign)
    {
      sign_c = '+';
    }
  else
    {
      sign_c = '-';
    }

  mt_setfgcolor (fg);
  mt_setbgcolor (bg);

  char string[50];
  int length = sprintf (string, "%c%.2x%.2x\n", sign_c, command, operand);
  
  int y = address % 10 * 6 - 4;
  int x = address / 10 + 2;
  mt_gotoXY (x, y);
  write (1, string, length);

  mt_setdefaultcolor ();
}