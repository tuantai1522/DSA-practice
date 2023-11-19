// https://leetcode.com/problems/symmetric-tree/description/
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

bool isSymmetric(TreeNode *root)
{
  queue<TreeNode *> queueLeft;
  queue<TreeNode *> queueRight;
  if (root->left)
    queueLeft.push(root->left);

  if (root->right)
    queueRight.push(root->right);

  while (!queueLeft.empty() && !queueRight.empty())
  {
    TreeNode *nodeLeft = queueLeft.front();
    queueLeft.pop();

    TreeNode *nodeRight = queueRight.front();
    queueRight.pop();

    if (nodeLeft->val != nodeRight->val)
      return false;

    if (nodeLeft->left && nodeRight->right)
    {
      queueLeft.push(nodeLeft->left);
      queueRight.push(nodeRight->right);
    }
    else if (nodeLeft->left || nodeRight->right)
      return false;

    if (nodeLeft->right && nodeRight->left)
    {
      queueLeft.push(nodeLeft->right);
      queueRight.push(nodeRight->left);
    }
    else if (nodeLeft->right || nodeRight->left)
      return false;
  }

  return queueLeft.size() == queueRight.size();
}