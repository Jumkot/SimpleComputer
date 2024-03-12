#include <console.h>

void
printFlags (void)
{
  char str[30] = "P 0 M T E";

  for (int i = 0, k = 1; i < 5; ++i, k *= 2)
    {
      int value;
      sc_regGet (k, &value);

      if (value == 0)
        {
          str[2 * i] = '_';
        }
    }
  printf ("Значения флагов: %s", str);
}