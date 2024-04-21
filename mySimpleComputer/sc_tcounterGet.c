#include <mySimpleComputer.h>

int
sc_tcounterGet (int *value)
{
  if (value)
    {
      *value = idle_tact_counter;
      return 0;
    }

  return -1;
}