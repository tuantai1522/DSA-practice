// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  // root is p or root is q => return
  if (root == p || root == q)
  {
    return root;
  }

  // p and q is on two sides -> return root;
  if ((p->val < root->val && root->val < q->val) ||
      q->val < root->val && root->val < p->val)
    return root;

  // p and q is on the right
  if (root->val < q->val && root->val < p->val)
    return lowestCommonAncestor(root->right, p, q);

  // p and q is on the left
  return lowestCommonAncestor(root->left, p, q);
}