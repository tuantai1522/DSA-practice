// https://leetcode.com/problems/same-tree/description/
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

bool isSameTree(TreeNode *p, TreeNode *q)
{
  // Nếu 1 cái NULL, kiểm tra xem cái còn lại có NULL luôn hay ko
  //  => nếu có là true, ngược lại false;
  if (p == NULL || q == NULL)
  {
    return p == q;
  }
  bool leftHeight = isSameTree(p->left, q->left);
  bool rightHeight = isSameTree(p->right, q->right);

  // Tới đây là phải so sánh 2 giá trị có giống nhau hay ko
  return p->val == q->val && leftHeight && rightHeight;
}