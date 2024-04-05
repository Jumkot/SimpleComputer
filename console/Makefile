#testMakefile for console

CC = gcc

CFLAGS = -Wall -Werror
FLAGS = -o

LIB_NAME = libconsole.a
PART_SOURCES = $(wildcard *.c)
PART_OBJECTS = $(patsubst %.c, %.o, $(PART_SOURCES))

all: $(LIB_NAME)	

%.o: %.c
	$(CC) $(CFLAGS) -c -I../include $(FLAGS) $@ $^

$(LIB_NAME): $(PART_OBJECTS)
	ar rcs $@ $^

# font.bin: font.o
# 	$(CC) $(CFLAGS) font.o -I../include $(FLAGS) font -Lconsole -LmySimpleComputer -LmyTerm -LmyBigChar -lconsole -lmsc -lmt -lmbc
# 	./font

clean:
	rm -rf $(LIB_NAME) $(PART_OBJECTS)

.PHONY: all clean 