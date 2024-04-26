#include <console.h>

void
IRC (int signum)
{
  int tcounter = 0;
  sc_tcounterGet (&tcounter);
  if (signum == SIGALRM)
    {
      int value = 0;
      sc_regGet (T, &value);
      if (value)
        {
          return;
        }
      (tcounter == 0) ? CU () : sc_tcounterSet (tcounter - 1);
    }
  else if (signum == SIGUSR1)
    {
      sc_memoryInit ();
      sc_accumulatorInit ();
      sc_icounterInit ();
      sc_tcounterInit ();
      sc_regInit ();
      sc_regSet (T, 1);
      sc_cacheInit ();
      actual_cell = 0;
      last_cell = 127;
    }
  else if (signum == SIGUSR2)
    {
      (tcounter == 0) ? CU () : sc_tcounterSet (tcounter - 1);
    }
}