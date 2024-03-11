#include "mySimpleComputer.h"

int
sc_regSet (int registr, int value)
{
  // Разрядность регистра флагов равна 5 бит
  if (registr >= 0 && registr < 32)
    {
      if (value == 0)
        {
          registr = registr & (~(1 << registr));
        }
      else if (value == 1)
        {
          registr = registr | (1 << registr);
        }
      else
        {
          return -1;
        }
      return 0;
    }
  return -1;
}