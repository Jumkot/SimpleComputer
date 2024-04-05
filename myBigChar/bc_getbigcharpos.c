#include "myBigChar.h"

int
bc_getbigcharpos (int *big, int x, int y, int *value)
{
  if (x < 0 || x > 7 || y < 0 || y > 7)
    {
      return -1;
    }
  int part = x / 4;
  x %= 4;
  if (big[part] & (1 << (8 * x + (4 - y) + 2)))
    {
      *value = 1;
    }
  else
    {
      *value = 0;
    }
  return 0;
}