#include <mySimpleComputer.h>

int
sc_cacheGet (int address, int *value)
{
  int tcounter = 0;
  sc_tcounterGet (&tcounter);
  sc_tcounterSet (tcounter + 1);

  if (address < 0 || address > 127)
    {
      sc_regSet (M, 1);
      return -1;
    }
  int l1_address = (address / 10) * 10;

  int flag = 0;
  while (1)
    {
      for (int i = 0; i < 5; i++)
        {
          if (cache[i].start_address == l1_address)
            {
              *value = cache[i].str[address % 10];
              cache[i].str_time = 0;
              flag = 1;
            }
          else
            {
              cache[i].str_time++;
            }
        }
      if (flag)
        {
          return 0;
        }
      if (sc_cacheLoad (l1_address))
        {
          return -1;
        }
    }
}