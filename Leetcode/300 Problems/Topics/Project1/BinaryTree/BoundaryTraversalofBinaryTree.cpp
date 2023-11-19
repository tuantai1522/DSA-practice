// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0
#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left, *right;
};
bool isleaf(Node *root)
{
  // ko có nút con trai và nút con phải
  if (!root->left && !root->right)
    return true;
  return false;
}
void addLeftBoundary(Node *root, vector<int> &ans)
{
  Node *cur = root->left;
  // if node is leaf node -> break
  while (cur)
  {
    if (!isleaf(cur))
    {
      ans.push_back(cur->data);
    }
    if (cur->left)
    {
      cur = cur->left;
    }
    else
    {
      cur = cur->right;
    }
  }
}

void addLeafNode(Node *root, vector<int> &ans)
{
  if (isleaf(root))
  {
    ans.push_back(root->data);
    return;
  }
  if (root->left)
    addLeafNode(root->left, ans);
  if (root->right)
    addLeafNode(root->right, ans);
}
void addRightBoundary(Node *root, vector<int> &ans)
{
  int size = ans.size();
  Node *cur = root->right;
  // if node is leaf node -> break
  while (cur)
  {
    if (!isleaf(cur))
    {
      ans.push_back(cur->data);
    }
    if (cur->right)
    {
      cur = cur->right;
    }
    else
    {
      cur = cur->left;
    }
  }
  // reverse from top to bottom
  reverse(ans.begin() + size, ans.end());
}
vector<int> boundary(Node *root)
{
  vector<int> ans;
  if (!isleaf(root))
    ans.push_back(root->data);
  addLeftBoundary(root, ans);
  addLeafNode(root, ans);
  addRightBoundary(root, ans);
  return ans;
}