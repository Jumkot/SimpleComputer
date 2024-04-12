#include <console.h>

void
keyF5 ()
{
  char string[5] = { 0 };
  mt_gotoXY (2, 79);
  scanf ("%4s", string);

  int value = 0;
  for (int i = 0; i < 4; i++)
    {
      int num;
      if (string[i] > 47 && string[i] < 58)
        {
          num = string[i] - 48;
        }
      else
        {
          num = string[i] - 87;
        }
      value += num * pow (16, 3 - i);
    }

  sc_accumulatorSet (value);
}