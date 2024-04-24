#include <console.h>

int
main (int argc, char *argv[])
{
  // Инициализация
  signal (SIGALRM, IRC);
  signal (SIGUSR1, IRC);
  signal (SIGUSR2, IRC);

  struct itimerval nval, oval;
  nval.it_interval.tv_sec = 0;
  nval.it_interval.tv_usec = 500000;
  nval.it_value.tv_sec = 0;
  nval.it_value.tv_usec = 500000;
  setitimer (ITIMER_REAL, &nval, &oval);

  IRC (SIGUSR1);

  for (int i = 0; i < SIZE; i++)
    {
      int value;
      sc_commandEncode (0, 0, 0, &value);
      sc_memorySet (i, value);
      printCell (i, WHITE, BLACK);

      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
    }

  // sc_commandEncode (0, 31, 0, &value);
  // sc_memorySet (3, value);

  // Загрузка шрифта
  int count_load;
  const char *load_filename;
  if (argc > 1)
    {
      load_filename = argv[1];
    }
  else
    {
      load_filename = "font.bin";
    }
  if (access (load_filename, F_OK) == -1)
    {
      char string[80];
      int length = snprintf (string, 80, "Ошибка: Файл '%s' не существует.\n",
                             load_filename);
      write (1, string, length);
      exit (0);
    }

  int file = open (load_filename, O_RDONLY);
  bc_bigcharread (file, big_load, 18, &count_load);
  close (file);
  
  // Загрузка памяти
  sc_memoryLoad ("test1.bin");
  console ();

  return 0;
}