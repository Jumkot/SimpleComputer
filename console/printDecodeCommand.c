#include <console.h>

void
printDecodedCommand (int value)
{
  char bin[16];

  int tmp = value;

  for (int i = 0; i < 15; ++i)
    {
      bin[15 - i - 1] = ((tmp >> i) & 1) + '0';
    }

  char string[61];
  sprintf (string, "dec: %.5d | oct: %.5o | hex: %.4x | bin: %s", value, value,
           value, bin);

  mt_gotoXY (17, 2);
  write (1, string, 60);
}