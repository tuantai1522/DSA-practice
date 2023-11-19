// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1?utm_source=geeksforgeeks&utm_medium=newui_home&utm_campaign=potd

// pre is before, suc is after

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
  if (root == NULL)
    return;
  findPreSuc(root->left, pre, suc, key);
  if (suc != NULL && root->key > key)
  {
    suc = root;
    return;
  }
  if (root->key < key)
  {
    pre = root;
  }
  findPreSuc(root->right, pre, suc, key);
}