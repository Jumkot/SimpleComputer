#include <console.h>

void
printAll ()
{
  mt_clrscr ();

  int rows = 0;
  int cols = 0;
  mt_getscreensize (&rows, &cols);

  if (rows < 26 || cols < 108)
    {
      char string[80];
      int length
          = snprintf (string, 80, "Ошибка: недостаточный размер терминала\n");
      write (1, string, length);
      exit (0);
    }

  bc_box (1, 1, 15, 61, WHITE, BLACK, "Оперативная память", RED, BLACK);
  bc_box (1, 62, 3, 23, WHITE, BLACK, "Аккумулятор", RED, BLACK);
  bc_box (4, 62, 3, 23, WHITE, BLACK, "Счётчик  команд", RED, BLACK);
  bc_box (1, 85, 3, 24, WHITE, BLACK, "Регистр  флагов", RED, BLACK);
  bc_box (4, 85, 3, 24, WHITE, BLACK, "Команда", RED, BLACK);
  bc_box (16, 1, 3, 61, WHITE, BLACK, "Редактируемая ячейка (формат)", RED,
          WHITE);
  bc_box (7, 62, 12, 47, WHITE, BLACK, "Редактируемая ячейка (увеличено)", RED,
          WHITE);
  bc_box (19, 1, 7, 66, WHITE, BLACK, "Кеш процессора", GREEN, WHITE);
  bc_box (19, 67, 7, 11, WHITE, BLACK, "IN--OUT", GREEN, WHITE);
  bc_box (19, 78, 7, 31, WHITE, BLACK, "Клавиши", GREEN, WHITE);
  mt_gotoXY (26, 1);

  for (int i = 0; i < SIZE; i++)
    {
      int value;
      sc_commandEncode (0, i, i, &value);
      sc_memoryGet (i, &value);
      printCell (i, WHITE, BLACK);
      printDecodedCommand (value);
      printBigCell ();
      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
    }
  mt_setdefaultcolor ();
}