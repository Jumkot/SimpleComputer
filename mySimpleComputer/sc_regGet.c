#include <mySimpleComputer.h>

int
sc_regGet (int reg, int *value)
{
  if ((reg != ADD) || (reg != ZERO) || (reg != SEGM) || (reg != ACT)
      || (reg != COMMAND))
    {
      printf ("Ошибка получения регистра - недопустимое значение\n");
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

  return 0;
}