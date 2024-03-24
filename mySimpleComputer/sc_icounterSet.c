#include <mySimpleComputer.h>

int
sc_icounterSet (int value)
{
  if (value >= 0 && value < 32767)
    {
      instruction_counter = value;
      return 0;
    }

  return -1;
}