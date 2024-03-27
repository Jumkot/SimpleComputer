#include <mySimpleComputer.h>
#include <stdlib.h>

int
main ()
{
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  mt_clrscr ();

  int rows = 0;
  int cols = 0;
  mt_getscreensize (&rows, &cols);

  if (rows < 26 || cols < 108)
    {
      char string[80];
      int length = snprintf (string, 80, "Ошибка: недостаточный размер терминала\n");
      write (1, string, length);
      exit (0);
    }

  for (int i = 0; i < SIZE; i++)
    {
      int value;
      sc_commandEncode (0, i, i, &value);
      sc_memorySet (i, value);
      printCell (i, WHITE, BLACK);

      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
    }

  for (int i = 0; i < SIZE; i++)
    {
      printCell (i, GREEN, BLACK);
      printCell (i - 1, WHITE, BLACK);

      int value;
      sc_memoryGet (i, &value);
      sc_icounterSet (value);

      printDecodedCommand (value);
      printTerm (i, 0);
      printCommand ();

      sleep (1);
    }

  return 0;
}