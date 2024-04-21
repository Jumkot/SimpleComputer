#include <mySimpleComputer.h>

int
sc_tcounterGet (int *value)
{
  if (value)
    {
      *value = idle_tact_counter;
      sc_regSet (M, 0);
      return 0;
    }

  sc_regSet (M, 1);
  return -1;
}