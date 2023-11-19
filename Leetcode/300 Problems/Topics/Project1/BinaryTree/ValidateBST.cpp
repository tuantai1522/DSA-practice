// https://leetcode.com/problems/validate-binary-search-tree/description/
bool isValidBSTHelper(TreeNode *root, long min, long max)
{
  if (root == NULL)
    return true;

  // if current value extends current range -> false;
  if (root->val <= min || root->val >= max)
    return false;
  bool leftSubTree = isValidBSTHelper(root->left, min, root->val);
  bool rightSubTree = isValidBSTHelper(root->right, root->val, max);

  return leftSubTree && rightSubTree;
}

bool isValidBST(TreeNode *root)
{
  return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}