// https://leetcode.com/problems/maximum-width-of-binary-tree/description/\
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
struct Element
{
  TreeNode *node;
  long long index;
};
int widthOfBinaryTree(TreeNode *root)
{
  int width = 0;
  queue<Element> my_queue;
  my_queue.push({root, 0});

  while (!my_queue.empty())
  {
    int first = -1;
    int last = -1;
    int size = my_queue.size();

    int mmin = my_queue.front().index; // first minimum index in queue
    for (int i = 0; i < size; ++i)
    {
      Element temp = my_queue.front();
      my_queue.pop();

      TreeNode *curNode = temp.node;
      long long curIndex = temp.index - mmin;
      if (i == 0)
        first = curIndex;
      if (i == size - 1)
        last = curIndex;

      if (curNode->left)
      {
        my_queue.push({curNode->left, curIndex * 2 + 1});
      }

      if (curNode->right)
      {
        my_queue.push({curNode->right, curIndex * 2 + 2});
      }
    }
    width = max(width, last - first + 1);
  }

  return width;
}