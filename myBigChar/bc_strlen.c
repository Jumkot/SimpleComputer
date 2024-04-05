#include "myBigChar.h"

int
bc_strlen (char *str)
{
  int len = 0;
  char *tmp = str;

  while (*tmp != '\0')
    {
      if (!(*tmp & 128))
        {
          len += 1;
          tmp += 1;
        }
      else if ((*tmp & 224) == 192)
        {
          if ((tmp[1] & 192) != 128)
            {
              return 0;
            }
          len += 2;
          tmp += 2;
        }
    }

  return len;
}