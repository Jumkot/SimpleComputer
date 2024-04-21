#include <console.h>
#include <myTerm.h>

void
CU ()
{
  mt_clrscr ();
  printAll ();

  int icounter = 0;
  sc_icounterGet (&icounter);
  int value = 0;
  sc_memoryGet (icounter, &value);

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
      sc_icounterSet (++icounter);
      return;
    }

  if (sc_commandValidate (command))
    {
      sc_regSet (E, 1);
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
          printTerm (operand, 1, 1);
          mt_gotoXY (24, 72);
          if (!(rk_readvalue (read_value, 0)))
            {
              sc_memorySet (operand, *read_value);
              input_flag = 1;
            }
          sc_icounterSet (++icounter);
          break;
        case WRITE:
          mt_setdefaultcolor ();

          printTerm (operand, 0, 1);
          sc_icounterSet (++icounter);
          break;
        case LOAD:
          sc_memoryGet (operand, &value);
          sc_accumulatorSet (value);
          sc_icounterSet (++icounter);
          break;
        case STORE:
          sc_accumulatorGet (&value);
          sc_memorySet (operand, value);
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
          break;
        case JZ:
          sc_accumulatorGet (&value);
          if (value == 0)
            {
              sc_icounterSet (operand);
            }
          break;
        case HALT:
          sc_icounterSet (++icounter);
          mt_gotoXY (27, 1);
          sc_regSet (T, 1);
          exit (0);
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