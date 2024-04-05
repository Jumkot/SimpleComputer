#include "myBigChar.h"

int
bc_bigcharwrite (int fd, int *big, int count)
{
  count *= 2;
  int bytes_written = write (fd, big, count * sizeof (int));
  if (bytes_written == -1)
    {
      return -1;
    }
  return 0;
}