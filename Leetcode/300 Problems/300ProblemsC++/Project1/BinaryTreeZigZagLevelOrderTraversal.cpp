// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;

  queue<TreeNode *> my_queue;
  my_queue.push(root);
  ans.push_back({root->val});

  int check = 1;

  while (!my_queue.empty())
  {
    int size = my_queue.size();
    vector<int> temp;
    for (int i = 0; i < size; ++i)
    {
      TreeNode *it = my_queue.front();
      if (it->left != NULL)
      {
        temp.push_back(it->left->val);
        my_queue.push(it->left);
      }
      if (it->right != NULL)
      {
        temp.push_back(it->right->val);
        my_queue.push(it->right);
      }

      my_queue.pop();
    }

    if (temp.size() != 0)
    {
      // 1: from right to left => reverse temp
      // 0: from left to right
      if (check == 1)
      {
        reverse(temp.begin(), temp.end());
      }
      ans.push_back(temp);
    }
    check = check == 1 ? 0 : 1;
  }
  return ans;
}