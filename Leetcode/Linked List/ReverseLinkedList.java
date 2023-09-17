public class ReverseLinkedList {
     public static class ListNode {
         int val;
         ListNode next;
         ListNode() {}
         ListNode(int val) { this.val = val; }
         ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     }
    public static ListNode reverseList(ListNode head) {
        ListNode cur = head;
        ListNode prev = null;
        while(cur != null){
            ListNode next = cur.next;

            cur.next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        ListNode Node1 = new ListNode(2);
        ListNode Node2 = new ListNode(3);
        ListNode Node3 = new ListNode(4);
        ListNode Node4 = new ListNode(5);

        head.next = Node1;
        Node1.next = Node2;
        Node2.next = Node3;
        Node3.next = Node4;

        ListNode res = reverseList(head);

        while(res != null){
            System.out.print(res.val + " ");
            res = res.next;
        }
    }
}
