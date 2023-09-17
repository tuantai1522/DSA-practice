public class CountGoodNodes {
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
    private int builder(TreeNode root, int max){
        if (root == null) return 0;

        int res = root.val >= max ? 1 : 0;

        res += builder(root.left, Math.max(root.val, max));
        res += builder(root.right, Math.max(root.val, max));

        return res;
    }
    public int goodNodes(TreeNode root) {
        return builder(root, root.val);
    }
}

// 1.F(3, 3)
// Res = 1
    // Res += F(1, 3)
    // F(1,3)
    // Res = 0;
        // Res += F(3, 3)
        // Res = 1
        // Res += F(N, 3) => return 0;
        // Res += F(N, 3) => return 0;
        // Res += F(N, 3) => return 0;
    // Res += F(4, 3)
    // Res = 1
        // Res = F(1,4)
        // Res = 0
        // Res = F(5,4)
        // Res = 1

// Return res(4)
