import java.util.*;

public class BinaryTreeLevelOrderTraversal {
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if(root == null) return result;

        Queue<TreeNode> my_queue = new LinkedList<>();

        my_queue.add(root);

        while(!my_queue.isEmpty()){
            List<Integer> list = new ArrayList<>();

            int length = my_queue.size();

            for(int i = 0; i < length; ++i){

                //to get first element from queue: PEEK
                TreeNode current_node = my_queue.peek();

                //to remove one element from queue: POLL
                list.add(my_queue.poll().val);

                if(current_node.left != null){
                    my_queue.add(current_node.left);
                }

                if(current_node.right != null){
                    my_queue.add(current_node.right);
                }
            }
            result.add(list);
        }
        return result;
    }
}
