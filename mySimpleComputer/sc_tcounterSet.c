#include <mySimpleComputer.h>

int
sc_icounterSet (int value)
{
  if (value >= 0 && value < 255)
    {
      idle_tact_counter = value;
      return 0;
    }

  return -1;
}