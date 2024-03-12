#include <console.h>

void
printCounters (void)
{
  int value = 0;

  sc_icounterGet (&value);

  printf ("Счётчик команд: +%.4x\n", value);
}