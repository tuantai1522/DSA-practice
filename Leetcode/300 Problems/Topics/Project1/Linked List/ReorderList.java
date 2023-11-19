public class ReorderList {
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

    public static void Merge (ListNode first, ListNode second){
        ListNode l1 = first;
        ListNode l2 = second;


        while(first != null){
            ListNode firstNext = first.next;
            ListNode secondNext = second.next;

            first.next = second;

            System.out.println("===========");

            if(firstNext == null) return;

            second.next = firstNext;

            first = firstNext;
            second = secondNext;

        }
    }
    public static void reorderList(ListNode head) {
        if(head == null || head.next == null) return;
        // seperate head from 2 smaller lists
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;

        while(fast != null && fast.next != null){
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = null;

        ListNode l1 = head;

        ListNode l2 = reverseList(slow);

        Merge(l1, l2);
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

        reorderList(head);

        while(head != null){
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
}
