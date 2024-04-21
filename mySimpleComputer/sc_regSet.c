#include <mySimpleComputer.h>

int
sc_regSet (int reg, int value)
{
  if ((value != 0) && (value != 1) && (reg != P) && (reg != O) && (reg != M)
      && (reg != T) && (reg != E))
    {
      sc_regSet (E, 1);
      return -1;
    }

  if (value)
    {
      registr = registr | reg;
    }
  else
    {
      registr = registr & ~reg;
    }

  return 0;
}