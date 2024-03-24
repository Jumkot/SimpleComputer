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

  sc_commandDecode (value, &sign, &command, &operand);
  int length = sprintf (string, "sc: %c%.2x%.2x hex: %.4x", (sign) ? '-' : '+',
                        command, operand, value);

  mt_gotoXY (2, 64);
  write (1, string, length);
}