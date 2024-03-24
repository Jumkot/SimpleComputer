#include <console.h>

static int history[5];

void
printTerm (int address, int input)
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;

  sc_memoryGet (address, &value);
  sc_commandDecode (value, &sign, &command, &operand);

  char string[50];
  int length = 0;

  if (input)
    {
      length = sprintf (string, "%s%s%d>     ", (address < 100) ? "0" : "",
                        (address < 10) ? "0" : "", address);
    }
  else
    {
      length = sprintf (string, "%s%s%d>%c%.2x%.2x", (address < 100) ? "0" : "",
                        (address < 10) ? "0" : "", address, (sign) ? '-' : '+',
                        command, operand);
    }

  for (int i = 4; i > 0; i--)
    {
      history[i] = history[i - 1];
    }
  history[0] = address;

  mt_gotoXY (24, 68);
  write (1, string, length);

  for (int i = 1; i < 5; i++)
    {
      address = history[i];
      sc_memoryGet (history[i], &value);
      sc_commandDecode (value, &sign, &command, &operand);

      length = sprintf (string, "%s%s%d>%c%.2x%.2x", (address < 100) ? "0" : "",
                        (address < 10) ? "0" : "", address, (sign) ? '-' : '+',
                        command, operand);

      mt_gotoXY (24 - i, 68);
      write (1, string, length);
    }
}