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

all: createProject string linklist sort tree

createProject:
	mkdir -p $(OBJFILE)

string:
	@echo "Compiling string programs..."
	@$(CC) $(CCFLAGS) -c $(STRING)/string.c \
	-o $(OBJFILE)/string.o -I $(INCLUDE)
	@$(CC) $(CCFLAGS) $(STRING)/main.c $(OBJFILE)/string.o \
	-o $(BIN)/stringMain -I $(INCLUDE)
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
	@echo "Compiling sorting programs..."
	@$(CC) $(CCFLAGS) -c $(SORT)/sorting.c \
	-o $(OBJFILE)/sorting.o -I $(INCLUDE)
	@$(CC) $(CCFLAGS) $(SORT)/main.c $(OBJFILE)/sorting.o \
	-o $(BIN)/sortingMain -I $(INCLUDE)
	@echo "Running sorting programs..."
	$(BIN)/sortingMain

tree:
	@echo "Compiling tree programs..."
	@$(CC) $(CCFLAGS) -c $(TREE)/tree.c \
	-o $(OBJFILE)/tree.o -I $(INCLUDE)
	@$(CC) $(CCFLAGS) -c $(TREE)/stack.c \
	-o $(OBJFILE)/stack.o -I $(INCLUDE)
	@$(CC) $(CCFLAGS) $(TREE)/main.c \
	$(OBJFILE)/tree.o \
	$(OBJFILE)/stack.o \
	-o $(BIN)/treeMain -I $(INCLUDE)
	@echo "Running tree programs..."
	$(BIN)/treeMain 8 9 13 16 47 20 1 88 34 90

clean:
	rm -rv $(EXE) $(OBJFILE)/*
