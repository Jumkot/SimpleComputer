#include <mySimpleComputer.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  // mt_clrscr ();

  // int rows = 0;
  // int cols = 0;
  // mt_getscreensize (&rows, &cols);

  // if (rows < 26 || cols < 108)
  //   {
  //     char string[80];
  //     int length
  //         = snprintf (string, 80, "Ошибка: недостаточный размер
  //         терминала\n");
  //     write (1, string, length);
  //     exit (0);
  //   }

  int count_load;

  const char *load_filename;
  if (argc > 1)
    {
      load_filename = argv[1];
    }
  else
    {
      load_filename = "font.bin";
    }
  if (access (load_filename, F_OK) == -1)
    {
      char string[80];
      int length = snprintf (string, 80, "Ошибка: Файл '%s' не существует.\n",
                             load_filename);
      write (1, string, length);
      exit (0);
    }

  int file = open (load_filename, O_RDONLY);
  bc_bigcharread (file, big_load, 18, &count_load);
  close (file);

  printAll ();

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
      printCounters ();
      printBigCell ();
      mt_setdefaultcolor ();
      printTerm (i, 0);
      printCommand ();
      mt_gotoXY (26, 1);
      sleep (1);
    }

  return 0;
}