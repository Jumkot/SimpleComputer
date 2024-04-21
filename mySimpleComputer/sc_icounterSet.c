#include <mySimpleComputer.h>

int
sc_icounterSet (int value)
{
  if (value >= 0 && value < 32767)
    {
      sc_regSet (P, 0);
      instruction_counter = value;
      return 0;
    }

  sc_regSet (P, 1);
  return -1;
}