#include <mySimpleComputer.h>

int
sc_memoryLoad (char *filename)
{
  FILE *file = fopen (filename, "rd");

  int buffer[SIZE];

  if (!file)
    {
      printf ("Ошибка загрузки - не удалось открыть файл\n");
      return -1;
    }

  if (fread (buffer, sizeof (int), SIZE, file) != SIZE)
    {
      printf ("Ошибка загрузки - не удалось записать в файл\n");
      fclose (file);
      return 0;
    }
  for (int i = 0; i < SIZE; i++)
    {
      ram[i] = buffer[i];
    }

  fclose (file);
  return 0;
}