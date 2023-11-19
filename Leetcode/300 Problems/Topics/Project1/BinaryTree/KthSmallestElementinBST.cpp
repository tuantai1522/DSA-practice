// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
void InOrder(TreeNode *root, int k, vector<int> &inorder, int &ans)
{
  if (root == NULL)
  {
    return;
  }
  InOrder(root->left, k, inorder, ans);

  inorder.push_back(root->val);
  if (inorder.size() == k)
  {
    ans = root->val;
    return;
  }

  InOrder(root->right, k, inorder, ans);
}
int kthSmallest(TreeNode *root, int k)
{
  vector<int> inorder;
  int ans = -1;
  InOrder(root, k, inorder, ans);

  return ans;
}