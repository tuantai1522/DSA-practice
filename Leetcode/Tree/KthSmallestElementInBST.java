import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class KthSmallestElementInBST {
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
    //In order
    List<Integer> list  = new ArrayList<>();
    void InOrder(TreeNode root){
        if(root == null) {
            return;
        }
        InOrder(root.left);
        list.add(root.val);
        InOrder(root.right);
    }
    public int kthSmallest(TreeNode root, int k) {
        InOrder(root);
        return list.get(k - 1);
    }

    public static void main(String[] args) {
        int [] arr = {1,2,3,4,5};
        int [] copyArr = Arrays.copyOfRange(arr, 1, 1);

        for(int i = 0; i < copyArr.length; ++i){
            System.out.println(copyArr[i]);
        }

    }
}
