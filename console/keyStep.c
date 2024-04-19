#include <console.h>

void
keyStep ()
{
  Cu();
  if (actual_cell < SIZE - 1) 
    {
      instruction_counter++;
      actual_cell = instruction_counter;
    }
}