// https://leetcode.com/problems/binary-search-tree-iterator/description/

// Store all elements in vector "InOrder"
class BSTIterator
{
public:
  int curIndex = 0;
  vector<int> order;
  void InOrder(TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }
    InOrder(root->left);
    order.push_back(root->val);
    InOrder(root->right);
  }
  BSTIterator(TreeNode *root)
  {
    InOrder(root);
  }

  int next()
  {
    if (curIndex < order.size())
    {
      return order[curIndex++];
    }
    return -1;
  }

  bool hasNext()
  {
    return curIndex < order.size();
  }
};

// Store ony left elements
class BSTIterator
{
public:
  stack<TreeNode *> my_stack;
  void moveToLeft(TreeNode *root)
  {
    TreeNode *cur = root;
    while (cur != NULL)
    {
      my_stack.push(cur);
      cur = cur->left;
    }
  }
  BSTIterator(TreeNode *root)
  {
    moveToLeft(root);
  }

  int next()
  {
    TreeNode *node = my_stack.top();
    my_stack.pop();

    moveToLeft(node->right);
    return node->val;
  }

  bool hasNext()
  {
    return !my_stack.empty();
  }
};