#include "myBigChar.h"

int
bc_printA (char *str)
{
  write (1, ENTER_ACS, strlen( ENTER_ACS));
  if (write (1, str, strlen (str)) != strlen (str))
  {
    write (1, EXIT_ACS, strlen (EXIT_ACS));
    return -1;
  }
  write(1, EXIT_ACS, strlen (EXIT_ACS));

  return 0;
}