#include <mySimpleComputer.h>

int
sc_cacheSave (int address)
{
  if (address == -1)
    {
      return -1;
    }

  int stop = 0;
  ((address + 10) < SIZE) ? (stop = 10) : (stop = 8);

  int index = -1;
  for (int i = 0; i < 5; i++)
    {
      if (cache[i].start_address == address)
        {
          index = i;
        }
    }

  for (int i = 0; i < stop; i++)
    {
      if (cache[index].str_change[i])
        {
          int value = cache[index].str[i];
          sc_memorySet (address + i, value);  
        }
    }

  return 0;
}