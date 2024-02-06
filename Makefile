#Makefile for simplecomputer
CC = gcc

CFLAGS = -Wall -Werror 
FLAGS = -o

APP_NAME = simplecomputer

BUILD_DIR = build

all: link
	
link: project
	$(CC) console/$(BUILD_DIR)/console.a $(FLAGS) $(APP_NAME)

project:
	cd console/ && $(MAKE)

run:
	./$(APP_NAME)

clean:
	cd console/ && make clean
	rm -rf simplecomputer

.PHONY: all clean 