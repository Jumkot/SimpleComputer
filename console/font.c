#include "myBigChar.h"

int
font (int *bigC, char value)
{
  if (bigC == NULL)
    {
      return -1;
    }
  switch (value)
    {
    case '0':
      {
        for (int i = 0; i < 8; i++)
          {
            for (int j = 1; j < 7; j++)
              {
                bc_setbigcharpos (bigC, i, j, 1);
              }
          }
        for (int i = 1; i < 7; i++)
          {
            bc_setbigcharpos (bigC, i, 3, 0);
            bc_setbigcharpos (bigC, i, 4, 0);
          }
        break;
      }
    case '1':
      {
        for (int j = 5; j < 7; j++)
          {
            for (int i = 0; i < 8; i++)
              {
                bc_setbigcharpos (bigC, i, j, 1);
              }
          }
        int j = 5;
        for (int i = 0; i < 3; i++)
          {
            bc_setbigcharpos (bigC, i, j, 1);
            bc_setbigcharpos (bigC, i, j - 1, 1);
            j--;
          }
        bc_setbigcharpos (bigC, 3, j, 1);
        break;
      }
    case '2':
      {
        for (int j = 1; j < 7; j++)
          {
            bc_setbigcharpos (bigC, 0, j, 1);
            bc_setbigcharpos (bigC, 7, j, 1);
            (j == 1 || j == 2 || j == 5 || j == 6)
                ? bc_setbigcharpos (bigC, 1, j, 1)
                : bc_setbigcharpos (bigC, 1, j, 0);
            // bc_setbigcharpos (bigC, j, 7, 1);
            // (j == 1 || j == 2 || j == 5 || j == 6) ? bc_setbigcharpos (bigC,
            // j, 1, 1) : bc_setbigcharpos (bigC, j, 1, 0); bc_setbigcharpos
            // (bigC, j, 0, 1);
          }
        int j = 6;
        for (int i = 2; i < 7; i++)
          {
            bc_setbigcharpos (bigC, i, j, 1);
            bc_setbigcharpos (bigC, i, j - 1, 1);
            // bc_setbigcharpos (bigC, j, i, 1);
            // bc_setbigcharpos (bigC, j - 1, i, 1);
            j--;
          }
        break;
      }
    case '3':
      {
        for (int j = 1; j < 7; j++)
          {
            bc_setbigcharpos (bigC, 0, j, 1);
            bc_setbigcharpos (bigC, 7, j, 1);
            (j == 1 || j == 2 || j == 5 || j == 6)
                ? bc_setbigcharpos (bigC, 1, j, 1)
                : bc_setbigcharpos (bigC, 1, j, 0);
            (j == 1 || j == 2 || j == 5 || j == 6)
                ? bc_setbigcharpos (bigC, 6, j, 1)
                : bc_setbigcharpos (bigC, 6, j, 0);
          }
        for (int j = 3; j < 7; j++)
          {
            bc_setbigcharpos (bigC, 3, j, 1);
            bc_setbigcharpos (bigC, 4, j, 1);
            (j == 5 || j == 6) ? bc_setbigcharpos (bigC, 2, j, 1)
                               : bc_setbigcharpos (bigC, 2, j, 0);
            (j == 5 || j == 6) ? bc_setbigcharpos (bigC, 5, j, 1)
                               : bc_setbigcharpos (bigC, 5, j, 0);
          }
        break;
      }
    case '4':
      {
        for (int j = 5; j < 7; j++)
          {
            for (int i = 0; i < 8; i++)
              {
                bc_setbigcharpos (bigC, i, j, 1);
              }
          }
        int j = 5;
        for (int i = 0; i < 4; i++)
          {
            bc_setbigcharpos (bigC, i, j, 1);
            bc_setbigcharpos (bigC, i, j - 1, 1);
            j--;
          }
        for (int j = 1; j < 7; j++)
          {
            bc_setbigcharpos (bigC, 4, j, 1);
          }
        break;
      }
    case '5':
      {
        for (int j = 1; j < 7; j++)
          {
            bc_setbigcharpos (bigC, 0, j, 1);
            bc_setbigcharpos (bigC, 4, j, 1);
            bc_setbigcharpos (bigC, 7, j, 1);
          }
        bc_setbigcharpos (bigC, 7, 6, 0);
        for (int i = 1; i < 7; i++)
          {
            (i < 4) ? bc_setbigcharpos (bigC, i, 1, 1)
                    : bc_setbigcharpos (bigC, i, 5, 1);
            (i < 4) ? bc_setbigcharpos (bigC, i, 2, 1)
                    : bc_setbigcharpos (bigC, i, 6, 1);
          }
        break;
      }
    case '6':
      {
        for (int i = 0; i < 8; i++)
          {
            bc_setbigcharpos (bigC, i, 2, 1);
            bc_setbigcharpos (bigC, i, 5, 1);
            if (i == 0 || i == 4 || i == 7)
              {
                bc_setbigcharpos (bigC, i, 3, 1);
                bc_setbigcharpos (bigC, i, 4, 1);
                (i == 4) ? bc_setbigcharpos (bigC, i, 1, 1)
                         : bc_setbigcharpos (bigC, i, 1, 0);
              }
            else if (i == 3)
              {
                bc_setbigcharpos (bigC, i, 1, 1);
                bc_setbigcharpos (bigC, i, 2, 1);
                bc_setbigcharpos (bigC, i, 5, 0);
              }
            else
              {
                bc_setbigcharpos (bigC, i, 1, 1);
                bc_setbigcharpos (bigC, i, 6, 1);
              }
          }
        break;
      }
    case '7':
      {
        for (int j = 1; j < 7; j++)
          {
            bc_setbigcharpos (bigC, 0, j, 1);
          }
        int j = 7;
        for (int i = 1; i < 8; i++)
          {
            if (i > 3)
              {
                bc_setbigcharpos (bigC, i, 3, 1);
                bc_setbigcharpos (bigC, i, 4, 1);
                continue;
              }
            bc_setbigcharpos (bigC, i, j, 1);
            bc_setbigcharpos (bigC, i, j - 1, 1);
            j--;
          }
        bc_setbigcharpos (bigC, 1, 7, 0);
        break;
      }
    case '8':
      {
        for (int i = 0; i < 8; i++)
          {
            bc_setbigcharpos (bigC, i, 2, 1);
            bc_setbigcharpos (bigC, i, 5, 1);
            if (i == 0 || i == 3 || i == 4 || i == 7)
              {
                bc_setbigcharpos (bigC, i, 3, 1);
                bc_setbigcharpos (bigC, i, 4, 1);
              }
            else
              {
                bc_setbigcharpos (bigC, i, 1, 1);
                bc_setbigcharpos (bigC, i, 6, 1);
              }
          }
        break;
      }
    case '9':
      {
        for (int i = 0; i < 8; i++)
          {
            bc_setbigcharpos (bigC, i, 2, 1);
            bc_setbigcharpos (bigC, i, 5, 1);
            if (i == 0 || i == 3 || i == 7)
              {
                bc_setbigcharpos (bigC, i, 3, 1);
                bc_setbigcharpos (bigC, i, 4, 1);
                (i == 3) ? bc_setbigcharpos (bigC, i, 6, 1)
                         : bc_setbigcharpos (bigC, i, 6, 0);
              }
            else if (i == 4)
              {
                bc_setbigcharpos (bigC, i, 6, 1);
                bc_setbigcharpos (bigC, i, 5, 1);
                bc_setbigcharpos (bigC, i, 2, 0);
              }
            else
              {
                bc_setbigcharpos (bigC, i, 1, 1);
                bc_setbigcharpos (bigC, i, 6, 1);
              }
          }
        break;
      }
    case 'a':
      {
        for (int j = 1; j < 7; j++)
          {
            for (int i = 0; i < 8; i++)
              {
                if (j == 1 || j == 6)
                  {
                    bc_setbigcharpos (bigC, i, j, 1);
                    bc_setbigcharpos (bigC, 0, j, 0);
                    bc_setbigcharpos (bigC, 1, j, 0);
                  }
                else if (j == 3 || j == 4)
                  {
                    bc_setbigcharpos (bigC, 0, j, 1);
                    bc_setbigcharpos (bigC, 4, j, 1);
                  }
                else
                  {
                    bc_setbigcharpos (bigC, i, j, 1);
                  }
              }
          }
        break;
      }
    case 'b':
      {
        for (int i = 0; i < 8; i++)
          {
            bc_setbigcharpos (bigC, i, 1, 1);
            bc_setbigcharpos (bigC, i, 2, 1);
            bc_setbigcharpos (bigC, i, 5, 1);
            if (i == 0 || i == 3 || i == 4 || i == 7)
              {
                bc_setbigcharpos (bigC, i, 3, 1);
                bc_setbigcharpos (bigC, i, 4, 1);
              }
            else
              {
                bc_setbigcharpos (bigC, i, 6, 1);
              }
          }
        break;
      }
    case 'c':
      {
        for (int i = 0; i < 8; i++)
          {
            bc_setbigcharpos (bigC, i, 2, 1);
            bc_setbigcharpos (bigC, i, 5, 1);
            if (i == 0 || i == 7)
              {
                bc_setbigcharpos (bigC, i, 3, 1);
                bc_setbigcharpos (bigC, i, 4, 1);
              }
            else if (i == 3 || i == 4)
              {
                bc_setbigcharpos (bigC, i, 1, 1);
                bc_setbigcharpos (bigC, i, 2, 1);
                bc_setbigcharpos (bigC, i, 5, 0);
              }
            else
              {
                bc_setbigcharpos (bigC, i, 1, 1);
                bc_setbigcharpos (bigC, i, 6, 1);
              }
          }
        break;
      }
    case 'd':
      {
        for (int i = 0; i < 8; i++)
          {
            bc_setbigcharpos (bigC, i, 1, 1);
            bc_setbigcharpos (bigC, i, 2, 1);
            bc_setbigcharpos (bigC, i, 5, 1);
            bc_setbigcharpos (bigC, i, 6, 1);
          }
        for (int j = 3; j < 7; j++)
          {
            if (j == 3 || j == 4)
              {
                bc_setbigcharpos (bigC, 0, j, 1);
                bc_setbigcharpos (bigC, 7, j, 1);
              }
            else if (j == 5 || j == 6)
              {
                bc_setbigcharpos (bigC, 0, j, 0);
                bc_setbigcharpos (bigC, 7, j, 0);
                (j == 6) ? bc_setbigcharpos (bigC, 1, j, 0)
                         : bc_setbigcharpos (bigC, 1, j, 1);
                (j == 6) ? bc_setbigcharpos (bigC, 6, j, 0)
                         : bc_setbigcharpos (bigC, 6, j, 1);
              }
          }
        break;
      }
    case 'e':
      {
        for (int i = 0; i < 8; i++)
          {
            bc_setbigcharpos (bigC, i, 1, 1);
            bc_setbigcharpos (bigC, i, 2, 1);
          }
        for (int j = 3; j < 7; j++)
          {
            bc_setbigcharpos (bigC, 0, j, 1);
            bc_setbigcharpos (bigC, 7, j, 1);
            if (j == 3 || j == 4)
              {
                bc_setbigcharpos (bigC, 3, j, 1);
                bc_setbigcharpos (bigC, 4, j, 1);
              }
          }
        break;
      }
    case 'f':
      {
        for (int i = 0; i < 8; i++)
          {
            bc_setbigcharpos (bigC, i, 1, 1);
            bc_setbigcharpos (bigC, i, 2, 1);
          }
        for (int j = 3; j < 7; j++)
          {
            bc_setbigcharpos (bigC, 0, j, 1);
            if (j == 3 || j == 4)
              {
                bc_setbigcharpos (bigC, 3, j, 1);
                bc_setbigcharpos (bigC, 4, j, 1);
              }
          }
        break;
      }
    case '+':
      {
        for (int i = 3; i < 5; i++)
          {
            for (int j = 1; j < 7; j++)
              {
                bc_setbigcharpos (bigC, i, j, 1);
              }
          }
        for (int j = 3; j < 5; j++)
          {
            for (int i = 1; i < 7; i++)
              {
                bc_setbigcharpos (bigC, i, j, 1);
              }
          }
        break;
      }
    case '-':
      {
        for (int i = 3; i < 5; i++)
          {
            for (int j = 1; j < 7; j++)
              {
                bc_setbigcharpos (bigC, i, j, 1);
              }
          }
        break;
      }
    default:
      bigC[0] = 0;
      bigC[1] = 0;
      break;
    }
  return 0;
}

int
main ()
{
  int fontBig[36];
  for (int i = 0; i < 10; i++)
    {
      fontBig[i] = 0x0;
    }

  int count_save = 0;
  char string[] = "0123456789abcdef+-";
  for (int i = 0; i < 18; i++)
    {
      int biggy[2] = { 0x0, 0x0 };

      font (biggy, string[i]);
      fontBig[count_save] = biggy[0];
      fontBig[count_save + 1] = biggy[1];
      count_save += 2;
    }

  int file = open ("font.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  bc_bigcharwrite (file, fontBig, 18);
  close (file);

  return 0;
}