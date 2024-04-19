#include <mySimpleComputer.h>

int
sc_icounterGet (int *value)
{
  if (value)
    {
      *value = idle_tact_counter;
      return 0;
    }

  return -1;
}