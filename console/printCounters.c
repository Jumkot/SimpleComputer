#include <console.h>

void
printCounters (void)
{
  int value = 0;
  char string[50];

  sc_icounterGet (&value);
  int length = snprintf (string, 50, "  T: 00   IC: +%.4x", value);

  mt_gotoXY (5, 63);
  write (1, string, length);

  mt_gotoXY (26, 1);
}