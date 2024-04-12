#ifndef MYREADKEY_H
#define MYREADKEY_H

#include <myTerm.h>
#include <rk_variables.h>
#include <string.h>
#include <termios.h>

extern struct termios actual, saved;

extern char key_value[16];

enum keys
{
  NONE,
  F5,
  F6,
  UP,
  DOWN,
  RIGHT,
  LEFT,
  LOAD,
  SAVE,
  RESET,
  RUN,
  STEP,
  EDIT,
  EXIT
};

int rk_mytermsave ();
int rk_mytermrestore ();
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_readkey (enum keys *key);
int rk_readvalue (int *value, int timeout);

#endif