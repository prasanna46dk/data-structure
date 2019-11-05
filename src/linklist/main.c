#include "linklist/linklist.h"
#define INDEX 4
#define NODES 7
#define MIDDLE 100
#define K 5

int main()
{
  unsigned i = 0;
  Node *head = NULL, *headDupList = NULL;
  int dupArr[] = {11, 12, 11, 16, 12, 9, 12};
  while(i++ != NODES)
    head = createList(head, createNode(i));
  printf("Linklist:\n");
  printList(head);
  printf("Node at index %d: %d\n", INDEX, linkListIndexing(head, INDEX));
  printf("Length of Linklist: %d\n",listLength(head));
  printf("Insert Node in middle of LL\n");
  head = insertNodeInMiddle(head, createNode(MIDDLE));
  printList(head);
  printf("Middle node: %d\n",(findMiddle(head)) -> data);
  printf("Reversed Linklist (Iterative):\n");
  head = reverseListIterative(head);
  printList(head);
  printf("Reversed Linklist (Recursive):\n");
  head = reverseListRecursive(head);
  printList(head);
  printf("%d node from end: %d\n", K, kthNodeFromEnd(head, K) -> data);
  for(i = 0; i < NODES; i++)
    headDupList = createList(headDupList, createNode(dupArr[i]));
  printf("\nLinklist with duplicates\n");
  printList(headDupList);
  headDupList = remDup(headDupList);
  printf("Linklist after removing duplicates\n");
  printList(headDupList);
  return 0;
}
