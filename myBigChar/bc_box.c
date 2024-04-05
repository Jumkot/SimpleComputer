#include "myBigChar.h"

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  mt_setfgcolor (box_fg);
  mt_setbgcolor (box_bg);

  mt_gotoXY (x1, y1);
  bc_printA (L_UP);
  for (int i = 0; i < y2 - 2; i++)
    {
      bc_printA (HORZ);
    }
  bc_printA (R_UP);

  for (int i = 1; i <= x2 - 2; i++)
    {
      mt_gotoXY (x1 + i, y1);
      bc_printA (VERT);
      mt_gotoXY (x1 + i, y1 + y2 - 1);
      bc_printA (VERT);
    }

  mt_gotoXY (x1 + x2 - 1, y1);
  bc_printA (L_BTM);
  for (int i = 0; i < y2 - 2; i++)
    {
      bc_printA (HORZ);
    }
  bc_printA (R_BTM);

  if (bc_strlen (header))
    {
      mt_setfgcolor (header_fg);
      mt_setbgcolor (header_bg);

      char header_print[100];
      int length
          = snprintf (header_print, strlen (header) + 3, " %s ", header);

      if (*header & 128)
        {
          length = length / 2 + 1;
        }
      int header_y = y1 + (y2 / 2) - length / 2;
      mt_gotoXY (x1, header_y);
      bc_printA (header_print);
    }

  mt_setdefaultcolor ();
  return 0;
}