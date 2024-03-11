#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#include <stdio.h>
#define SIZE 128

extern int ram[SIZE];

int sc_memoryInit ();

int sc_memoryInit ();

int sc_memorySet (int address, int value);

int sc_memoryGet (int address, int *value);

int sc_memorySave (const char *filename);

int sc_memoryLoad (char *filename);

#endif