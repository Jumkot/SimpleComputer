#include <console.h>

static int history_address[5] = { -1, -1, -1, -1, -1 };
static int history_value[5] = { -1, -1, -1, -1, -1 };
static int history_input[5];

void
printTerm (int address, int input, int update)
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;

  char string[50];
  int length = 0;

  if (update)
    {
      sc_memoryGet (address, &value);
      sc_commandDecode (value, &sign, &command, &operand);

      for (int i = 4; i > 0; i--)
        {
          history_address[i] = history_address[i - 1];
          history_input[i] = history_input[i - 1];
          history_value[i] = history_value[i - 1];
        }
      history_address[0] = address;
      history_input[0] = input;
      history_value[0] = value;
    }

  for (int i = 0; i < 5; i++)
    {
      address = history_address[i];
      sc_memoryGet (history_address[i], &value);
      sc_commandDecode (history_value[i], &sign, &command, &operand);
      if (address < 0)
        {
          continue;
        }

      if (input)
        {
          length = snprintf (string, 50, "%s%x<      ",
                             (address < 16) ? "0" : "", address);
        }
      else
        {
          length = snprintf (string, 50, "%s%x%c %c%.2x%.2x",
                             (address < 16) ? "0" : "", address,
                             (history_input[i]) ? '<' : '>',
                             (sign) ? '-' : '+', command, operand);
        }

      mt_gotoXY (24 - i, 68);
      write (1, string, length);
    }
  mt_gotoXY (26, 1);
}