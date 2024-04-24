#include <console.h>

void
printBigCell (void)
{
  int x = 8;
  int y = 64;

  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;

  sc_memoryGet (actual_cell, &value);
  sc_commandDecode (value, &sign, &command, &operand);
  char string[50];
  snprintf (string, 50, "%c%.2x%.2x", (sign) ? '-' : '+', command, operand);

  for (int i = 0; i < 5; i++)
    {
      int biggy[2] = { 0x0, 0x0 };

      switch (string[i])
        {
        case '0':
          {
            biggy[0] = big_load[0];
            biggy[1] = big_load[1];
            break;
          }
        case '1':
          {
            biggy[0] = big_load[2];
            biggy[1] = big_load[3];
            break;
          }
        case '2':
          {
            biggy[0] = big_load[4];
            biggy[1] = big_load[5];
            break;
          }
        case '3':
          {
            biggy[0] = big_load[6];
            biggy[1] = big_load[7];
            break;
          }
        case '4':
          {
            biggy[0] = big_load[8];
            biggy[1] = big_load[9];
            break;
          }
        case '5':
          {
            biggy[0] = big_load[10];
            biggy[1] = big_load[11];
            break;
          }
        case '6':
          {
            biggy[0] = big_load[12];
            biggy[1] = big_load[13];
            break;
          }
        case '7':
          {
            biggy[0] = big_load[14];
            biggy[1] = big_load[15];
            break;
          }
        case '8':
          {
            biggy[0] = big_load[16];
            biggy[1] = big_load[17];
            break;
          }
        case '9':
          {
            biggy[0] = big_load[18];
            biggy[1] = big_load[19];
            break;
          }
        case 'a':
          {
            biggy[0] = big_load[20];
            biggy[1] = big_load[21];
            break;
          }
        case 'b':
          {
            biggy[0] = big_load[22];
            biggy[1] = big_load[23];
            break;
          }
        case 'c':
          {
            biggy[0] = big_load[24];
            biggy[1] = big_load[25];
            break;
          }
        case 'd':
          {
            biggy[0] = big_load[26];
            biggy[1] = big_load[27];
            break;
          }
        case 'e':
          {
            biggy[0] = big_load[28];
            biggy[1] = big_load[29];
            break;
          }
        case 'f':
          {
            biggy[0] = big_load[30];
            biggy[1] = big_load[31];
            break;
          }
        case '+':
          {
            biggy[0] = big_load[32];
            biggy[1] = big_load[33];
            break;
          }
        case '-':
          {
            biggy[0] = big_load[34];
            biggy[1] = big_load[35];
            break;
          }
        default:
          biggy[0] = 0;
          biggy[1] = 0;
          break;
        }

      bc_printbigchar (biggy, x + 1, y + i * 9, WHITE, BLACK);
    }

  char str[100];
  int length = snprintf (str, 100, "Номер редактируемой ячейки: %s%s%d",
                         actual_cell < 100 ? "0" : "",
                         actual_cell < 10 ? "0" : "", actual_cell);
  mt_gotoXY (17, 64);
  mt_setbgcolor (BLACK);
  mt_setfgcolor (BLUE);
  write (1, str, length);
  
  mt_setdefaultcolor ();
  mt_gotoXY (26, 1);
}