#include <mySimpleComputer.h>

int
sc_icounterSet (int value)
{
  if (value >= 0 && value < 128)
    {
      instruction_counter = value;
      return 0;
    }

  sc_regSet (P, 1);
  return -1;
}