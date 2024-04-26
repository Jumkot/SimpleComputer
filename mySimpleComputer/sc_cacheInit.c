#include <mySimpleComputer.h>

int
sc_cacheInit ()
{
  for (int i = 0; i < 5; i++)
    {
      cache[i].start_address = -1;
      for (int j = 0; j < 10; j++)
        {
          cache[i].str[j] = 0;
        }
      cache[i].str_change = 0;
      cache[i].str_time = 0;
    }
  return 0;
}