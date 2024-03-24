#include <mySimpleComputer.h>

int
sc_memorySave (char *filename)
{
  FILE *file = fopen (filename, "wb");

  if (!file)
    {
      return -1;
    }
  if (fwrite (ram, sizeof (int), SIZE, file) != SIZE)
    {
      fclose (file);
      return -1;
    }

  fclose (file);
  return 0;
}