#include <mySimpleComputer.h>

int
sc_cacheLoad (int address)
{
  int tcounter = 0;
  sc_tcounterGet (&tcounter);
  sc_tcounterSet (tcounter + 9);

  int stop = 0;
  ((address + 10) < SIZE) ? (stop = 10) : (stop = 8);

  int flag = -1;
  for (int i = 0; i < 5; i++)
    {
      if (cache[i].start_address == -1)
        {
          flag = i;
          break;
        }
    }

  if (flag >= 0)
    {
      int value = 0;
      cache[flag].start_address = address;
      for (int i = 0; i < stop; i++)
        {
          sc_memoryGet (address + i, &value);
          cache[flag].str[i] = value;
        }
    }
  else
    {
      int max_time = 0;
      int max_index = -1;
      for (int i = 0; i < 5; i++)
        {
          if (cache[i].str_time > max_time)
            {
              max_time = cache[i].str_time;
              max_index = i;
            }
        }
      if (cache[max_index].str_change)
        {
          sc_cacheSave (address);
        }

      int value = 0;
      cache[max_index].start_address = address;
      for (int i = 0; i < stop; i++)
        {
          sc_memoryGet (address + i, &value);
          cache[max_index].str[i] = value;
          cache[max_index].str_change[i] = 0;
        }
      cache[max_index].str_time = 0;
    }

  return 0;
}