#include <mySimpleComputer.h>

int
sc_memorySave (char *filename)
{
  FILE *file = fopen (filename, "wb");

  if (!file)
    {
      sc_regSet (M, 1);
      return -1;
    }

  for (int i = 0; i < 5; i++)
    {
      if ((cache[i].start_address != -1) && (cache[i].str_change == 1))
        {
          sc_cacheSave (cache[i].start_address);
        }
    }
  if (fwrite (ram, sizeof (int), SIZE, file) != SIZE)
    {
      sc_regSet (M, 1);
      fclose (file);
      return -1;
    }

  sc_regSet (M, 0);
  fclose (file);
  return 0;
}