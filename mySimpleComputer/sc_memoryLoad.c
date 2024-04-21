#include <mySimpleComputer.h>

int
sc_memoryLoad (char *filename)
{
  FILE *file = fopen (filename, "rd");

  int buffer[SIZE];

  if (!file)
    {
      sc_regSet (M, 1);
      return -1;
    }

  if (fread (buffer, sizeof (int), SIZE, file) != SIZE)
    {
      sc_regSet (M, 1);
      fclose (file);
      return -1;
    }
  for (int i = 0; i < SIZE; i++)
    {
      ram[i] = buffer[i];
    }

  sc_regSet (M, 0);
  fclose (file);
  return 0;
}