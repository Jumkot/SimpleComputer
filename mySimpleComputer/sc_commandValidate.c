#include <mySimpleComputer.h>

int
sc_commandValidate (int command)
{
  if (command == NOP || command == CPUINFO || command == READ
      || command == WRITE || command == LOAD || command == STORE
      || command == ADD || command == SUB || command == DIVIDE || command == MUL
      || command == JUMP || command == JNEG || command == JZ || command == HALT
      || command == NOT || command == JNS)
    {
      return 0;
    }

  sc_regSet (E, 1);
  return -1;
}