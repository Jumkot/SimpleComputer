#testMakefile for mySimpleComputer
DIR_NAME = mySimpleComputer
PART_NAME = test

CC = gcc

CFLAGS = -Wall -Werror 
FLAGS = -o

LIB_NAME = lib_sc.a
PART_SOURCES = $(wildcard *.c)
PART_OBJECTS = $(patsubst %.c, %.o, $(PART_SOURCES))

all: $(LIB_NAME)	

$(LIB_NAME): $(PART_OBJECTS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o -I../include $<

clean:
	rm -rf *.[ao]

.PHONY: all clean 