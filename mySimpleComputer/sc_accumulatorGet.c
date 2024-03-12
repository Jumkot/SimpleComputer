#include <mySimpleComputer.h>

int
sc_accumulatorGet (int *value)
{
  if (value)
    {
      *value = accumulator;
      return 0;
    }

  printf ("Ошибка получения аккумулятора - недопустимое значение\n");
  return -1;
}