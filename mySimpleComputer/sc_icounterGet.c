#include "mySimpleComputer.h"

int
sc_icounterGet (int *value)
{
  // Разрядность счётчика команд равна 7 бит => 2^7
  if (instruction_counter >= 0 && instruction_counter < 128)
    {
      *value = instruction_counter;
      return 0;
    }
  return -1;
}