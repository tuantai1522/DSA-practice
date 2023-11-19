// https://leetcode.com/problems/insert-into-a-binary-search-tree/
TreeNode *insertIntoBST(TreeNode *root, int x)
{
  TreeNode *cur = root;
  TreeNode *newNode = new TreeNode(x);
  if (root == NULL)
  {
    root = newNode;
    return root;
  }

  while (cur != NULL)
  {
    if (x < cur->val)
    {
      if (cur->left != NULL)
        cur = cur->left;
      else
      {
        cur->left = newNode;
        break;
      }
    }
    else if (x > cur->val)
    {
      if (cur->right != NULL)
        cur = cur->right;
      else
      {
        cur->right = newNode;
        break;
      }
    }
  }
  return root;
}