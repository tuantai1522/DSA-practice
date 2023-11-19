public class Merge2SortedLists {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null && list2 == null) return null;


        ListNode temp = new ListNode();
        ListNode result = temp;

        while(list1 != null && list2 != null){
            if(list1.val <= list2.val) {
                temp.next = list1;
                list1 = list1.next;
            }else {
                temp.next = list2;
                list2 = list2.next;
            }
            temp = temp.next;

        }

        temp.next = list1 == null ? list2 : list1;

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

        ListNode result = mergeTwoLists(Node1, Node4);

        while(result != null){
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
