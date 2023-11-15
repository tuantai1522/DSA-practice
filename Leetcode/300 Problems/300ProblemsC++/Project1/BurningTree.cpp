// https://practice.geeksforgeeks.org/problems/burning-tree/1

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

Node *findParentsAndTargetNode(Node *root, unordered_map<Node *, Node *> &parent_track, int target)
{
  queue<Node *> my_queue;
  my_queue.push(root);
  Node *temp = new Node(-1);
  while (!my_queue.empty())
  {
    Node *node = my_queue.front();
    my_queue.pop();

    if (node->data == target)
    {
      temp = node;
    }
    if (node->left)
    {
      my_queue.push(node->left);
      parent_track[node->left] = node;
    }

    if (node->right)
    {
      my_queue.push(node->right);
      parent_track[node->right] = node;
    }
  }
  return temp;
}
int minTime(Node *root, int val)
{
  unordered_map<Node *, Node *> parent_track;
  Node *target = findParentsAndTargetNode(root, parent_track, val);

  // to find min time
  int time = 0;
  queue<Node *> my_new_queue;
  my_new_queue.push(target);
  unordered_map<Node *, bool> visited;
  visited[target] = true;

  while (!my_new_queue.empty())
  {
    int size = my_new_queue.size();
    bool check = false;
    while (size--)
    {
      Node *node = my_new_queue.front();
      my_new_queue.pop();

      if (node->left && !visited[node->left])
      {
        visited[node->left] = true;
        my_new_queue.push(node->left);
        check = true;
      }

      if (node->right && !visited[node->right])
      {
        visited[node->right] = true;
        my_new_queue.push(node->right);
        check = true;
      }

      if (parent_track[node] && !visited[parent_track[node]])
      {
        visited[parent_track[node]] = true;
        my_new_queue.push(parent_track[node]);
        check = true;
      }
    }
    if (check)
      ++time;
  }

  return time;
}
