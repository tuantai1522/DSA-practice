public class AddTwoNumbers {
    public static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode temp = new ListNode();
        ListNode result = temp;

        int remainder = 0;
        while(l1 != null || l2 != null){
            int firstNumber = l1 != null ? l1.val : 0;
            int secondNumber = l2 != null ? l2.val : 0;

            int count = firstNumber + secondNumber + remainder;
            int number = count % 10;
            remainder = number / 10;


            temp.next = new ListNode(number);

            temp = temp.next;
            if(l1 != null) l1 = l1.next;
            if(l2 != null)  l2 = l2.next;
        }


        return result.next;
    }

    public static void main(String[] args) {
        ListNode Node1 = new ListNode(1);
        ListNode Node2 = new ListNode(2);
        ListNode Node3 = new ListNode(4);


        ListNode Node4 = new ListNode(1);
        ListNode Node5 = new ListNode(3);
        ListNode Node6 = new ListNode(4);

        Node1.next = Node2;
        Node2.next = Node3;

        Node4.next = Node5;
        Node5.next = Node6;

        ListNode result = addTwoNumbers(Node1, Node4);

        while(result != null){
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
