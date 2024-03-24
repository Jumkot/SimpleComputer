#include <mySimpleComputer.h>

int
sc_accumulatorSet (int value)
{
  if (value >= -32768 && value < 32768)
    {
      accumulator = value;
      return 0;
    }

  return -1;
}