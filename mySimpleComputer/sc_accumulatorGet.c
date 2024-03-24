#include <mySimpleComputer.h>

int
sc_accumulatorGet (int *value)
{
  if (value)
    {
      *value = accumulator;
      return 0;
    }

  return -1;
}