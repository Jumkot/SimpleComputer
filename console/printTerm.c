#include <console.h>

static int history_address[5] = { -1, -1, -1, -1, -1 };
static int history_value[5] = { -1, -1, -1, -1, -1 };
static int history_input[5];

void
printTerm (int address, int value, int input, int update)
{
  int sign = 0;
  int command = 0;
  int operand = 0;

  char string[50];
  int length = 0;

  if (input && !(update))
    {
      if (history_address[0] >= 0)
        {
          for (int i = 0; i < 4; i++)
            {
              int h_address = history_address[i];
              sc_commandDecode (history_value[i], &sign, &command, &operand);
              if (h_address < 0)
                {
                  continue;
                }

              length = snprintf (string, 50, "%.2x%c %c%.2x%.2x", h_address,
                                 (history_input[i]) ? '<' : '>',
                                 (sign) ? '-' : '+', command, operand);

              mt_gotoXY (24 - (i + 1), 68);
              write (1, string, length);
            }
        }
      length = snprintf (string, 50, "         ");
      mt_gotoXY (24, 68);
      write (1, string, length);

      length = snprintf (string, 50, "%.2x< ", address);
      mt_gotoXY (24, 68);
      write (1, string, length);

      return;
    }

  if (update)
    {
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
      sc_commandDecode (history_value[i], &sign, &command, &operand);
      if (address < 0)
        {
          continue;
        }

      length = snprintf (string, 50, "%.2x%c %c%.2x%.2x", address,
                         (history_input[i]) ? '<' : '>', (sign) ? '-' : '+',
                         command, operand);

      mt_gotoXY (24 - i, 68);
      write (1, string, length);
    }
  mt_gotoXY (26, 1);
}