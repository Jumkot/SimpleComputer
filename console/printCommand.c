#include <console.h>

void
printCommand (void)
{
  int value = 0;
  sc_icounterGet (&value);

  int sign = 0;
  int command = 0;
  int operand = 0;
  char string[50];

  sc_commandDecode (value, &sign, &command, &operand);

  if (sc_commandDecode (value, &sign, &command, &operand) != 0)
    {
      int length = snprintf (string, 50, "! + FF : FF");
      mt_gotoXY (5, 92);
      write (1, string, length);
    }
  else
    {
      if (command > 15)
        {
          int length
              = snprintf (string, 50, "%c 00 : %2.x", (sign) ? '-' : '+', command);
          mt_gotoXY (5, 94);
          write (1, string, length);
        }
      else
        {
          int length = snprintf (string, 50, "%c 00 : %s%1.x", (sign) ? '-' : '+',
                                "0", command);
          mt_gotoXY (5, 94);
          write (1, string, length);
        }
    }
}