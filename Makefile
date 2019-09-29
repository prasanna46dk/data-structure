SRC=src
INCLUDE=include
BIN=bin
OBJFILE=$(BIN)/objects
STRING=$(SRC)/string
CC=gcc -g
EXE:=$(shell find $(BIN) -maxdepth 1 -type f -executable)

all: main run

string.o:
	$(CC) -c $(STRING)/string.c -o $(OBJFILE)/string.o -I $(INCLUDE)

main: string.o
	$(CC) $(STRING)/main.c $(OBJFILE)/* -o $(BIN)/main -I $(INCLUDE)

run:
	$(BIN)/main

clean:
	rm -rv $(EXE) $(OBJFILE)/*
