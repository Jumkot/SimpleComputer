#include <console.h>

void
printCache ()
{
  for (int i = 0; i < 5; i++)
    {
      char clear[16];
      int clear_length = snprintf (clear, 16, "\t");
      mt_gotoXY (20 + i, 2);
      write (1, clear, clear_length);

      if (cache[i].start_address != -1)
        {
          int stop = 0;
          ((cache[i].start_address + 10) < SIZE) ? (stop = 10) : (stop = 8);

          char address_print[6];
          int length = snprintf (
              address_print, 6,
              "%s%s%d: ", (cache[i].start_address >= 100) ? "" : "0",
              (cache[i].start_address != 0) ? "" : "0", cache[i].start_address);
          mt_gotoXY (20 + i, 2);
          write (1, address_print, 6);

          for (int j = 0; j < stop; j++)
            {
              int sign = 0;
              int command = 0;
              int operand = 0;
              sc_commandDecode (cache[i].str[j], &sign, &command, &operand);

              char string[6];
              length = snprintf (string, 6, "%c%.2x%.2x", (sign) ? '-' : '+',
                                 command, operand);

              int y = 7 * (j + 1) - j;
              int x = 20 + i;
              mt_gotoXY (x, y);
              write (1, string, length);
            }
        }
      else
        {
          char empty[5] = "-01:\0";
          mt_gotoXY (20 + i, 2);
          write (1, empty, 5);
        }
    }

  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}