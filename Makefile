SRC=src
INCLUDE=include
BIN=bin
OBJFILE=$(BIN)/objects
STRING=$(SRC)/string
LIST=$(SRC)/linklist
CC=gcc -g
CCFLAGS= -Wall -Werror
EXE:=$(shell find $(BIN) -maxdepth 1 -type f -executable)

all: main run

string.o:
	$(CC) $(CCFLAGS) -c $(STRING)/string.c \
	-o $(OBJFILE)/string.o -I $(INCLUDE)

linklist.o:
	$(CC) $(CCFLAGS) -c $(LIST)/linklist.c \
	-o $(OBJFILE)/linklist.o -I $(INCLUDE)

main: string.o linklist.o
	$(CC) $(CCFLAGS) $(STRING)/main.c $(OBJFILE)/string.o \
	-o $(BIN)/stringMain -I $(INCLUDE)
	$(CC) $(CCFLAGS) $(LIST)/main.c $(OBJFILE)/linklist.o \
	-o $(BIN)/linklistMain -I $(INCLUDE)

run:
	@echo -e "Running string programs ...\n"
	$(BIN)/stringMain
	@echo -e "Running linklist programs ...\n"
	$(BIN)/linklistMain

clean:
	rm -rv $(EXE) $(OBJFILE)/*
