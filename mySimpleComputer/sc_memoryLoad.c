#include <mySimpleComputer.h>

int
sc_memoryLoad (char *filename)
{
  FILE *file = fopen (filename, "rd");

  int buffer[SIZE];

  if (!file)
    {
      return -1;
    }

  if (fread (buffer, sizeof (int), SIZE, file) != SIZE)
    {
      fclose (file);
      return -1;
    }
  for (int i = 0; i < SIZE; i++)
    {
      ram[i] = buffer[i];
    }

  fclose (file);
  return 0;
}