// https://leetcode.com/problems/binary-tree-inorder-traversal/
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> inorderTraversal(TreeNode *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;
  TreeNode *cur = root;
  while (cur != NULL)
  {
    if (cur->left)
    {
      TreeNode *prev = cur->left;
      while (prev->right && prev->right != cur)
      {
        prev = prev->right;
      }

      // prev is pointing to cur -> have previously visited
      if (prev->right)
      {
        prev->right = NULL;
        ans.push_back(cur->val);
        cur = cur->right;
      }
      else
      {
        prev->right = cur;
        cur = cur->left;
      }
    }
    else
    {
      ans.push_back(cur->val);
      cur = cur->right;
    }
  }

  return ans;
}