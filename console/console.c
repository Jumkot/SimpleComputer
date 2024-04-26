#include <console.h>

void
console ()
{
  mt_clrscr ();

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
  printTerm (-1, -1, 0, 0);

  for (int i = 0; i < SIZE; i++)
    {
      int value;
      sc_commandEncode (0, i, i, &value);
      sc_memoryGet (i, &value);
      printCell (i, WHITE, BLACK);
    }
  printAll ();

  enum keys key = NONE;

  while (key != EXIT)
    {
      int count = 0;

      int value = 0;
      sc_regGet (T, &value);
      if (value)
        {
          if (tcgetattr (STDOUT_FILENO, &saved) != 0)
            {
              return;
            }
          rk_mytermsave ();
          if (rk_mytermregime (0, 1, 1, 0, 0) != 0)
            {
              return;
            }
          rk_readkey (&key);
          rk_mytermrestore ();

          mt_clrstr ();
          printAll ();

          int read_value[5];
          int y = 0;
          int x = 0;

          switch (key)
            {
            case EDIT:
              y = actual_cell % 10 * 6 + 2;
              x = actual_cell / 10 + 2;
              mt_gotoXY (x, y);

              sc_regSet (T, 0);
              rk_readvalue (read_value, 0);
              sc_cacheSet (actual_cell, *read_value);
              sc_regSet (T, 1);

              printActualCell ();
              break;
            case F5:
              mt_gotoXY (2, 68);
              if (!(rk_readvalue (read_value, 0)))
                {
                  sc_accumulatorSet (*read_value);
                  printAccumulator ();
                };
              break;
            case F6:
              mt_gotoXY (5, 77);
              if (!(rk_readvalue (read_value, 0)))
                {
                  sc_icounterSet (*read_value);
                  printCounters ();
                }
              break;
            case UP:
              last_cell = actual_cell;
              if (actual_cell < 8)
                {
                  actual_cell += 120;
                }
              else if (actual_cell < 10)
                {
                  actual_cell += 110;
                }
              else
                {
                  actual_cell -= 10;
                }
              break;
            case DOWN:
              last_cell = actual_cell;
              if (actual_cell > 119)
                {
                  actual_cell -= 120;
                }
              else if (actual_cell == 118 || actual_cell == 119)
                {
                  actual_cell -= 110;
                }
              else
                {
                  actual_cell += 10;
                }
              break;
            case RIGHT:
              last_cell = actual_cell;
              if (actual_cell % 10 == 9)
                {
                  actual_cell -= 9;
                }
              else if (actual_cell == 127)
                {
                  actual_cell = 120;
                }
              else
                {
                  actual_cell++;
                }
              break;
            case LEFT:
              last_cell = actual_cell;
              if (actual_cell == 120)
                {
                  actual_cell = 127;
                }
              else if (actual_cell % 10 == 0)
                {
                  actual_cell += 9;
                }
              else
                {
                  actual_cell--;
                }
              break;
            case LOAD_KEY:
              keyLoad ();
              break;
            case SAVE:
              IRC (SIGUSR2);
              keySave ();
              break;
            case RESET:
              IRC (SIGUSR1);
              sc_icounterGet (&count);
              break;
            case RUN:
              sc_regSet (T, 0);
              sc_icounterGet (&count);
              last_cell = actual_cell;
              actual_cell = count;
              break;
            case STEP:
              sc_regSet (T, 0);
              IRC (SIGALRM);
              sc_regSet (T, 1);
              sc_icounterGet (&count);
              last_cell = actual_cell;
              actual_cell = count;
              break;
            case EXIT:
              mt_gotoXY (27, 1);
              IRC (SIGALRM);
              exit (0);
            default:
              break;
            }
        }
      else
        {
          pause ();
          sc_icounterGet (&count);
          last_cell = actual_cell;
          actual_cell = count;
        }
      printAll ();
    }
}