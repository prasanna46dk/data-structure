SRC=src
INCLUDE=include
BIN=bin
OBJFILE=$(BIN)/objects
STRING=$(SRC)/string
LIST=$(SRC)/linklist
SORT=$(SRC)/sorting
CC=gcc -g
CCFLAGS= -Wall -Werror
EXE:=$(shell find $(BIN) -maxdepth 1 -type f -executable)

all: string linklist sort

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
<<<<<<< HEAD

sorting.o:
	$(CC) $(CCFLAGS) -c $(SORT)/sorting.c \
	-o $(OBJFILE)/sorting.o -I $(INCLUDE)

main: string.o linklist.o sorting.o
	$(CC) $(CCFLAGS) $(STRING)/main.c $(OBJFILE)/string.o \
	-o $(BIN)/stringMain -I $(INCLUDE)
	$(CC) $(CCFLAGS) $(LIST)/main.c $(OBJFILE)/linklist.o \
	-o $(BIN)/linklistMain -I $(INCLUDE)
	$(CC) $(CCFLAGS) $(SORT)/main.c $(OBJFILE)/sorting.o \
	-o $(BIN)/sortingMain -I $(INCLUDE)

run:
	@echo -e "\nRunning string programs ...\n"
	$(BIN)/stringMain
	@echo -e "\nRunning linklist programs ...\n"
	$(BIN)/linklistMain
	@echo -e "\nRunning sorting programs ...\n"
=======
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
>>>>>>> 0aa619f921367b91c2b4d39d8deb006f72e8c839
	$(BIN)/sortingMain

clean:
	rm -rv $(EXE) $(OBJFILE)/*
