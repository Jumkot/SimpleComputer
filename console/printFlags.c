#include <console.h>

void
printFlags (void)
{
  char string[30] = "P 0 M T E";

  for (int i = 0, k = 1; i < 5; ++i, k *= 2)
    {
      int value;
      sc_regGet (k, &value);

      if (value == 0)
        {
          string[2 * i] = '_';
        }
    }

  mt_gotoXY (2, 90);
  write (1, string, 9);
}