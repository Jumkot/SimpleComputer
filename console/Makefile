#Makefile for console
DIR_NAME = console
PART_NAME = test

CC = gcc

CFLAGS = -Wall -Werror 
FLAGS = -o

all: $(DIR_NAME).a

$(DIR_NAME).a: $(PART_NAME).o
	ar cr $(DIR_NAME).a $(PART_NAME).o

$(PART_NAME).o: $(PART_NAME).c
	$(CC) $(CFLAGS) -c $(PART_NAME).c $(FLAGS) $@

clean:
	rm -rf *.[ao]

.PHONY: all clean 