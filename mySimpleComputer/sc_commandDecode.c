#include <mySimpleComputer.h>

int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  if (!sign || !command || !operand)
    {
      sc_regSet (M, 1);
      return -1;
    }

  *sign = (value >> 14) & 0x1;
  *command = (value >> 7) & 0x7f;
  *operand = value & 0x7f;

  if (sc_commandValidate (*command))
  {
    sc_regSet (E, 1);
    return -1;
  }

  sc_regSet (M, 0);
  return 0;
}