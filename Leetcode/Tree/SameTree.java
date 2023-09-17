public class SameTree {
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

    private boolean compareNode(TreeNode p, TreeNode q){
        if(p == null && q == null){
            return true;
        }

        if((p == null) || (q == null)){
            return false;
        }


        if(p.val != q.val) return false;

        boolean left = compareNode(p.left, q.left);
        boolean right = compareNode(p.right, q.right);


        return left && right;
    }

    // 1: same tree; -1: not same tree
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return compareNode(p, q);
    }
}
