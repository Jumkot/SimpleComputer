#include "myBigChar.h"

int
bc_bigcharread (int fd, int *big, int need_count, int *count)
{
  need_count *= 2;
  *count = read (fd, big, need_count * sizeof (int));
  if (*count == -1)
    {
      return -1;
    }

  if (*count != need_count * sizeof (int))
    {
      *count = 0;
      return -1;
    }
  return 0;
}