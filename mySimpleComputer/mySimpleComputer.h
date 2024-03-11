#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#include <stdio.h>
#define SIZE 128

#define ERRORADD  1 // Переполнение при выполнении операции
#define ERRORZERO 2 // Ошибка деления на 0 (ERRORFLAG = 2)
#define ERRORSEG 3 // Ошибка выхода за границы памяти (ERRORFILE = 3)
#define IGNORTACT 4 // Игнорирование тактовых импульсов
#define ERRORCOMM 5 // Неверная команда (ERRORCOMS = 4)

extern int ram[SIZE];

extern int instruction_counter;
extern int accumulator;
extern int registr;

// Память
int sc_memoryInit (void);
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int *value);
int sc_memorySave (const char *filename);
int sc_memoryLoad (char *filename);

// Регистры
int sc_regInit(void); 
int sc_regSet(int registr, int value); 
int sc_regGet(int registr, int *value);

// Аккумулятор
int sc_accumInit(void);
int sc_accumSet(int value);
int sc_accumGet(int *value);

// Счётчик команд
int sc_countInit(void);
int sc_countSet(int value);
int sc_countGet(int *value);

#endif