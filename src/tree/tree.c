#include"tree/stack.h"

Node *createNode(int data)
{
  Node *newNode = (Node*) malloc(sizeof(Node*));
  newNode -> data = data;
  newNode -> left = NULL;
  newNode -> right = NULL;
  return newNode;
}

Node *createTree(Node *root, Node *newNode)
{
  if(!root)
    return newNode;
  Node *temp = root, *parent;
  while(temp) {
    parent = temp;
    if(newNode -> data <= root -> data)
      temp = temp -> left;
    else
      temp = temp -> right;
  }
  if(newNode -> data <= parent -> data)
    parent -> left = newNode;
  else
    parent -> right = newNode;
  return root;
}

void preorder(Node *root)
{
  Stack *s = createStack(SIZE);
  while(root) {
    printf("%d", root ->data);
    root = root -> left;
  }

  if(isEmpty(s))
    return;

  root = top(s);
  pop(s);
  root = root -> right;
  deleteStack(s);
}
 void inorder(Node *root)
{
  Stack *s = createStack(SIZE);
  while(root) {
    root = root -> left;
  }

  if(isEmpty(s))
    return;

  root = top(s);
  pop(s);
  printf("%d", root -> data);
  root = root -> right;
  deleteStack(s);
}

void postorder(Node *root)
{
  Stack *s = createStack(SIZE);
  while(1) {
    while (root) {
      if(root -> right)
	push(s, root -> right);
      push(s, root);
      root = root -> left;
    }

    if(isEmpty(s))
      return;

    root = top(s);
    pop(s);
    if(root -> right && top(s) == root -> right) {
      printf("%d", top(s) -> data);
      pop(s);
      push(s, root);
    }
    else {
      printf("%d", root -> data);
      root = NULL;
    }
  }
}
