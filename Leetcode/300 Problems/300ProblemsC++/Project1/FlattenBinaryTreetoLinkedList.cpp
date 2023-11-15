// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
using namespace std;
void flatten(TreeNode *root)
{
  TreeNode *curr = root;
  while (curr != NULL)
  {
    if (curr->left)
    {
      TreeNode *prev = curr->left;
      while (prev->right)
      {
        prev = prev->right;
      }

      prev->right = curr->right;
      curr->right = curr->left;
      curr->left = NULL;
    }
    curr = curr->right;
  }
}