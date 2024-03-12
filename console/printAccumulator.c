#include <console.h>

void
printAccumulator (void)
{
  int value = 0;

  sc_accumulatorGet (&value);

  printf ("Аккумулятор: +%.4x\n", value);
}