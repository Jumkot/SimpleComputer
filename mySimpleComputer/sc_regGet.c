#include "mySimpleComputer.h"

int
sc_regGet (int registr, int *value)
{
  // Разрядность регистра флагов равна 5 бит => 2^5
  if (registr >= 0 && registr < 32)
    {
      *value = (registr >> registr) & 0x1;
      return 0;
    }

  return -1;
}