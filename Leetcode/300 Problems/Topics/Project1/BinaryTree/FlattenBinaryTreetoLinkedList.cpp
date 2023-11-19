// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
using namespace std;
void flatten(TreeNode *root)
{
  TreeNode *curr = root;
  while (curr != NULL)
  {
    while (cur->left != NULL)
    {
      cur = cur->right;
    }

    TreeNode *prev = cur->left;
    while (prev->right != NULL)
    {
      prev = prev->right;
    }
    prev->right = cur->right;
    cur->right = cur->left;
    cur->left = NULL;

    cur = cur->right;
  }
}