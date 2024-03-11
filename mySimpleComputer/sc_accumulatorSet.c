#include "mySimpleComputer.h"

int
sc_accumulatorSet (int value)
{
  // Разрядность аккумулятора равна 15 бит => 2^15
  if (value >= 0 && value < 32768)
    {
      accumulator = value;
    }
  return 0;
}