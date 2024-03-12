#include <mySimpleComputer.h>

int
main ()
{
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  for (int i = 0; i < 25; i++)
    {
      sc_memorySet (i, i + 1);
    }
  for (int i = 0; i < 26; i++)
    {
      printCell (i);
    }
  printf ("\n");

  printf ("%d\n\n", sc_memorySet (25, -2));

  sc_regSet (P, 1);
  sc_regSet (T, 1);
  printFlags ();
  printf ("\n");

  printf ("%d\n\n", sc_regSet (P, -2));

  sc_icounterSet (100);
  printCounters ();
  printf ("\n");

  printf ("%d\n\n", sc_icounterSet (-2));

  int value = 0;
  sc_commandEncode (0, 0x32, 1, &value);
  printDecodedCommand (value);

  return 0;
}