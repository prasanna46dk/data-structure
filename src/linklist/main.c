#include"linklist/linklist.h"

int main()
{
  unsigned i;
  Node *head = NULL;
  for(i = 0; i < 10; i++) {
    head = createList(head, createNode(i));
  }
  printf("Given linklist:\n");
  printList(head);
  printf("Reverse of linklist:\n");
  head = reverseListIterative(head);
  printList(head);
  printf("Reverse of linklist:\n");
  head = reverseListRecursive(head);
  printList(head);
  printf("Length Of list: %d\n",listLength(head));
  return 0;
}
