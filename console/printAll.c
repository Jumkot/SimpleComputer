#include <console.h>

void
printAll ()
{

  int rows = 0;
  int cols = 0;
  mt_getscreensize (&rows, &cols);

  if (rows < 26 || cols < 108)
    {
      char string[80];
      int length
          = snprintf (string, 80, "Ошибка: недостаточный размер терминала\n");
      write (1, string, length);
      exit (0);
    }

  printBoxes ();
  printKeys ();

  for (int i = 0; i < SIZE; i++)
    {
      int value;
      sc_commandEncode (0, i, i, &value);
      sc_memoryGet (i, &value);
      printCell (i, WHITE, BLACK);
    }
  printActualCell ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printCommand ();
  printTerm (-1, 0, 0);

  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}