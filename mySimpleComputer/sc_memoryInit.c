#include <mySimpleComputer.h>

int
sc_memoryInit (void)
{
  for (int i = 0; i < SIZE; i++)
    {
      ram[i] = 0;
    }

  return 0;
}