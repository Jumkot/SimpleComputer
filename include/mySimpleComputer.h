#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#include <console.h>
#include <sc_variables.h>
#include <stdio.h>

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

// Кодирование/декодирование команд
int sc_commandEncode (int sign, int command, int operand, int *value);
int sc_commandDecode (int value, int *sign, int *command, int *operand);
int sc_commandValidate (int command);

#endif