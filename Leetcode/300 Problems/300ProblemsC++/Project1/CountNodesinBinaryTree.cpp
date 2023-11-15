// https://leetcode.com/problems/count-complete-tree-nodes/description/
int findLeftHeight(TreeNode *root)
{
  int height = 0;
  while (root)
  {
    height++;
    root = root->left;
  }

  return height;
}

int findRightHeight(TreeNode *root)
{
  int height = 0;
  while (root)
  {
    height++;
    root = root->right;
  }

  return height;
}
int countNodes(TreeNode *root)
{
  if (root == NULL)
    return 0;
  int lh = findLeftHeight(root->left);
  int rh = findRightHeight(root->right);
  if (lh == rh)
    return pow(2, lh + 1) - 1;
  return 1 + countNodes(root->left) + countNodes(root->right);
}