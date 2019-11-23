#include "tree/avl.h"

int main()
{
  int i;
  tree *tRoot = NULL;
  for(i = 0; i < 10; i++)
    tRoot = insert(tRoot, i);

  preOrder(tRoot);
  printf("\n");
  return 0;
}
