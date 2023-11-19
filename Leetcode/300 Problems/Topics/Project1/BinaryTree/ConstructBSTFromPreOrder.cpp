// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
TreeNode *bstFromPreorderHelper(vector<int> &preorder, int &index, int upper_bound)
{
  if (index >= preorder.size() || preorder[index] > upper_bound)
  {
    cout << upper_bound << endl;
    cout << "\n-------\n";
    return NULL;
  }
  TreeNode *root = new TreeNode(preorder[index++]);
  root->left = bstFromPreorderHelper(preorder, index, root->val);
  root->right = bstFromPreorderHelper(preorder, index, upper_bound);
  return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
  int index = 0;
  return bstFromPreorderHelper(preorder, index, INT32_MAX);
}