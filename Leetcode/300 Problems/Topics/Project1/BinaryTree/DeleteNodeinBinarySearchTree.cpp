// https://leetcode.com/problems/delete-node-in-a-bst/
TreeNode *deleteNode(TreeNode *root, int key)
{
  if (root == NULL)
    return NULL;

  if (root->val == key)
    return helper(root);

  TreeNode *temp = root;
  while (temp)
  {
    if (key < temp->val)
    {
      if (temp->left && temp->left->val == key)
      {
        temp->left = helper(temp->left);
        break;
      }
      else
      {
        temp = temp->left;
      }
    }
    else if (key > temp->val)
    {
      if (temp->right && temp->right->val == key)
      {
        temp->right = helper(temp->right);
        break;
      }
      else
      {
        temp = temp->right;
      }
    }
  }

  return root;
}

TreeNode *helper(TreeNode *root)
{
  // Node cần xóa có 1 con
  if (root->left == NULL)
    return root->right;

  if (root->right == NULL)
    return root->left;

  // Node cần xóa có 2 con: nối Node con "cuối cùng bên phải"
  // của cây con bên trái với node "đầu của cây con bên phải"

  TreeNode *rightChild = root->right;
  TreeNode *lastChild = findMostRightNodeInLeftSubTree(root->left);

  lastChild->right = rightChild;

  // trả về node bên trái để nối với node ở phần function chính
  return root->left;
}
TreeNode *findMostRightNodeInLeftSubTree(TreeNode *root)
{
  if (root->right == NULL)
    return root;
  return findMostRightNodeInLeftSubTree(root->right);
}