#Makefile for simplecomputer
CC = gcc

CFLAGS = -Wall -Werror
FLAGS = -o

APP = console/main
APP_OBJECT = console/main.o
APP_PATH = console/main.c

FONT = console/font
FONT_OBJECT = console/font.o
FONT_PATH = console/font.c

INCLUDE = include
LIB_MSC = mySimpleComputer/libmsc.a
LIB_MT = myTerm/libmt.a
LIB_MT = myBigChar/libmbc.a
LIB_MT = myReadKey/libmrk.a

all: link
	
link: project
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(APP_OBJECT) $(APP_PATH)
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(FONT_OBJECT) $(FONT_PATH)
	$(CC) $(CFLAGS) $(FLAGS) ./$(APP) $(APP_OBJECT) -Lconsole -LmySimpleComputer -LmyTerm -LmyBigChar -LmyReadKey -lconsole -lmsc -lmt -lmbc -lmrk
	$(CC) $(CFLAGS) $(FLAGS) ./$(FONT) $(FONT_OBJECT) -Lconsole -LmySimpleComputer -LmyTerm -LmyBigChar -LmyReadKey -lconsole -lmsc -lmt -lmbc -lmrk

project:
	make -C console/
	make -C mySimpleComputer/
	make -C myTerm/
	make -C myBigChar/
	make -C myReadKey/

run:
	./console/font
	./$(APP) font.bin

clean:
	make clean -C console/
	make clean -C mySimpleComputer/
	make clean -C myTerm/
	make clean -C myBigChar/
	make clean -C myReadKey/
	rm -rf $(APP) $(FONT) $(FONT_OBJECT) $(APP_OBJECT) font.bin

.PHONY: all clean 