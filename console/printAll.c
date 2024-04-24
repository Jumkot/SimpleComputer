#include <console.h>

void
printAll ()
{
  printActualCell ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printCommand ();
  printTerm (-1, 0, 0);

  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}