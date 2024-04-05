#ifndef MYBIGCHAR_H
#define MYBIGCHAR_H

#include <fcntl.h>
#include <myTerm.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ENTER_ACS "\E(0"
#define EXIT_ACS "\E(B"
#define ACS_CKBOARD "a"

#define L_UP "l"
#define R_UP "k"
#define HORZ "q"
#define VERT "x"
#define L_BTM "m"
#define R_BTM "j"

int bc_strlen (char *str);
int bc_printA (char *str);
int bc_box (int x1, int y1, int x2, int y2, enum colors box_fg,
            enum colors box_bg, char *header, enum colors header_fg,
            enum colors header_bg);

int bc_setbigcharpos (int *big, int x, int y, int value);
int bc_getbigcharpos (int *big, int x, int y, int *value);
int bc_printbigchar (int[2], int x, int y, enum colors, enum colors);

int bc_bigcharwrite (int fd, int *big, int count);
int bc_bigcharread (int fd, int *big, int need_count, int *count);

#endif