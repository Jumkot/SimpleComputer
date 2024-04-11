#include <myReadKey.h>

int
rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint)
{
  if (regime < 0 || regime > 1 || echo < 0 || echo > 1 || sigint < 0
      || sigint > 1)
    {
      return -1;
    }
  if (tcgetattr (STDOUT_FILENO, &actual) != 0)
    {
      return -1;
    }
  // канонический режим
  if (regime)
    {
      actual.c_lflag |= ICANON;
    }
  // неканонический режим
  else if (!regime)
    {
      actual.c_lflag &= ~ICANON;
    }
  else
    {
      return -1;
    }

  // отображение символов
  if (echo == 1)
    {
      actual.c_lflag |= ECHO;
    }
  else if (!echo)
    {
      actual.c_lflag &= ~ECHO;
    }
  else
    {
      return -1;
    }

  // клавиши прерывания
  if (sigint)
    {
      actual.c_lflag |= ISIG;
    }
  else if (!sigint)
    {
      actual.c_lflag &= ~ISIG;
    }
  else
    {
      return -1;
    }

  // количество читаемых символов
  actual.c_cc[VTIME] = vtime;
  // время ожидания символа
  actual.c_cc[VMIN] = vmin;

  return tcsetattr (STDOUT_FILENO, TCSANOW, &actual);
}