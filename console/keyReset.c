#include <console.h>

void
keyReset ()
{
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_tcounterInit ();
  sc_regInit ();
  sc_regSet (T, 1);
  IRC(SIGUSR1);
  actual_cell = 0;
  printAll ();
}