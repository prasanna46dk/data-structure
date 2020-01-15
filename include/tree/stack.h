#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

#define SIZE 10

typedef struct Stack {
    Node **array;
    int size;
    int top;
}Stack;

Stack *createStack  (int size);
void   push         (Stack *stack, Node *newNode);
void   pop          (Stack *stack);
Node  *top          (Stack *stack);
void   deleteStack  (Stack *stack);
int    isEmpty      (Stack *stack);
int    isFull       (Stack *stack);
