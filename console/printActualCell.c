#include <console.h>

void
printActualCell ()
{
  int value;
  sc_memoryGet (actual_cell, &value);

  printDecodedCommand (value);
  printBigCell ();
  printCell (actual_cell, BLACK, WHITE);
  printCell (last_cell, WHITE, BLACK);

  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}