#include <console.h>

void
console ()
{
  mt_clrscr ();
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

          mt_clrscr ();
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
              if (!(rk_readvalue (read_value, 0)))
                {
                  sc_memorySet (actual_cell, *read_value);
                  printAccumulator ();
                }
              break;
            case F5:
              mt_gotoXY (2, 68);
              if (!(rk_readvalue (read_value, 0)))
                {
                  sc_accumulatorSet (*read_value);
                };
              break;
            case F6:
              mt_gotoXY (5, 77);
              if (!(rk_readvalue (read_value, 0)))
                {
                  sc_icounterSet (*read_value);
                }
              break;
            case UP:
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
              actual_cell = count;
              break;
            case RUN:
              sc_regSet (T, 0);
              sc_icounterGet (&count);
              actual_cell = count;
              break;
            case STEP:
              CU ();
              sc_icounterGet (&count);
              actual_cell = count;
              break;
            case EXIT:
              mt_gotoXY (27, 1);
              IRC (SIGALRM);
              exit (0);
            default:
              break;
            }
          printAll ();
        }
      else
        {
          pause ();
          sc_icounterGet (&count);
          actual_cell = count;
        }
    }
}