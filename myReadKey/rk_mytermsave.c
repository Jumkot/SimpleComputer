#include <myReadKey.h>

int
rk_mytermsave ()
{
  return tcgetattr (STDOUT_FILENO, &saved);
}
