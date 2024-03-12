#include <console.h>

void
printCell (int address)
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;

  sc_memoryGet (address, &value);
  sc_commandDecode (value, &sign, &command, &operand);

  char sign_c;
  if (!sign)
    {
      sign_c = '+';
    }
  else
    {
      sign_c = '-';
    }
  printf ("Команда: %c%.2x %.2x\n", sign_c, command, operand);
}