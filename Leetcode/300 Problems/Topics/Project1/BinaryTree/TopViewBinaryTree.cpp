// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/0
#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;
};

struct QueueNode
{
  Node *node;
  int vertical;
  int level;

  QueueNode(Node *n, int v, int l) : node(n), vertical(v), level(l) {}
};

vector<int> topView(Node *root)
{
  vector<int> ans;
  queue<QueueNode> my_queue;
  my_queue.push({root, 0, 0});
  map<int, int> my_map;

  while (!my_queue.empty())
  {
    QueueNode ele = my_queue.front();
    my_queue.pop();

    Node *temp = ele.node;
    int x = ele.vertical;
    int y = ele.level;

    if (temp->left != NULL)
    {
      my_queue.push({temp->left, x - 1, y + 1});
    }

    if (temp->right != NULL)
    {
      my_queue.push({temp->right, x + 1, y + 1});
    }

    auto it = my_map.find(x);

    // không tìm thấy
    if (it == my_map.end())
    {
      my_map.insert(make_pair(x, temp->data));
    }
  }

  for (auto it : my_map)
  {
    ans.push_back(it.second);
  }
  return ans;
}