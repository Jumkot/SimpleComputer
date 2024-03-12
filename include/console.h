#ifndef CONSOLE_H
#define CONSOLE_H

#include <mySimpleComputer.h>
#include <stdio.h>
#include <string.h>

void printCell (int address);
void printFlags (void);
void printDecodedCommand (int value);
void printAccumulator (void);
void printCounters (void);

#endif