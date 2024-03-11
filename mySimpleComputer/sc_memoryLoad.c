#include "mySimpleComputer.h"

int
sc_memoryLoad (char *filename)
{
  FILE *file;

  if (!(file = fopen (filename, "rd")))
    {
      return -1;
    }
  fread (ram, sizeof (int), SIZE, file);

  fclose (file);
  return 0;
}