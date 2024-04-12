#include <mySimpleComputer.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

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
  int value = KEY_SIZE - 1;

  actual_cell = 0;

  while (key != EXIT)
    {
      rk_readvalue (&value, 1);
      rk_readkey (&key);

      char string[10];
      int length = 0;
      switch (key)
        {
        case F5:
          mt_gotoXY (26, 1);
          length = snprintf (string, 10, "%d!", key);
          write (1, string, length);
          break;
        case F6:
          mt_gotoXY (26, 1);
          length = snprintf (string, 10, "%d!", key);
          write (1, string, length);
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
          mt_gotoXY (26, 1);
          length = snprintf (string, 10, "%d!", key);
          write (1, string, length);
          break;
        case SAVE:
          mt_gotoXY (26, 1);
          length = snprintf (string, 10, "%d!", key);
          write (1, string, length);
          break;
        case RESET:
          mt_gotoXY (26, 1);
          length = snprintf (string, 10, "%d!", key);
          write (1, string, length);
          break;
        case RUN:
          mt_gotoXY (26, 1);
          length = snprintf (string, 10, "%d!", key);
          write (1, string, length);
          break;
        case STEP:
          mt_gotoXY (26, 1);
          length = snprintf (string, 10, "%d!", key);
          write (1, string, length);
          break;
        case EDIT:
          mt_gotoXY (26, 1);
          length = snprintf (string, 10, "%d!", key);
          write (1, string, length);
          break;
        case EXIT:
          mt_gotoXY (27, 1);
          exit (0);
        default:
          break;
        }

      printAll ();
    }

  return 0;
}