#include <console.h>

void
IRC (int signum)
{
  if (signum == SIGALRM)
    {
      int value = 0;
      sc_regGet (T, &value);
      if (value)
        {
          return;
        }
      (idle_tact_counter == 0) ? CU ()
                               : sc_icounterSet (idle_tact_counter - 1);
    }
  else if (signum == SIGUSR1)
    {
      sc_memoryInit ();
      sc_accumulatorInit ();
      sc_icounterInit ();
      sc_tcounterInit ();
      sc_regInit ();
      sc_regSet (T, 1);
      actual_cell = 0;
      last_cell = 127;
    }
  else if (signum == SIGUSR2)
    {
      (idle_tact_counter == 0) ? CU ()
                               : sc_icounterSet (idle_tact_counter - 1);
    }
}