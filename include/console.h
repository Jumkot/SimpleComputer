#ifndef CONSOLE_H
#define CONSOLE_H

#include "myBigChar.h"
#include <mySimpleComputer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int big_load[36];

void printCell (int address, enum colors fg, enum colors bg);
void printFlags (void);
void printDecodedCommand (int value);
void printAccumulator (void);
void printCounters (void);

void printTerm (int address, int input);
void printCommand (void);

void printBigCell (void);
void printAll (void);

#endif