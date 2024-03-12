#include <mySimpleComputer.h>

int
sc_regSet (int reg, int value)
{
  if ((value != 0) || (value != 1))
    {
      printf ("Ошибка задания регистра - недопустимое значение\n");
      return -1;
    }
  else if ((reg != P) || (reg != O) || (reg != M) || (reg != T) || (reg != E))
    {
      printf ("Ошибка задания регистра - недопустимое имя регистра\n");
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