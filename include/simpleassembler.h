#ifndef SIMPLEASSEMBLER_H
#define SIMPLEASSEMBLER_H

#include <mySimpleComputer.h>
#include <stdlib.h>
#include <string.h>

int sc_memoryInit (void);
int sc_commandEncode (int sign, int command, int operand, int *value);
int sc_memorySet (int address, int value);
int sc_memorySave (char *filename);

int sa_fileTranslate (char *input_file, char *output_file);
int sa_commandTranslate (char *command);

#endif