#include <mySimpleComputer.h>

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if ((sign > 1) || (command > 127) || (operand > 127))
    {
      return -1;
    }
  *value = ((command << 7) | (sign << 14)) | operand;

  return 0;
}