// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  if (root == NULL)
    return NULL;

  if (root == p || root == q)
    return root;

  TreeNode *leftNode = lowestCommonAncestor(root->left, p, q);
  TreeNode *rightNode = lowestCommonAncestor(root->right, p, q);

  if (leftNode && rightNode)
    return root;
  else if (leftNode)
    return leftNode;
  return rightNode;
}