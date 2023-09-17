import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class ValidateBinarySearchTree {
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
    List<Integer> list = new ArrayList<>();

    //L - N - R (increasing)
    private void InOrder(TreeNode root){
        if(root == null){
            return;
        }

        InOrder(root.left);
        list.add(root.val);
        InOrder(root.right);
    }
    public boolean isValidBST(TreeNode root) {
        int length = list.size();

        for(int i = 0; i < length - 1; ++i){
            if(list.get(i) >= list.get(i + 1)) return false;
        }

        return true;
    }
}
