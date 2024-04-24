#ifndef MYTERM_H
#define MYTERM_H

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

enum colors
{
  BLACK = 16,
  RED = 1,
  GREEN = 2,
  YELLOW = 3,
  BLUE = 4,
  PURPLE = 5,
  CYAN = 6,
  WHITE = 7
};

int mt_clrscr (void);
int mt_clrstr (void);
int mt_gotoXY (int string, int column);
int mt_getscreensize (int *rows, int *cols);
int mt_setfgcolor (enum colors);
int mt_setbgcolor (enum colors);
int mt_setdefaultcolor (void);
int mt_setcursorvisible (int value);
int mt_delline (void);

#endif