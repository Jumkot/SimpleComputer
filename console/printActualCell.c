#include <console.h>

void
printActualCell ()
{
  int value;
  sc_memoryGet (actual_cell, &value);

  printCommand ();
  printDecodedCommand (value);
  printBigCell ();
  printCell (actual_cell, BLACK, WHITE);

  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}