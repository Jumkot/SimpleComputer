#include <console.h>

void
printAccumulator (void)
{
  int value = 0;
  sc_accumulatorGet (&value);

  int sign = 0;
  int command = 0;
  int operand = 0;
  char string[21];
  int length = 0;

  sc_commandDecode (value, &sign, &command, &operand);

  if (value < 0)
    {
      int temp = 0x0;
      temp = value * (-1);
      length = snprintf (string, 21, "sc: %c%.2x%.2x hex:-%.4x\n",
                         (sign) ? '-' : '+', command, operand, temp);
    }
  else
    {      
      length = snprintf (string, 21, "sc: %c%.2x%.2x hex: %.4x",
                         (sign) ? '-' : '+', command, operand, value);
    }
  mt_gotoXY (2, 64);
  write (1, string, length);

  mt_gotoXY (26, 1);
}