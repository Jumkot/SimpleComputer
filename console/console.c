#include <console.h>

int
main (int argc, char *argv[])
{
  signal (SIGALRM, IRC);
  signal (SIGUSR1, IRC);
  signal (SIGUSR2, IRC);

  IRC (SIGUSR1);

  /////////////////
  int value;
  for (int i = 0; i < SIZE; i++)
    {
      int value;
      sc_commandEncode (1, 0, 0, &value);
      sc_memorySet (i, value);
      printCell (i, WHITE, BLACK);

      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
    }
  sc_commandEncode (0, 1, 0, &value);
  sc_memorySet (0, value);

  sc_commandEncode (0, 40, 120, &value);
  sc_memorySet (1, value);

  sc_commandEncode (0, 10, 120, &value);
  sc_memorySet (120, value);

  sc_commandEncode (0, 11, 120, &value);
  sc_memorySet (121, value);

  sc_commandEncode (0, 40, 61, &value);
  sc_memorySet (122, value);

  sc_commandEncode (0, 43, 61, &value);
  sc_memorySet (61, value);
  /////////////////

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

  mt_clrscr ();
  printAll ();

  enum keys key = NONE;
  actual_cell = 0;

  while (key != EXIT)
    {
      int count = 0;

      int value = 0;
      sc_regGet (T, &value);
      if (value)
        {
          if (tcgetattr (STDOUT_FILENO, &saved) != 0)
            {
              return -1;
            }
          rk_mytermsave ();
          if (rk_mytermregime (0, 1, 1, 0, 0) != 0)
            {
              return -1;
            }
          rk_readkey (&key);
          rk_mytermrestore ();

          mt_clrscr ();
          printAll ();

          input_flag = 0;
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
                  input_flag = 1;
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
              printAll ();
              IRC (SIGALRM);
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
          sc_icounterGet (&count);
          actual_cell = count;
          printAll ();
          IRC (SIGALRM);
        }
    }

  return 0;
}