public class InvertBinaryTree {
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
    public static TreeNode invertTree(TreeNode root) {
        if (root == null) return null;

        TreeNode left = invertTree(root.left);
        TreeNode right = invertTree(root.right);
        if(left != null){
            System.out.println("Left: " + left.val);
        }

        if(right != null){
            System.out.println("Right: " + right.val);
        }

        System.out.println("-----------------");

        root.left = right;
        root.right = left;

        return root;
    }
}
