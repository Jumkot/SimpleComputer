#include <mySimpleComputer.h>

int
sc_memoryLoad (char *filename)
{
  FILE *file = fopen (filename, "rd");

  if (!file)
    {
      printf ("Ошибка загрузки - не удалось открыть файл\n");
      return -1;
    }
  if (fread (ram, sizeof (int), SIZE, file) != SIZE)
    {
      printf ("Ошибка загрузки - не удалось записать в файл\n");
      fclose (file);
      return 0;
    }

  fclose (file);
  return 0;
}