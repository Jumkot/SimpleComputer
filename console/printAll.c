#include <console.h>

void
printAll ()
{
  printActualCell ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printCommand ();
  printCache ();

  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}