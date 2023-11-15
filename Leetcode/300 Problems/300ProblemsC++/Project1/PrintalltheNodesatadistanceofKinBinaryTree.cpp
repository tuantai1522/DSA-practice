// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
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

void findParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
{
  queue<TreeNode *> my_queue;
  my_queue.push(root);
  while (!my_queue.empty())
  {
    TreeNode *node = my_queue.front();
    my_queue.pop();

    if (node->left)
    {
      parent_track[node->left] = node;
      my_queue.push(node->left);
    }
    if (node->right)
    {
      parent_track[node->right] = node;
      my_queue.push(node->right);
    }
  }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
  unordered_map<TreeNode *, TreeNode *> parent_track;
  findParents(root, parent_track);

  // true is visited
  unordered_map<TreeNode *, bool> visited;

  queue<TreeNode *> my_queue;
  my_queue.push(target);
  visited[target] = true;
  int curDistance = 0;
  while (!my_queue.empty())
  {
    int size = my_queue.size();
    if (curDistance == k)
      break;

    while (size--)
    {
      TreeNode *node = my_queue.front();
      my_queue.pop();

      // at target node, we only move topward, left and right
      if (node->left && !visited[node->left])
      {
        visited[node->left] = true;
        my_queue.push(node->left);
      }

      if (node->right && !visited[node->right])
      {
        visited[node->right] = true;
        my_queue.push(node->right);
      }

      if (parent_track[node] && !visited[parent_track[node]])
      {
        visited[parent_track[node]] = true;
        my_queue.push(parent_track[node]);
      }
    }
    ++curDistance;
  }

  vector<int> ans;
  while (!my_queue.empty())
  {
    ans.push_back(my_queue.front()->val);
    my_queue.pop();
  }

  return ans;
}