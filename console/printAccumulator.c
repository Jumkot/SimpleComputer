#include <console.h>

void
printAccumulator (void)
{
  int value = 0;
  sc_accumulatorGet (&value);

  int sign = 0;
  int command = 0;
  int operand = 0;
  char string[50];

  sc_commandDecode (value, &sign, &command, &operand);
  int length = sprintf (string, "sc: %.2x%.2x hex: %.4x", command, operand, value);
  
  mt_gotoXY (64, 2);
  write (1, string, length);
}