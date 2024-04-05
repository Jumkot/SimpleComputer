#Makefile for simplecomputer
CC = gcc

CFLAGS = -Wall -Werror
FLAGS = -o

APP = console/console
APP_OBJECT = console/console.o
APP_PATH = console/console.c

FONT = console/font
FONT_OBJECT = console/font.o
FONT_PATH = console/font.c

INCLUDE = include
LIB_MSC = mySimpleComputer/libmsc.a
LIB_MT = myTerm/libmt.a
LIB_MT = myBigChar/libmbc.a

all: link
	
link: project
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(APP_OBJECT) $(APP_PATH)
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(FONT_OBJECT) $(FONT_PATH)
	$(CC) $(CFLAGS) $(FLAGS) ./$(APP) $(APP_OBJECT) -Lconsole -LmySimpleComputer -LmyTerm -LmyBigChar -lconsole -lmsc -lmt -lmbc
	$(CC) $(CFLAGS) $(FLAGS) ./$(FONT) $(FONT_OBJECT) -Lconsole -LmySimpleComputer -LmyTerm -LmyBigChar -lconsole -lmsc -lmt -lmbc

project:
	make -C console/
	make -C mySimpleComputer/
	make -C myTerm/
	make -C myBigChar/

run:
	./console/font
	./$(APP) font.bin

clean:
	make clean -C console/
	make clean -C mySimpleComputer/
	make clean -C myTerm/
	make clean -C myBigChar/
	rm -rf $(APP) $(FONT) $(FONT_OBJECT) $(APP_OBJECT) *.bin console/*.bin

.PHONY: all clean 