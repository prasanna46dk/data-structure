#include "tree/avl.h"

tree *createTNode(int iData)
{
  tree *tNode = (tree *) malloc(sizeof(tree));
  tNode->iData = iData;
  tNode->tLeft = tNode->tRight = NULL;
  tNode->iHeight = 1;
  return tNode;
}

int height(tree *tRoot)
{
  if(!tRoot)
    return 0;
  return 1 + max(height(tRoot->tLeft), height(tRoot->tRight));
}

int getBalance(tree *tRoot)
{
  if (!tRoot)
    return 0;
  return (height(tRoot->tLeft) - height(tRoot->tRight));
}
tree *leftRotate(tree *tRoot)
{
  tree *tRightRoot = tRoot->tRight;
  tree *temp = tRightRoot->tLeft;

  tRightRoot->tLeft = tRoot;
  tRoot->tRight = temp;

  tRightRoot->iHeight = 1 + max(height(tRightRoot->tLeft),
				height(tRightRoot->tRight));

  return tRightRoot;
}

tree *rightRotate(tree *tRoot)
{
  tree *tLeftRoot = tRoot->tLeft;
  tree *temp = tLeftRoot->tRight;

  tLeftRoot->tRight = tRoot;
  tRoot->tLeft = temp;

  tLeftRoot->iHeight = 1 + max(height(tLeftRoot->tLeft),
			       height(tLeftRoot->tRight));

  return tLeftRoot;
}

tree *insert(tree *tRoot, int iData)
{
  int iBalence;
  if (!tRoot)
    return createTNode(iData);

  if (tRoot->iData > iData)
    tRoot->tLeft = insert(tRoot->tLeft, iData);
  else if (tRoot->iData < iData)
    tRoot->tRight = insert(tRoot->tRight, iData);
  else
    return tRoot;

  tRoot->iHeight = 1 + max(height(tRoot->tLeft),height(tRoot->tRight));

  iBalence = getBalance(tRoot);

  if (iBalence > 1 &&
      tRoot->tLeft->iData > iData)
    return rightRotate(tRoot);

  if (iBalence < -1 &&
      tRoot->tRight->iData < iData)
    return leftRotate(tRoot);

  if (iBalence > 1 &&
      tRoot->tLeft->iData < iData) {
    tRoot->tLeft = leftRotate(tRoot->tLeft);
    return rightRotate(tRoot);
  }

  if (iBalence < -1 &&
      tRoot->tRight->iData > iData) {
    tRoot->tRight = rightRotate(tRoot->tRight);
    return leftRotate(tRoot);
  }

  return tRoot;
}


void preOrder(tree *tRoot)
{
  if (!tRoot)
    return;
  printf("%d ", tRoot->iData);
  preOrder(tRoot->tLeft);
  preOrder(tRoot->tRight);
}
