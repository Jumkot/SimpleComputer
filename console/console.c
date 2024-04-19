#include <console.h>

int
main (int argc, char *argv[])
{
  keyReset ();

  /////////////////
  // Задание значений RAM счётчиком по порядку
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
  ////////////////

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

  enum keys key = NONE;

  while (key != EXIT)
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

      int input_flag = 0;
      int value[5];
      int y = 0;
      int x = 0;

      switch (key)
        {
        case EDIT:
          y = actual_cell % 10 * 6 + 2;
          x = actual_cell / 10 + 2;
          mt_gotoXY (x, y);
          if (!(rk_readvalue (value, 0)))
            {
              sc_memorySet (actual_cell, *value);
              input_flag = 1;
            }
          break;
        case F5:
          mt_gotoXY (2, 68);
          if (!(rk_readvalue (value, 0)))
            {
              sc_accumulatorSet (*value);
            };
          break;
        case F6:
          mt_gotoXY (5, 77);
          if (!(rk_readvalue (value, 0)))
            {
              sc_icounterSet (*value);
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
        case LOAD:
          keyLoad ();
          break;
        case SAVE:
          IRC(SIGUSR2);
          keySave ();
          break;
        case RESET:
          IRC(SIGUSR1);
          break;
        case RUN:
          break;
        case STEP:
          CU ();
          break;
        case EXIT:
          mt_gotoXY (27, 1);
          IRC (SIGALRM);
          exit (0);
        default:
          break;
        }

      printAll ();
      printTerm (actual_cell, input_flag);
    }

  return 0;
}