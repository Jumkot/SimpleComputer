#include <mySimpleComputer.h>

int
sc_accumulatorGet (int *value)
{
  if (value)
    {
      *value = accumulator;
      sc_regSet (M, 0);
      return 0;
    }

  sc_regSet (M, 1);
  return -1;
}