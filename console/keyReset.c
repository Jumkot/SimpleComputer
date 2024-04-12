#include <console.h>

void
keyReset ()
{
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();
  actual_cell = 0;
  printAll ();
}