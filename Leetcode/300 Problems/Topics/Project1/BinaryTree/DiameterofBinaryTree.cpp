// https://leetcode.com/problems/diameter-of-binary-tree/description/
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

int countDiameter(TreeNode *root, int &Max)
{
  if (root == NULL)
    return 0;
  int leftHeight = countDiameter(root->left, Max);
  int rightHeight = countDiameter(root->right, Max);
  Max = max(Max, leftHeight + rightHeight);
  return 1 + max(leftHeight, rightHeight);
}
int diameterOfBinaryTree(TreeNode *root)
{
  int Max = 0;
  countDiameter(root, Max);
  return Max;
}