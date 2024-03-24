#ifndef CONSOLE_H
#define CONSOLE_H

#include <mySimpleComputer.h>
#include <myTerm.h>
#include <stdio.h>
#include <string.h>

void printCell (int address, enum colors fg, enum colors bg);
void printFlags (void);
void printDecodedCommand (int value);
void printAccumulator (void);
void printCounters (void);

void printTerm (int address, int input);
void printCommand (void);

#endif