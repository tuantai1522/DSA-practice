public class RemoveNthFromEndOfList {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public static ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null && n == 1) return null;

        int temp = n;
        ListNode first = head;
        ListNode second = head;
        ListNode prev = null;
        while(temp-- > 0){
            second = second.next;
        }

        while(second != null){
            prev = first;
            first = first.next;

            second = second.next;
        }

        //delete at first
        if(prev == null) {
            head = head.next;
        }else{
            prev.next = first.next;
        }
        return head;
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

        ListNode res = removeNthFromEnd(head, 5);

        while(res != null){
            System.out.print(res.val + " ");
            res = res.next;
        }
    }
}
