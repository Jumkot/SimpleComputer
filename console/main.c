#include <console.h>

int
main (int argc, char *argv[])
{
  struct itimerval nval, oval;
  nval.it_interval.tv_sec = 2;
  nval.it_interval.tv_usec = 0;
  nval.it_value.tv_sec = 2;
  nval.it_value.tv_usec = 0;
  setitimer (ITIMER_REAL, &nval, &oval);

  signal (SIGALRM, IRC);
  signal (SIGUSR1, IRC);
  signal (SIGUSR2, IRC);

  IRC (SIGUSR1);

  //// Создание тестовой RAM и её сохранение
  int value;
  for (int i = 0; i < SIZE; i++)
    {
      int value;
      sc_commandEncode (1, 0, 0, &value);
      sc_memorySet (i, value);
      printCell (i, WHITE, BLACK);

      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
    }
  // Вывести исполнителя
  sc_commandEncode (0, 1, 5, &value);
  sc_memorySet (0, value);

  // Загрузка в акк. из №120 = +0b00
  sc_commandEncode (0, 20, 120, &value);
  sc_memorySet (1, value);

  // Перейти на №120
  sc_commandEncode (0, 40, 120, &value);
  sc_memorySet (2, value);

  // Вывести №0 = +0105
  sc_commandEncode (0, 11, 0, &value);
  sc_memorySet (120, value);

  // Ячейка для вычислений
  sc_commandEncode (0, 0, 2, &value);
  sc_memorySet (122, value);

  // Сложение №122 = +0002  и акк. = +0b00 (+0b02)
  sc_commandEncode (0, 30, 122, &value);
  sc_memorySet (121, value);

  // Деление акк. = +0b02 на №122 = +0002 (+03ab)
  sc_commandEncode (0, 32, 122, &value);
  sc_memorySet (123, value);

  // Выгрузка акк. = +03ab в №123
  sc_commandEncode (0, 21, 123, &value);
  sc_memorySet (124, value);

  // Вычитание  №123 = +03ab и акк. = +03ab (+0000)
  sc_commandEncode (0, 31, 123, &value);
  sc_memorySet (125, value);

  // Перейти к №61 = HALT если акк. = +0000
  sc_commandEncode (0, 42, 61, &value);
  sc_memorySet (126, value);

  // HALT
  sc_commandEncode (0, 43, 61, &value);
  sc_memorySet (61, value);

  sc_memorySave ("test.bin");

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

  sc_memoryLoad ("test.bin");
  console ();

  return 0;
}