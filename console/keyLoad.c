#include <console.h>

void
keyLoad ()
{
  char message[70];
  int length = snprintf (message, 70, "Введите имя файла для загрузки: ");
  mt_gotoXY (26, 1);
  write (1, message, length);
  mt_gotoXY (26, 33);
  mt_setbgcolor (GREEN);
  write (1, " ", 1);
  mt_setdefaultcolor ();

  char filename[35] = { 0 };
  scanf ("%34s", filename);

  if (access (filename, F_OK) == -1)
    {
      char string[100];
      int length = snprintf (string, 100, "Ошибка: Файл '%s' не существует.\n",
                             filename);
      printAll ();
      mt_gotoXY (26, 1);
      write (1, string, length);
      exit (0);
    }
  else
    {
      sc_memoryLoad (filename);
      rk_mytermrestore ();

      for (int i = 0; i < SIZE; i++)
        {
          int value;
          sc_commandEncode (0, i, i, &value);
          sc_memoryGet (i, &value);
          printCell (i, WHITE, BLACK);
        }
      mt_delline ();
      printAll ();
    }
}