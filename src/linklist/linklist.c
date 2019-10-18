#include "linklist/linklist.h"

Node *createNode(int data)
{
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

Node *createList(Node *head, Node *newNode)
{
  Node *temp = head;
  if(!head && !newNode)
    return NULL;
  else if(!head)
    return newNode;

  while(temp->next)
    temp = temp->next;
  temp->next = newNode;
  return head;
}

unsigned listLength(Node *head)
{
  Node *temp = head;
  unsigned length = 0;

  while(temp) {
    length++;
    temp = temp->next;
  }
  return length;
}

void printNode(Node *node)
{
  if(!node){
    printf("NULL\n");
    return;
  }
  printf("%d\n",node->data);
}

void printList(Node *head)
{
  Node *temp = head;
  if(!head){
    printf("NULL\n");
    return;
  }
  while(temp){
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

Node *reverseListIterative(Node *head)
{
  Node *prev = NULL, *cur = head, *next;
  while(cur) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

Node *reverseListRecursive(Node *head)
{
  Node *secondElem, *rest;
  if(!head || !head->next)
    return head;

  secondElem = head->next;
  head->next = NULL;
  rest = reverseListRecursive(secondElem);
  secondElem->next = head;
  return rest;
}

bool findLoop(Node *head)
{
  Node *fast = head, *slow = head;
  if(!head)
    return true;

  while(slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast)
      return false;
  }
  return true;
}

/* void nthNodeFromLast(Node *head, unsigned n) */
/* { */
/*   unsigned len = listLength(head); */
/*   if(len < n) */
/*     return; */
/* } */
