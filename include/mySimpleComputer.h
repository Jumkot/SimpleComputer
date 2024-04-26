#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#include <sc_variables.h>
#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define SIZE 128

#define BIT7 0x7f
#define BIT8 0xff

#define P 1 // Переполнение при выполнении операции
#define O 2  // Ошибка деления на 0
#define M 4  // Ошибка выхода за границы памяти
#define T 8  // Игнорирование тактовых импульсов
#define E 16 // Неверная команда

extern int ram[SIZE];

extern int instruction_counter;
extern int idle_tact_counter;
extern int accumulator;
extern int registr;

typedef struct cache_line
{
  int start_address; // Адрес начала строки
  int str[10];       // Строка значений из памяти
  int str_change;    // Флаг изменения строки
  int str_time; // Давность последнего использования строки
} cache_line;

extern cache_line cache[5];

enum commands
{
  NOP = 0x00,     // пустая операция
  CPUINFO = 0x01, // вывод информации об исполнителе

  READ = 0x0A, // ввод с терминала в указ. ячейку памяти
  WRITE = 0x0B, // вывод на терминал из указ. ячейки памяти

  LOAD = 0x14, // загрузка в аккумулятор знач. из указ. адреса
  STORE = 0x15, // выгрузка знач. из аккумулятора по указ. адресу

  ADD = 0x1E, // сложение слова в аккумуляторе и слова из указ. ячейки памяти
  SUB = 0x1F, // вычитание из слова в аккумуляторе слова из указ. ячейки памяти
  DIVIDE = 0x20, // деление слова в акк. на слово из указ. ячейки памяти
  MUL = 0x21, // умножение слова в аккумуляторе на слово из указ. ячейки памяти
  // результат в аккумуляторе

  JUMP = 0x28, // переход к указанному адресу памяти
  JNEG = 0x29, // переход к указанному адресу памяти if accum < 0
  JZ = 0x2A, // переход к указанному адресу памяти if accum == 0
  HALT = 0x2B, // остановка, завершает программу

  // Пользовательские функции
  NOT = 0x33, // инверсия слова в аккумуляторе, результат в указ. ячейку памяти
  JNS = 0x37 // переход к указанному адресу памяти if accum > 0
};

// Память
int sc_memoryInit (void);
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int *value);
int sc_memorySave (char *filename);
int sc_memoryLoad (char *filename);

// Регистры
int sc_regInit (void);
int sc_regSet (int reg, int value);
int sc_regGet (int reg, int *value);

// Аккумулятор
int sc_accumulatorInit (void);
int sc_accumulatorSet (int value);
int sc_accumulatorGet (int *value);

// Счётчик команд
int sc_icounterInit (void);
int sc_icounterSet (int value);
int sc_icounterGet (int *value);

// Счётчик тактов простоя процессора
int sc_tcounterInit (void);
int sc_tcounterSet (int value);
int sc_tcounterGet (int *value);

// Кодирование/декодирование команд
int sc_commandEncode (int sign, int command, int operand, int *value);
int sc_commandDecode (int value, int *sign, int *command, int *operand);
int sc_commandValidate (int command);

void CU (void);
int ALU (int command, int operand);
void IRC (int signum);

// Кэш
int sc_cacheInit (void);
int sc_cacheSet (int address, int value);
int sc_cacheGet (int address, int *value);
int sc_cacheSave (int address);
int sc_cacheLoad (int address);

#endif