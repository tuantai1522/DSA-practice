// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
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
struct QueueNode
{
  TreeNode *node;
  int vertical;
  int level;

  QueueNode(TreeNode *n, int v, int l) : node(n), vertical(v), level(l) {}
};
vector<vector<int>> verticalTraversal(TreeNode *root)
{
  if (root == NULL)
    return {};

  map<int, map<int, multiset<int>>> matrix;
  queue<QueueNode> my_queue;
  my_queue.push(QueueNode(root, 0, 0));
  while (!my_queue.empty())
  {
    QueueNode currentElement = my_queue.front();
    my_queue.pop();

    TreeNode *curNode = currentElement.node;
    int x = currentElement.vertical;
    int y = currentElement.level;

    matrix[x][y].insert(curNode->val);

    if (curNode->left != NULL)
    {
      my_queue.push(QueueNode(curNode->left, x - 1, y + 1));
    }

    if (curNode->right != NULL)
    {
      my_queue.push(QueueNode(curNode->right, x + 1, y + 1));
    }
  }

  vector<vector<int>> ans;
  for (auto it : matrix)
  {
    vector<int> col;
    for (auto p : it.second)
      col.insert(col.end(), p.second.begin(), p.second.end());
    ans.push_back(col);
  }
  return ans;
}