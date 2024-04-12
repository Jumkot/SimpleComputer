#ifndef CONSOLE_H
#define CONSOLE_H

#include <c_variables.h>
#include <myBigChar.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int big_load[36];
extern int actual_cell;

void printCell (int address, enum colors fg, enum colors bg);
void printFlags (void);
void printDecodedCommand (int value);
void printAccumulator (void);
void printCounters (void);

void printTerm (int address, int input);
void printCommand (void);

void printBigCell (void);
void printActualCell (void);
void printBoxes (void);
void printKeys (void);
void printAll (void);

void keyReset (void);
void keySave (void);
void keyLoad (void);

#endif