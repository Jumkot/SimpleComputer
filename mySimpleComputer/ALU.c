#include <mySimpleComputer.h>

int
ALU (int command, int operand)
{
  int value = 0;
  sc_cacheGet (operand, &value);

  int accum = 0;
  sc_accumulatorGet (&accum);
  int icounter = 0;
  sc_icounterGet (&icounter);

  switch (command)
    {
    case ADD:
      accum += value;
      sc_accumulatorSet (accum);
      break;
    case SUB:
      accum -= value;
      sc_accumulatorSet (accum);
      break;
    case DIVIDE:
      if (value == 0)
        {
          sc_regSet (O, 1);
          sc_icounterSet (++icounter);
          return -1;
        }
      accum /= value;
      sc_accumulatorSet (accum);
      break;
    case MUL:
      accum *= value;
      sc_accumulatorSet (accum);
      break;
    case NOT:
      accum = ~accum;
      sc_cacheSet (operand, value);
      break;
    default:
      sc_regSet (E, 1);
      break;
    }

  sc_icounterSet (++icounter);
  return 0;
}