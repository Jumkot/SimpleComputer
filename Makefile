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

SA = simpleassembler/sat
SA_OBJECT = simpleassembler/main_sa.o 
SA_PATH = simpleassembler/main_sa.c

INCLUDE = include
LIB_MSC = mySimpleComputer/libmsc.a
LIB_MT = myTerm/libmt.a
LIB_MT = myBigChar/libmbc.a
LIB_MT = myReadKey/libmrk.a

LIB_SA = simpleassembler/libsa.a

all: link
	
link: project
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(APP_OBJECT) $(APP_PATH)
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(FONT_OBJECT) $(FONT_PATH)
	$(CC) $(CFLAGS) -c -I./include $(FLAGS) $(SA_OBJECT) $(SA_PATH)
	$(CC) $(CFLAGS) $(FLAGS) ./$(APP) $(APP_OBJECT) -Lconsole -LmySimpleComputer -LmyTerm -LmyBigChar -LmyReadKey -lconsole -lmsc -lmt -lmbc -lmrk
	$(CC) $(CFLAGS) $(FLAGS) ./$(FONT) $(FONT_OBJECT) -Lconsole -LmySimpleComputer -LmyTerm -LmyBigChar -LmyReadKey -lconsole -lmsc -lmt -lmbc -lmrk
	$(CC) $(CFLAGS) $(FLAGS) ./$(SA) $(SA_OBJECT) -Lsimpleassembler -LmySimpleComputer -lsa -lmsc

project:
	make -C console/
	make -C mySimpleComputer/
	make -C myTerm/
	make -C myBigChar/
	make -C myReadKey/
	make -C simpleassembler/

run:
	./console/font
	./$(SA) sa_test.sa sa_test.o
	./$(APP) sa_test.o

clean:
	make clean -C console/
	make clean -C mySimpleComputer/
	make clean -C myTerm/
	make clean -C myBigChar/
	make clean -C myReadKey/
	make clean -C simpleassembler/
	rm -rf $(APP) $(FONT) $(FONT_OBJECT) $(APP_OBJECT) font.bin

.PHONY: all clean 