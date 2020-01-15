typedef struct tree
{
  int data;
  struct tree *left, *right;
}Node;

void  inorder     (Node *root);
void  preorder    (Node *root);
void  postorder   (Node *root);
Node *createNode  (int data);
Node *createTree  (Node *root, Node *newNode);
