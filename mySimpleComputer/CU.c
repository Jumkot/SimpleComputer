#include <console.h>
#include <myTerm.h>

void
CU ()
{
  int icounter = 0;
  sc_icounterGet (&icounter);
  if (icounter >= 127)
    {
      sc_regSet (M, 1);
      sc_regSet (T, 1);
      return;
    }
  int value = 0;
  sc_cacheGet (icounter, &value);

  int sign = 0;
  int command = 0;
  int operand = 0;

  if (sc_commandDecode (value, &sign, &command, &operand))
    {
      sc_icounterSet (++icounter);
      return;
    }
  if (sign)
    {
      sc_regSet (E, 1);
      sc_regSet (T, 1);
      return;
    }

  if (operand >= SIZE || operand < 0)
    {
      sc_regSet (M, 1);
      sc_regSet (T, 1);
      return;
    }

  if ((command >= ADD && command <= MUL) || command == NOT)
    {
      ALU (command, operand);
      return;
    }
  else
    {
      int read_value[5];

      char string[85];
      int length = 0;

      switch (command)
        {
        case NOP:
          sc_icounterSet (++icounter);
          break;
        case CPUINFO:
          mt_setdefaultcolor ();
          length = snprintf (string, 85,
                             "Бондаренко Анастасия Александровна, ИС-241");
          mt_gotoXY (26, 1);
          write (1, string, length);
          sc_icounterSet (++icounter);
          break;
        case READ:
          sc_regSet (T, 1);
          printTerm (operand, -1, 1, 0);
          if (!(rk_readvalue (read_value, 0)))
            {
              sc_cacheSet (operand, *read_value);
            }
          printTerm (operand, *read_value, 1, 1);
          sc_icounterSet (++icounter);
          sc_regSet (T, 0);
          break;
        case WRITE:
          mt_setdefaultcolor ();
          sc_cacheGet (operand, &value);
          printTerm (operand, value, 0, 1);
          sc_icounterSet (++icounter);
          break;
        case LOAD:
          sc_cacheGet (operand, &value);
          sc_accumulatorSet (value);
          sc_icounterSet (++icounter);
          break;
        case STORE:
          sc_accumulatorGet (&value);
          sc_cacheSet (operand, value);
          sc_icounterSet (++icounter);
          break;
        case JUMP:
          sc_icounterSet (operand);
          break;
        case JNEG:
          sc_accumulatorGet (&value);
          if (value < 0)
            {
              sc_icounterSet (operand);
            }
          else
            {
              sc_icounterSet (++icounter);
            }
          break;
        case JZ:
          sc_accumulatorGet (&value);
          if (value == 0)
            {
              sc_icounterSet (operand);
            }
          else
            {
              sc_icounterSet (++icounter);
            }
          break;
        case HALT:
          sc_icounterSet (++icounter);
          mt_gotoXY (27, 1);
          sc_regSet (T, 1);
          break;
        case JNS:
          sc_accumulatorGet (&value);
          if (value > 0)
            {
              sc_icounterSet (operand);
            }
          break;
        default:
          sc_regSet (E, 1);
          break;
        }
    }
}