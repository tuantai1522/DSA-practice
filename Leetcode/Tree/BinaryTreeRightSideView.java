import java.util.*;

public class BinaryTreeRightSideView {
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

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> my_queue = new LinkedList<>();
        my_queue.add(root);

        while (!my_queue.isEmpty()) {

            int length = my_queue.size();

            //to get one element from queue: PEEK
            result.add(my_queue.peek().val);

            for(int i = 0; i < length; ++i){

                //to remove first element from queue: POLL
                TreeNode current_node = my_queue.poll();

                if(current_node.right != null){
                    my_queue.add(current_node.right);
                }

                if(current_node.left != null){
                    my_queue.add(current_node.left);
                }
            }
        }
        return result;
    }
}
