#include <mySimpleComputer.h>

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  *value = ((command << 7) | (sign << 14)) | operand;

  return 0;
}