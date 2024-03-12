#include <mySimpleComputer.h>

int
sc_icounterSet (int value)
{
  // Разрядность счётчика команд равна 7 бит => 2^7
  if (value >= 0 && value < 32767)
    {
      instruction_counter = value;
      return 0;
    }

  printf ("Ошибка задания счётчика - недопустимое значение\n");
  return -1;
}