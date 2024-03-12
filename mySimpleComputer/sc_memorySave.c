#include <mySimpleComputer.h>

int
sc_memorySave (char *filename)
{
  FILE *file = fopen (filename, "wb");

  if (!file)
    {
      printf ("Ошибка сохранения - не удалось открыть файл\n");
      return -1;
    }
  if (fwrite (ram, sizeof (int), SIZE, file) != SIZE)
    {
      printf ("Ошибка сохранения - не удалось прочитать файл\n");
      fclose (file);
      return 0;
    }

  fclose (file);
  return 0;
}