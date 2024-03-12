#include <mySimpleComputer.h>

int
sc_commandValidate (int command)
{
  if (command >= 0 && command < SIZE)
    {
      return 0;
    }

  printf ("Недопустимая команда\n");
  return -1;
}