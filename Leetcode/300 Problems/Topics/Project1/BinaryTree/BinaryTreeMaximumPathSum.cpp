// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#include <bits/stdc++.h>
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

int findMaximumPathSum(TreeNode *root, int &Max)
{
  if (root == NULL)
    return 0;

  // don't take value < 0
  int leftHeight = max(0, findMaximumPathSum(root->left, Max));
  int rightHeight = max(0, findMaximumPathSum(root->right, Max));
  Max = max(Max, leftHeight + rightHeight + root->val);

  return root->val + max(leftHeight, rightHeight);
}
int maxPathSum(TreeNode *root)
{
  int Max = INT_MIN;
  findMaximumPathSum(root, Max);
  return Max;
}