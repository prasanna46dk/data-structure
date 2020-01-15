#include<stdio.h>
#include<stdlib.h>
#include"tree/stack.h"

Stack *createStack(int size)
{
  Stack *stack = (Stack *) malloc(sizeof(Stack *));
  stack -> size = size;
  stack -> top = -1;
  stack -> array = (Node **) malloc(sizeof(stack -> size * sizeof(Node *)));
  return stack;
}

int isFull(Stack *stack)
{
  return (stack -> top == SIZE - 1);
}

int isEmpty(Stack *stack)
{
  return (stack -> top == - 1);
}

void push(Stack *stack, Node* newNode)
{
  if(isFull(stack))
    return;
  stack -> array[++stack -> top] = newNode;
}

void pop(Stack *stack)
{
  if(isEmpty(stack))
    return;
  free(stack -> array[stack -> top--]);
}

Node *top(Stack *stack)
{
  return stack -> array[stack -> top];
}

void deleteStack(Stack *stack)
{
  free(stack);
}
