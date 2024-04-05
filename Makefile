#Makefile for simplecomputer
CC = gcc

CFLAGS = -Wall -Werror
FLAGS = -o

APP = console/console
APP_OBJECT = console/console.o
APP_PATH = console/console.c

INCLUDE = include
LIB_MSC = mySimpleComputer/libmsc.a
LIB_MT = myTerm/libmt.a
LIB_MT = myBigChar/libmbc.a

all: link
	
link: project
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(APP_OBJECT) $(APP_PATH)
	$(CC) $(CFLAGS) $(FLAGS) ./$(APP) $(APP_OBJECT) -Lconsole -LmySimpleComputer -LmyTerm -LmyBigChar -lconsole -lmsc -lmt -lmbc

project:
	make -C console/
	make -C mySimpleComputer/
	make -C myTerm/
	make -C myBigChar/

run:
	./$(APP)

clean:
	make clean -C console/
	make clean -C mySimpleComputer/
	make clean -C myTerm/
	make clean -C myBigChar/
	rm -rf $(APP) $(APP_OBJECT) *.bin

.PHONY: all clean 