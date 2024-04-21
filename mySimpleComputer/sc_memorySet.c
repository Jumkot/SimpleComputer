#include <mySimpleComputer.h>

int
sc_memorySet (int address, int value)
{
  if (address < 0 || address >= SIZE || value < 0 || value >= 32767)
    {
      sc_regSet(P, 1);
      return -1;
    }

  sc_regSet(0, 1);
  ram[address] = value;
  return 0;
}