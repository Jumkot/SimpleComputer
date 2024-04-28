#include <console.h>

void
printCounters (void)
{
  int icounter = 0;
  sc_icounterGet (&icounter);
  int tcounter = 0;
  sc_tcounterGet (&tcounter);

  char string[50];
  int length = snprintf (string, 50, "  T: %.2d   IC: +%.4x", tcounter, icounter);

  mt_gotoXY (5, 63);
  write (1, string, length);

  mt_gotoXY (26, 1);
}