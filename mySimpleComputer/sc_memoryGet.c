#include <mySimpleComputer.h>

int
sc_memoryGet (int address, int *value)
{
  if (address >= 0 && address < SIZE && value)
    {
      sc_regSet(M, 0);
      *value = ram[address];
      return 0;
    }

  sc_regSet(M, 1);
  return -1;
}