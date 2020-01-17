#include"tree/stack.h"
#include "tree/avl.h"

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

  tree *tRoot = NULL;
  for(i = 0; i < 10; i++)
    tRoot = insert(tRoot, i);

  preOrder(tRoot);
  printf("\n");
  return 0;
}
