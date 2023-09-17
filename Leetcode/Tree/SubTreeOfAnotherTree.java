public class SubTreeOfAnotherTree {
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

    private boolean isSameTree(TreeNode p, TreeNode q){
        if(p == null && q == null){
            return true;
        }

        if(q == null || p == null || p.val != q.val){
            return false;
        }

        boolean left = isSameTree(p.left, q.left);
        boolean right = isSameTree(p.right, q.right);

        return left && right;
    }
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (isSameTree(root, subRoot)) return true;

        if (root == null) return false;

        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }
}

// isSubtree(4,4)
// Current = (4,4)
// Left = (1,1) => return true;
// 	Left = (N,N) => return true;
// 	Right = (N,N) => return true;
// Right = (2,2) =? Return true;
// 	Left = (N,N) => return true;
// 	Right = (N,N) => return true;

// => return true && true => true;
