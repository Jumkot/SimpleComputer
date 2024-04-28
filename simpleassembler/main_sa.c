#include <simpleassembler.h>

int
main (int argc, char *argv[])
{
  if (argc < 3)
    {
      char error_string[100];
      int error_length
          = snprintf (error_string, 100,
                      "Ошибка: неверное именя входного/выходного файла\n");
      write (1, error_string, error_length);
      exit (0);
    }
  sc_memoryInit ();

  char *input_file = argv[1];
  char *output_file = argv[2];
  
  sa_fileTranslate (input_file, output_file);

  return 0;
}