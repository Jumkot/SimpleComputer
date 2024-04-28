#include <simpleassembler.h>

int
sa_fileTranslate (char *input_file, char *output_file)
{
  FILE *file_sa = fopen (input_file, "r");

  char error_string[100];
  int error_length = 0;

  if (!file_sa)
    {
      error_length = snprintf (
          error_string, 100, "Ошибка: Файл '%s' не существует.\n", input_file);
      write (1, error_string, error_length);
      return -1;
    }

  for (int i = 0; !feof (file_sa); i++)
    {
      char string[160];
      if (!fgets (string, 160, file_sa))
        {
          if (feof (file_sa))
            {
              break;
            }
          else
            {
              error_length
                  = snprintf (error_string, 100,
                              "Ошибка: невозможно прочитать строку %d\n", i);
              write (1, error_string, error_length);
              return -1;
            }
        }

      char *ptr = strtok (string, " ");
      char *str_address = ptr;
      int address = atoi (str_address);
      if (address < 0 || address > 127)
        {
          error_length = snprintf (
              error_string, 100,
              "Ошибка: неверный адрес ячейки '%d' в строке %d\n", address, i);
          write (1, error_string, error_length);
          return -1;
        }

      ptr = strtok (NULL, " ");
      char *str_command = ptr;

      ptr = strtok (NULL, " +");
      char *str_operand = ptr;

      ptr = strtok (NULL, " ");

      if (ptr != NULL && ptr[0] != ';')
        {
          error_length = snprintf (error_string, 100,
                                    "Ошибка: неверный знак '%c' в строке %d\n",
                                    ptr[0], i);
          write (1, error_string, error_length);
          return -1;
        }

      int operand = atoi (str_operand);
      char buffer[255];
      sprintf (buffer, "%02x", operand);
      sscanf (buffer, "%02x", &operand);

      if (str_command[0] == '=')
        {
          sscanf (str_operand, "%x", &operand);
          sc_memorySet (address, operand);
          continue;
        }
      int command = sa_commandTranslate (str_command);

      int value = 0;
      if (sc_commandEncode (0, command, operand, &value))
        {
          error_length = snprintf (error_string, 100,
                                    "Ошибка кодирования в строке %d\n", i);
          write (1, error_string, error_length);
          return -1;
        }
      sc_memorySet (address, value);
    }

  sc_memorySave (output_file);

  fclose (file_sa);

  return 0;
}