public class BalancedBinaryTree {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {
        }
        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public boolean isBalanced(TreeNode root) {
        return height(root) != -1;
    }
    public int height(TreeNode root){
        if(root == null) {
            return 0;
        }
        int lh = height(root.left);
        int rh = height(root.right);
        if((lh == -1) || (rh == -1)) return -1;
        if(Math.abs(lh - rh) > 1) return -1;
        return 1 + Math.max(lh,rh);
    }
}

// Current = 1
// Left = F(1) => -1
// Right = F(1)
// left = -1 => return -1;
// Current = 2
// Left = F(2) => 2
// Right = F(2) => 0
// => return -1;
// 	Current = 3
// Left = F(3) => 1
// Right = F(3) => 0
// => return 2
// Current = 4
// Left = F(4) => 0
// Right = F(4) => 0
// => return 1
// Current = NULL -> return 0;
