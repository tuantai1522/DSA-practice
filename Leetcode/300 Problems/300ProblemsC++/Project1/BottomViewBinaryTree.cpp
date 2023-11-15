// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
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

vector<int> bottomView(Node *root)
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

    // move to bottom -> change current vertical to a new one
    my_map[x] = temp->data;
  }

  for (auto it : my_map)
  {
    ans.push_back(it.second);
  }
  return ans;
}