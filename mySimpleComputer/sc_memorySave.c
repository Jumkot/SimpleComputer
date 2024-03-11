#include "mySimpleComputer.h"

int
sc_memorySave (char *filename)
{
  FILE *file;
  if (!(file = fopen (filename, "wb")))
    {
      return -1;
    }
  fwrite (ram, sizeof (int), SIZE, file);

  fclose (file);
  return 0;
}