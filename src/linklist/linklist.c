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

int linkListIndexing(Node* head, int i)
{
  int index = 0;
  Node *current = head;
  while(index++ != i) {
    current = current -> next;
  }
  return current -> data;
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

Node *insertNodeInMiddle(Node *head, Node *newNode)
{
  Node *slowPtr = NULL, *fastPtr = NULL;
  if(!head)
    return newNode;
  if(!head -> next) {
    newNode -> next = head;
    return newNode;
  }
  slowPtr = head;
  fastPtr = head -> next;
  while(fastPtr -> next && fastPtr -> next -> next) {
    slowPtr = slowPtr -> next;
    fastPtr = fastPtr -> next -> next;
  }
  newNode -> next = slowPtr ->next;
  slowPtr -> next = newNode;
  return head;
}

Node *findMiddle(Node *head)
{
  Node *slowPtr = head, *fastPtr = head;
  while(fastPtr && fastPtr -> next && fastPtr -> next -> next) {
    slowPtr = slowPtr -> next;
    fastPtr = fastPtr -> next -> next;
  }
  return slowPtr;
}

Node *checkIfLoop(Node *head)
{
  Node *slowPtr = head, *fastPtr = head;
  while(slowPtr && fastPtr && fastPtr->next) {
    slowPtr = slowPtr -> next;
    fastPtr = fastPtr -> next -> next;
    if(slowPtr == fastPtr)
      {
	removeLoop(head, slowPtr);
	return slowPtr;
      }
  }
  return NULL;
}

Node *removeLoop(Node *head, Node *loopNode)
{
  Node *p = head;
  while(p -> next != loopNode)
    p = p -> next;
  p ->next = NULL;
  return head;
}

//remove duplicates from unsorted ll
Node *remDup(Node *head)
{
  Node *p = head, *q = NULL, *prev = NULL;
  while(p) {
    prev = p;
    q = p -> next;
    while(q) {
      if(p -> data == q -> data)
	{
	  prev -> next = q -> next;
	  q -> next = NULL;
	  free(q);
	  q = prev -> next;
	}
      else
	{
	prev = q;
	q = q-> next;
	}
    }
    p = p ->next;
  }
  return head;
}

//Kth node from end
Node *kthNodeFromEnd(Node *head, int k)
{
  Node *slowPtr = head, *fastPtr = head;
  int i = 0;
  while((i++ != k) && fastPtr) {
    fastPtr = fastPtr -> next;
  }
  if(!fastPtr)
    return NULL;
  while(fastPtr) {
    slowPtr = slowPtr -> next;
    fastPtr = fastPtr -> next;
  }
  return slowPtr;
}

/* void nthNodeFromLast(Node *head, unsigned n) */
/* { */
/*   unsigned len = listLength(head); */
/*   if(len < n) */
/*     return; */
/* } */
