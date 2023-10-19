//https://leetcode.com/problems/middle-of-the-linked-list/description/
public class MiddleOftheLinkedList {
      public class ListNode {
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
    public ListNode middleNode_1(ListNode head) {
          int size = 0;
          ListNode temp = head;
          while(temp != null){
              ++size;
              temp = temp.next;
          }

          temp = head;
          for(int i = 0; i < size / 2; ++i){
              temp = temp.next;
          }
          return temp;
    }

    public ListNode middleNode_2(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(slow != null && fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }
}
