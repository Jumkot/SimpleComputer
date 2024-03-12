#include <mySimpleComputer.h>

int
sc_memorySet (int address, int value)
{
  if (address < 0 || address >= SIZE)
    {
      printf ("Ошибка задания ячейки памяти - недопустимый адрес\n");
      return -1;
    }
  else if (value < 0 || value >= 32767)
    {
      printf ("Ошибка задания ячейки памяти - недопустимое значение\n");
      return -1;
    }

  ram[address] = value;
  return 0;
}