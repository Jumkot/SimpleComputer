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

  int count_load;
  int file = open ("font.bin", O_RDONLY);
  bc_bigcharread (file, big_load, 18, &count_load);
  close (file);

  IRC (SIGUSR1);

  // Загрузка памяти
  sc_memoryLoad (argv[1]);

  console ();

  return 0;
}