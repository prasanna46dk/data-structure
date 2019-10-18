#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
typedef struct node {
  int data;
  struct node *next;
} Node;

typedef enum {false, true} bool;
Node *createNode(int data);
Node *createList(Node *head, Node *newNode);
unsigned listLength(Node *head);
void printNode(Node *node);
void printList(Node *head);
Node *reverseListIterative(Node *head);
Node *reverseListRecursive(Node *head);
bool findLoop(Node *head);
