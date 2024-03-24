#include <mySimpleComputer.h>

int
sc_commandValidate (int command)
{
  if (command >= 0 && command < SIZE)
    {
      return 0;
    }

  return -1;
}