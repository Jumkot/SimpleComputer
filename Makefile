#Makefile for simplecomputer
CC = gcc

CFLAGS = -Wall -Werror
FLAGS = -o

APP = console/pr01
APP_OBJECT = console/pr01.o
APP_PATH = console/pr01.c

INCLUDE = include
LIB_MSC = mySimpleComputer/libmsc.a
LIB_MT = myTerm/libmt.a

all: link
	
link: project
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(APP_OBJECT) $(APP_PATH)
	$(CC) $(CFLAGS) $(FLAGS) ./$(APP) $(APP_OBJECT) -Lconsole -LmySimpleComputer -LmyTerm -lconsole -lmsc -lmt

project:
	make -C console/
	make -C mySimpleComputer/
	make -C myTerm/

run:
	./$(APP)

clean:
	make clean -C console/
	make clean -C mySimpleComputer/
	make clean -C myTerm/
	rm -rf $(APP) $(APP_OBJECT) *.bin

.PHONY: all clean 