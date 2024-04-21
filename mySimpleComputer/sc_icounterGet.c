#include <mySimpleComputer.h>

int
sc_icounterGet (int *value)
{
  if (value)
    {
      *value = instruction_counter;
      sc_regSet (M, 0);
      return 0;
    }

  sc_regSet (M, 1);
  return -1;
}