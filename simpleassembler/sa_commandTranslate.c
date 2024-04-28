#include <simpleassembler.h>

int
sa_commandTranslate (char *command)
{
  int result = 0;
  if (strcmp (command, "NOP") == 0)
    {
      result = 0x00;
    }
  else if (strcmp (command, "CPUINFO") == 0)
    {
      result = 0x01;
    }
  else if (strcmp (command, "READ") == 0)
    {
      result = 0x0A;
    }
  else if (strcmp (command, "WRITE") == 0)
    {
      result = 0x0B;
    }
  else if (strcmp (command, "LOAD") == 0)
    {
      result = 0x14;
    }
  else if (strcmp (command, "STORE") == 0)
    {
      result = 0x15;
    }
  else if (strcmp (command, "ADD") == 0)
    {
      result = 0x1E;
    }
  else if (strcmp (command, "SUB") == 0)
    {
      result = 0x1F;
    }
  else if (strcmp (command, "DIVIDE") == 0)
    {
      result = 0x20;
    }
  else if (strcmp (command, "MUL") == 0)
    {
      result = 0x21;
    }
  else if (strcmp (command, "JUMP") == 0)
    {
      result = 0x28;
    }
  else if (strcmp (command, "JNEG") == 0)
    {
      result = 0x29;
    }
  else if (strcmp (command, "JZ") == 0)
    {
      result = 0x2A;
    }
  else if (strcmp (command, "HALT") == 0)
    {
      result = 0x2B;
    }
  else if (strcmp (command, "NOT") == 0)
    {
      result = 0x33;
    }
  else if (strcmp (command, "JNS") == 0)
    {
      result = 0x37;
    }
  else
    {
      char error_string[80];
      int error_length = snprintf (error_string, 80, "Ошибка: Нераспознанная команда '%s'\n",
                             command);
      write (1, error_string, error_length);
      return -1;
    }
  return result;
}