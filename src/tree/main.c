#include"tree/stack.h"

int main(int argc, char *argv[])
{
  Node *head = NULL;
  int i;
  for(i = 1; i < argc; i++) {
    head = createTree(head, createNode(atoi(argv[i])));
  }
  printf("Preorder traversal:\n");
  preorder(head);
  printf("Inorder traversal:\n");
  inorder(head);
  printf("Postorder traversal:\n");
  postorder(head);
  return 0;
}
