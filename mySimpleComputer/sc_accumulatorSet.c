#include <mySimpleComputer.h>

int
sc_accumulatorSet (int value)
{
  if (value >= -32768 && value < 32768)
    {
      accumulator = value;
      sc_regSet(P, 0);
      return 0;
    }

  sc_regSet(P, 1);
  return -1;
}