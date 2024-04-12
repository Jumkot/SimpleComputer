#include <mySimpleComputer.h>
#include <stdlib.h>

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
  int value = KEY_SIZE - 1;

  while (key != EXIT)
    {
      rk_readvalue (&value, 1);
      rk_readkey (&key);

      int input_flag = 0;

      switch (key)
        {
        case F5:
          keyF5 ();
          break;
        case F6:
          keyF6 ();
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
          keySave ();
          break;
        case RESET:
          keyReset ();
          break;
        case RUN:
          break;
        case STEP:
          break;
        case EDIT:
          keyEdit ();
          input_flag = 1;
          break;
        case EXIT:
          mt_gotoXY (27, 1);
          exit (0);
        default:
          break;
        }

      printAll ();
      printTerm (actual_cell, input_flag);
    }

  return 0;
}