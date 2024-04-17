#include <myReadKey.h>
#include <mySimpleComputer.h>

int
rk_readvalue (int *value, int timeout)
{
  if (tcgetattr (STDOUT_FILENO, &saved) != 0)
    {
      return -1;
    }
  rk_mytermsave ();
  if (rk_mytermregime (0, 1, 1, 0, 0) != 0)
    {
      return -1;
    }

  for (int i = 0; i < 5; i++)
    {
      enum keys key = NONE;
      int flag = 1;
      while (flag)
        {
          rk_readkey (&key);
          char num = key + 48;
          if (key == EXIT)
            {
              rk_mytermrestore ();
              return -1;
            }
          if (i == 0)
            {
              if (key == 16)
                {
                  write (1, "+", 1);
                  value[0] = 0;
                  flag = 0;
                }
              else if (key == 17)
                {
                  write (1, "-", 1);
                  value[0] = 1;
                  flag = 0;
                }
            }
          else if (i == 1 || i == 3)
            {
              if (key >= 0 && key <= 7)
                {
                  write (1, &num, 1);
                  flag = 0;
                }
            }
          else if (i == 2 || i == 4)
            {
              if (key >= 0 && key <= 15)
                {
                  if (key > 9)
                    {
                      num += 39;
                    }
                  write (1, &num, 1);
                  flag = 0;
                }
            }
          if (i != 0)
            {
              value[i] = key;
            }
        }
    }
  rk_mytermrestore ();

  int sign = value[0];
  int command = value[1] * 16 + value[2];
  int operand = value[3] * 16 + value[4];

  sc_commandEncode (sign, command, operand, value);

  rk_mytermrestore ();

  return 0;
}