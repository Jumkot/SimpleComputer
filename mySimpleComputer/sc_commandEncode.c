#include <mySimpleComputer.h>

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if ((sign > 1) || (command > 127))
    {
      sc_regSet (P, 1);
      return -1;
    }
  if (operand > 127)
    {
      sc_regSet (M, 1);
      return -1;
    }
  *value = ((command << 7) | (sign << 14)) | operand;

  sc_regSet (P, 0);
  sc_regSet (M, 0);
  return 0;
}