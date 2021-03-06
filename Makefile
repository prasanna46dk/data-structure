SRC=src
INCLUDE=include
BIN=bin
OBJFILE=$(BIN)/objects
STRING=$(SRC)/string
LIST=$(SRC)/linklist
SORT=$(SRC)/sorting
TREE=$(SRC)/tree
CC=gcc -g
CCFLAGS= -Wall -Werror
EXE:=$(shell find $(BIN) -maxdepth 1 -type f -executable)

all: string linklist sort tree

string:
	@echo -n "Compiling string programs..."
	@$(CC) $(CCFLAGS) -c $(STRING)/string.c \
	-o $(OBJFILE)/string.o -I $(INCLUDE)
	@$(CC) $(CCFLAGS) $(STRING)/main.c $(OBJFILE)/string.o \
	-o $(BIN)/stringMain -I $(INCLUDE)
	@echo "OK"
	@echo "Running string programs..."
	$(BIN)/stringMain

linklist:
	@echo "Compiling linklist programs..."
	@$(CC) $(CCFLAGS) -c $(LIST)/linklist.c \
	-o $(OBJFILE)/linklist.o -I $(INCLUDE)
	@$(CC) $(CCFLAGS) $(LIST)/main.c $(OBJFILE)/linklist.o \
	-o $(BIN)/linklistMain -I $(INCLUDE)
	@echo "Running linklist programs..."
	@$(BIN)/linklistMain

sort:
	@echo -n "Compiling sorting programs..."
	@$(CC) $(CCFLAGS) -c $(SORT)/sorting.c \
	-o $(OBJFILE)/sorting.o -I $(INCLUDE)
	@$(CC) $(CCFLAGS) $(SORT)/main.c $(OBJFILE)/sorting.o \
	-o $(BIN)/sortingMain -I $(INCLUDE)
	@echo "OK"
	@echo "Running sorting programs..."
	$(BIN)/sortingMain

tree:
	@echo -n "Compiling tree programs..."
	@$(CC) $(CCFLAGS) -c $(TREE)/avl.c \
	-o $(OBJFILE)/avl.o -I $(INCLUDE)
	@$(CC) $(CCFLAGS) $(TREE)/main.c $(OBJFILE)/avl.o \
	-o $(BIN)/avlMain -I $(INCLUDE)
	@echo "OK"
	@echo "Running tree programs..."
	@$(BIN)/avlMain
clean:
	rm -rv $(EXE) $(OBJFILE)/*
