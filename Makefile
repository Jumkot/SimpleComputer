#Makefile for simplecomputer
CC = gcc

CFLAGS = -Wall -Werror 
FLAGS = -o

APP_NAME = simplecomputer

all: link
	
link: project
#$(CC) console/console.a $(FLAGS) $(APP_NAME)
	$(CC) mySimpleComputer/mySimpleComputer.a $(FLAGS) $(APP_NAME)

project:
#cd console/ && $(MAKE)
	cd mySimpleComputer/ && $(MAKE)

run:
	./$(APP_NAME)

clean:
#cd console/ && make clean
	cd mySimpleComputer/ && make clean
	rm -rf simplecomputer

.PHONY: all clean 