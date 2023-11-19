// https://www.interviewbit.com/problems/path-to-given-node/
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

void solveHelper(TreeNode *root, int B, vector<int> &temp, vector<int> &ans)
{
  // create vector temp => it will not add other nodes in the next loop
  if (root == NULL)
    return;

  temp.push_back(root->val);

  if (root->val == B)
  {
    ans = temp;
    return;
  }
  solveHelper(root->left, B, temp, ans);

  solveHelper(root->right, B, temp, ans);
  temp.pop_back();
}
vector<int> solve(TreeNode *root, int B)
{
  vector<int> ans;
  vector<int> temp;
  solveHelper(root, B, temp, ans);

  return ans;
}