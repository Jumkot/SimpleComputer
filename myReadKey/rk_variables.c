#include <myReadKey.h>

#define KEY_SIZE 16

struct termios actual, saved;

char key_value[16];