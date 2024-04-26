#include <mySimpleComputer.h>

#define SIZE 128

int ram[SIZE];

int instruction_counter;
int idle_tact_counter;
int accumulator;
int registr;

cache_line cache[5];