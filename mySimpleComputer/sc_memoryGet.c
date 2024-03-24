#include <mySimpleComputer.h>

int
sc_memoryGet (int address, int *value)
{
  if (address >= 0 && address < SIZE && value)
    {
      *value = ram[address];
      return 0;
    }

  return -1;
}