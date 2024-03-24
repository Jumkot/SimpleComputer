#include <mySimpleComputer.h>

int
sc_icounterGet (int *value)
{
  if (value)
    {
      *value = instruction_counter;
      return 0;
    }

  return -1;
}