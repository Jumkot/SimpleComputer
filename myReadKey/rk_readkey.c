#include <myReadKey.h>

int
rk_readkey (enum keys *key)
{
  *key = NONE;

  for (int i = 0; i < 5; i++)
    {
      read (STDOUT_FILENO, &key_value[i], 1);
      if (i == 0)
        {
          if (!((key_value[i] == '-') || (key_value[i] == '+')
                || (key_value[i] == '1') || (key_value[i] == '2')
                || (key_value[i] == '3') || (key_value[i] == '4')
                || (key_value[i] == '5') || (key_value[i] == '6')
                || (key_value[i] == '7') || (key_value[i] == '8')
                || (key_value[i] == '9') || (key_value[i] == '0')
                || (key_value[i] == 'a') || (key_value[i] == 'a')
                || (key_value[i] == 'b') || (key_value[i] == 'c')
                || (key_value[i] == 'd') || (key_value[i] == 'e')
                || (key_value[i] == 'f') || (key_value[i] == 'l')
                || (key_value[i] == 's') || (key_value[i] == 'i')
                || (key_value[i] == 'r') || (key_value[i] == 't')
                || (key_value[i] == '\E') || (key_value[i] == '\n')
                || (key_value[i] == '\r')))
            {
              rk_mytermrestore ();
              return -1;
            }
          if (key_value[i] != '\E')
            {
              break;
            }
        }
      else if (i == 1)
        {
          if (!((key_value[i] == '[') || (key_value[i] == '\E')))
            {
              rk_mytermrestore ();
              return -1;
            }
          if (key_value[i] == '\E')
            {
              break;
            }
        }
      else if (i == 2)
        {
          if (!((key_value[i] == '1') || (key_value[i] == 'A')
                || (key_value[i] == 'B') || (key_value[i] == 'C')
                || (key_value[i] == 'D')))
            {
              rk_mytermrestore ();
              return -1;
            }
          if (key_value[i] != '1')
            {
              break;
            }
        }
      else if (i == 3)
        {
          if (!((key_value[i] == '5') || (key_value[i] == '7')))
            {
              rk_mytermrestore ();
              return -1;
            }
        }
      else if (i == 4)
        {
          if (key_value[i] != '~')
            {
              rk_mytermrestore ();
              return -1;
            }
        }
      key_value[i + 1] = '\0';
    }

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
      *key = LOAD_KEY;
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
  else if (!(strncmp (key_value, "+", 1)))
    {
      *key = PLUS;
    }
  else if (!(strncmp (key_value, "-", 1)))
    {
      *key = MINUS;
    }
  else if (!(strncmp (key_value, "a", 1)))
    {
      *key = A_KEY;
    }
  else if (!(strncmp (key_value, "b", 1)))
    {
      *key = B_KEY;
    }
  else if (!(strncmp (key_value, "c", 1)))
    {
      *key = C_KEY;
    }
  else if (!(strncmp (key_value, "d", 1)))
    {
      *key = D_KEY;
    }
  else if (!(strncmp (key_value, "e", 1)))
    {
      *key = E_KEY;
    }
  else if (!(strncmp (key_value, "f", 1)))
    {
      *key = F_KEY;
    }
  else if (!(strncmp (key_value, "0", 1)))
    {
      *key = ZERO;
    }
  else if (!(strncmp (key_value, "1", 1)))
    {
      *key = ONE;
    }
  else if (!(strncmp (key_value, "2", 1)))
    {
      *key = TWO;
    }
  else if (!(strncmp (key_value, "3", 1)))
    {
      *key = THREE;
    }
  else if (!(strncmp (key_value, "4", 1)))
    {
      *key = FOUR;
    }
  else if (!(strncmp (key_value, "5", 1)))
    {
      *key = FIVE;
    }
  else if (!(strncmp (key_value, "6", 1)))
    {
      *key = SIX;
    }
  else if (!(strncmp (key_value, "7", 1)))
    {
      *key = SEVEN;
    }
  else if (!(strncmp (key_value, "8", 1)))
    {
      *key = EIGHT;
    }
  else if (!(strncmp (key_value, "9", 1)))
    {
      *key = NINE;
    }
  else if (!(strncmp (key_value, "\n", 1)) || !(strncmp (key_value, "\r", 1)))
    {
      *key = EDIT;
    }
  else if (!(strncmp (key_value, "\E\E", 1)))
    {
      *key = EXIT;
    }

  return 0;
}