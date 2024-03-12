#Makefile for simplecomputer
CC = gcc

CFLAGS = -Wall -Werror
FLAGS = -o

APP = console/pr01
APP_OBJECT = console/pr01.o
APP_PATH = console/pr01.c

INCLUDE = include
LIB_SC = mySimpleComputer/lib_sc.a

all: link
	
link: project
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(APP_OBJECT) $(APP_PATH)
	$(CC) $(CFLAGS) $(FLAGS) ./$(APP) $(APP_OBJECT) -Lconsole -LmySimpleComputer -lconsole -lmySimpleComputer

project:
	cd console/ && $(MAKE)
#cd mySimpleComputer/ && $(MAKE)

run:
	./$(APP_NAME)

clean:
	cd console/ && make clean
#cd mySimpleComputer/ && make clean
	rm -rf simplecomputer

.PHONY: all clean 