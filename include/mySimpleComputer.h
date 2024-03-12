#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#include <sc_variables.h>
#include <stdio.h>

#define SIZE 128

#define BIT7 0x7f
#define BIT8 0xff

#define ADD 1 // Переполнение при выполнении операции
#define ZERO 2 // Ошибка деления на 0
#define SEGM 4 // Ошибка выхода за границы памяти
#define TACT 8 // Игнорирование тактовых импульсов
#define COMMAND 16 // Неверная команда

extern int ram[SIZE];

extern int instruction_counter;
extern int accumulator;
extern int registr;

enum commands
{

  // INPUT/OUTPUT
  READ = 0x10,
  WRITE = 0x11,

  // LOAD/STORE IT ACCUMULATOR
  LOAD = 0x20,
  STORE = 0x21,

  // ARITHMETIC OPERATIONS
  ADD = 0x30,
  SUB = 0x31,
  DIVIDE = 0x32,
  MUL = 0x33,

  // OPERATIONS BROADCAST CONTROL
  JUMP = 0x40,
  JNEG = 0x41,
  JZ = 0x42,
  HALT = 0x43,

  // USER FUNCTUON
  NOT = 0x51,
  AND = 0x52,
  OR = 0x53,
  XOR = 0x54,
  JNS = 0x55,
  JC = 0x56,
  JNC = 0x57,
  JP = 0x58,
  JNP = 0x59,
  CHL = 0x60,
  SHR = 0x61,
  RCL = 0x62,
  RCR = 0x63,
  NEG = 0x64,
  ADDC = 0x65,
  SUBC = 0x66,
  LOGLC = 0x67,
  LOGRC = 0x68,
  RCCL = 0x69,
  RCCR = 0x70,
  MOVA = 0x71,
  MOVR = 0x72,
  MOVCA = 0x73,
  MOVCR = 0x74
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
int sc_accumInit (void);
int sc_accumSet (int value);
int sc_accumGet (int *value);

// Счётчик команд
int sc_countInit (void);
int sc_countSet (int value);
int sc_countGet (int *value);

// Кодирование/декодирование команд
int sc_commandEncode (int command, int operand, int *value);
int sc_commandDecode (int value, int *command, int *operand);
int sc_commandValidate (int command);

#endif