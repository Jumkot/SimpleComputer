#include <console.h>

void
printDecodedCommand (int value)
{
  char bin[50];

  int tmp = value;

  for (int i = 0; i < 15; ++i)
    {
      bin[15 - i - 1] = ((tmp >> i) & 1) + '0';
    }

  printf ("Команда:\n dec: %.5d, oct: %.5o, ", value, value);
  printf ("hex: %.4x, bin: %s", value, bin);
}