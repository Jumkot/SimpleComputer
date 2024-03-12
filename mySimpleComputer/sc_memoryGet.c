#include <mySimpleComputer.h>

int
sc_memoryGet (int address, int *value)
{
  if (!value)
    {
      printf ("Ошибка задания ячейки памяти - недопустимое значение\n");
      return -1;
    }
  if (address >= 0 && address < SIZE)
    {
      *value = ram[address];
      return 0;
    }

  printf ("Ошибка получения ячейки памяти - недопустимый адрес\n");
  return -1;
}