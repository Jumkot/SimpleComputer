#include <mySimpleComputer.h>

int
sc_memorySet (int address, int value)
{
  if (address < 0 || address >= SIZE || value < 0 || value >= 32767)
    {
      printf ("Ошибка задания ячейки памяти - недопустимый адрес\n");
      return -1;
    }

  ram[address] = value;
  return 0;
}