#include <myReadKey.h>

int
rk_mytermrestore ()
{
  return tcsetattr (STDOUT_FILENO, TCSANOW, &saved);
}