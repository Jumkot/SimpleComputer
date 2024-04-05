#include "myBigChar.h"

int
bc_printbigchar (int *big, int x, int y, enum colors fgcolor,
                 enum colors bgcolor)
{
  mt_setbgcolor (bgcolor);
  mt_setfgcolor (fgcolor);
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
        {
          mt_gotoXY (x + i, y + j);
          int value;
          bc_getbigcharpos (big, i, j, &value);
          if (value)
            {
              bc_printA (ACS_CKBOARD);
            }
          else
            {
              bc_printA (" ");
            }
        }
    }
  mt_setbgcolor (WHITE);
  mt_setfgcolor (BLACK);
  return 0;
}