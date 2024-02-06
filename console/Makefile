#Makefile for console
DIR_NAME = console
PART_NAME = test

CC = gcc

CFLAGS = -Wall -Werror 
FLAGS = -o

BUILD_DIR = build

all: dir $(BUILD_DIR)/$(DIR_NAME).a

$(BUILD_DIR)/$(DIR_NAME).a: $(BUILD_DIR)/$(PART_NAME).o
	ar cr $(BUILD_DIR)/$(DIR_NAME).a $(BUILD_DIR)/$(PART_NAME).o

$(BUILD_DIR)/$(PART_NAME).o: $(PART_NAME).c
	$(CC) $(CFLAGS) -c $(PART_NAME).c $(FLAGS) $@

dir:
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*.[ao]
	rmdir $(BUILD_DIR)

.PHONY: all clean 