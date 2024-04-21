#include <mySimpleComputer.h>

int
sc_tcounterSet (int value)
{
  if (value >= 0 && value < 255)
    {
      idle_tact_counter = value;
      sc_regSet(P, 0);
      return 0;
    }

  sc_regSet(P, 1);
  return -1;
}