#testMakefile for simpleassembler

CC = gcc

CFLAGS = -Wall -Werror
FLAGS = -o

LIB_NAME = libsa.a
PART_SOURCES = $(wildcard *.c)
PART_OBJECTS = $(patsubst %.c, %.o, $(PART_SOURCES))

all: $(LIB_NAME)	

%.o: %.c
	$(CC) $(CFLAGS) -c -I../include $(FLAGS) $@ $^

$(LIB_NAME): $(PART_OBJECTS)
	ar rcs $@ $^

clean:
	rm -rf $(LIB_NAME) $(PART_OBJECTS) sat

.PHONY: all clean 