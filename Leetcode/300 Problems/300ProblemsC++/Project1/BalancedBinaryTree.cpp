// https://leetcode.com/problems/balanced-binary-tree/description/
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

// Balanced BT -> for every node, |height(left) - height(right)| <= 1
int countDepth(TreeNode *root)
{
  if (root == NULL)
    return 0;
  int left = countDepth(root->left);

  // if left subtree is not balanced tree -> then return -1 => don't need to visit right subtree
  if (left == -1)
    return -1;

  int right = countDepth(root->right);

  // if right subtree is not balanced tree -> then return -1 => don't need to visit left subtree
  if (right == -1)
    return -1;

  if (abs(left - right) > 1)
    return -1;
  return 1 + max(left, right);
}
bool isBalanced(TreeNode *root)
{
  if (root == NULL)
    return true;

  return countDepth(root) != -1;
}