#include <mySimpleComputer.h>

int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  if (!sign || !command || !operand)
    {
      return -1;
    }

  *sign = (value >> 14) & 0x1;
  *command = (value >> 7) & 0x7f;
  *operand = value & 0x7f;

  return 0;
}