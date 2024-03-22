#include <myTerm.h>

int
mt_getscreensize (int *rows, int *cols)
{

  if (!(rows) || !(cols))
    {
      return -1;
    }

  struct winsize screen_size;

  if (ioctl (1, TIOCGWINSZ, &screen_size) != 0)
    {
      return -1;
    }
  *rows = screen_size.ws_row;
  *cols = screen_size.ws_col;

  return 0;
}