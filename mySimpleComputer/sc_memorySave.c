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