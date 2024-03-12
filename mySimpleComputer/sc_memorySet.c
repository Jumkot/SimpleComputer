#include <mySimpleComputer.h>

int
sc_memorySet (int address, int value)
{
  if (address >= 0 && address < SIZE)
    {
      ram[address] = value;
      return 0;
    }

  printf ("Ошибка задания ячейки памяти - недопустимый адрес\n");
  return -1;
}