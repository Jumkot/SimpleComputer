#include <myReadKey.h>

int
rk_readkey (enum keys *key)
{
  *key = NONE;
  if (!(strncmp (key_value, "\E[15~", 5)))
    {
      *key = F5;
    }
  else if (!(strncmp (key_value, "\E[17~", 5)))
    {
      *key = F6;
    }
  else if (!(strncmp (key_value, "\E[A", 3)))
    {
      *key = UP;
    }
  else if (!(strncmp (key_value, "\E[B", 3)))
    {
      *key = DOWN;
    }
  else if (!(strncmp (key_value, "\E[C", 3)))
    {
      *key = RIGHT;
    }
  else if (!(strncmp (key_value, "\E[D", 3)))
    {
      *key = LEFT;
    }
  else if (!(strncmp (key_value, "l", 1)))
    {
      *key = LOAD;
    }
  else if (!(strncmp (key_value, "s", 1)))
    {
      *key = SAVE;
    }
  else if (!(strncmp (key_value, "i", 1)))
    {
      *key = RESET;
    }
  else if (!(strncmp (key_value, "r", 1)))
    {
      *key = RUN;
    }
  else if (!(strncmp (key_value, "t", 1)))
    {
      *key = STEP;
    }
  else if (!(strncmp (key_value, "\n", 1)) || !(strncmp (key_value, "\r", 1)))
    {
      *key = EDIT;
    }
  else if (!(strncmp (key_value, "\E", 1)))
    {
      *key = EXIT;
    }

  return 0;
}