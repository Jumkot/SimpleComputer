#include <mySimpleComputer.h>

int
sc_icounterGet (int *value)
{
  if (value)
    {
      *value = instruction_counter;
      return 0;
    }

  printf ("Ошибка получения счётчика - недопустимое значение\n");
  return -1;
}