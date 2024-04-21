#include <console.h>

void
printCommand (void)
{
  int icounter = 0;
  sc_icounterGet (&icounter);

  int value = 0;
  sc_memoryGet (icounter, &value);
  int sign = 0;
  int command = 0;
  int operand = 0;
  char string[50];

  if (sc_commandDecode (value, &sign, &command, &operand) != 0)
    {
      int length = snprintf (string, 50, "! + FF : FF");
      mt_gotoXY (5, 92);
      write (1, string, length);
    }
  else
    {
      int length = snprintf (string, 50, "%c 00 : %s%x", (sign) ? '-' : '+',
                             (command > 15) ? "" : "0", command);
      mt_gotoXY (5, 94);
      write (1, string, length);
    }
}