#include <myReadKey.h>

int
rk_readvalue (int *value, int timeout)
{
  if (tcgetattr (STDOUT_FILENO, &saved) != 0)
    {
      return -1;
    }
  rk_mytermsave ();
  if (rk_mytermregime (0, 1, timeout, 0, 0) != 0)
    {
      return -1;
    }
  int key_length = read (STDOUT_FILENO, key_value, *value);
  key_value[key_length] = '\0';

  enum keys key = NONE;
  rk_readkey (&key);
  if (!key)
    {
      char string[80];
      int length = snprintf (string, 80, "Неверная команда!");
      mt_gotoXY (26, 1);
      write (1, string, length);
    }

  return rk_mytermrestore ();
}