#include "mySimpleComputer.h"

int
sc_memorySet (int address, int value)
{
  if (address >= 0 && address < SIZE)
    {
      ram[address] = value;
      if (ram[address] == value)
        {
          return 0;
        }
    }
  return -1;
}