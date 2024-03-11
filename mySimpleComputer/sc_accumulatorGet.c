#include "mySimpleComputer.h"

int
sc_accumulatorGet (int *value)
{
  // Разрядность аккумулятора равна 15 бит => 2^15
  if (value >= 0 && value < 32768)
    {
      *value = accumulator;
    }
  return 0;
}