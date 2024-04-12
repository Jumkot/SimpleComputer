#include <console.h>

void
keySave ()
{
  char message[70];
  int length = snprintf (message, 70, "Введите имя файла для сохранения: ");
  mt_gotoXY (26, 1);
  write (1, message, length);
  mt_gotoXY (26, 35);
  mt_setbgcolor (GREEN);
  write (1, " ", 1);
  mt_setdefaultcolor ();

  char filename[35] = { 0 };
  scanf ("%34s", filename);
  sc_memorySave (filename);
  rk_mytermsave ();
  printAll ();
}