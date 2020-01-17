#ifndef AVL_H
#define AVL_H

#include<stdio.h>
#include<stdlib.h>

#define max(x, y) (x > y ? x : y)

typedef struct treeNode {
  int iData, iHeight;
  struct treeNode *tLeft, *tRight;
}tree;

tree *createTNode(int iData);
int height(tree *tRoot);
int getBalance(tree *tRoot);
tree *leftRoatate(tree *tRoot);
tree *rightRotate(tree *tRoot);
tree *insert(tree *tRoot, int iData);
void preOrder(tree *tRoot);

#endif  // AVL_H
