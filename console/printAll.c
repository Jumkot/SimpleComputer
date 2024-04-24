#include <console.h>

void
printAll ()
{
  printActualCell ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printCommand ();

  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}