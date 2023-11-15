// https://leetcode.com/problems/binary-tree-right-side-view/
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

vector<int> rightSideView(TreeNode *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;
  queue<QueueNode> my_queue;
  my_queue.push({root, 0, 0});
  map<int, int> my_map;

  while (!my_queue.empty())
  {
    QueueNode ele = my_queue.front();
    my_queue.pop();

    TreeNode *temp = ele.node;
    int x = ele.vertical;
    int y = ele.level;

    if (temp->right != NULL)
    {
      my_queue.push({temp->right, x + 1, y + 1});
    }

    if (temp->left != NULL)
    {
      my_queue.push({temp->left, x - 1, y + 1});
    }

    auto it = my_map.find(y);

    // không tìm thấy
    if (it == my_map.end())
    {
      my_map.insert(make_pair(y, temp->val));
    }
  }

  for (auto it : my_map)
  {
    ans.push_back(it.second);
  }
  return ans;
}