#include <console.h>

void
printBoxes ()
{
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

  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}