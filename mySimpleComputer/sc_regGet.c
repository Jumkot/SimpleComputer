#include <mySimpleComputer.h>

int
sc_regGet (int reg, int *value)
{
  if ((reg != P) && (reg != O) && (reg != M) && (reg != T) && (reg != E))
    {
      sc_regSet (E, 1);
      return -1;
    }

  if (reg & registr)
    {
      *value = 1;
    }
  else
    {
      *value = 0;
    }

  sc_regSet (E, 0);
  return 0;
}