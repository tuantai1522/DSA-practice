//https://leetcode.com/problems/merge-two-sorted-lists/description/
public class MergeTwoSortedLists {
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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode first_pointer = list1;
        ListNode second_pointer = list2;
        ListNode temp = new ListNode(0);
        ListNode ans = temp;

        while(first_pointer != null && second_pointer != null){
            if(first_pointer.val > second_pointer.val){
                temp.next = second_pointer;
                second_pointer = second_pointer.next;
            }else{
                temp.next = first_pointer;
                first_pointer = first_pointer.next;
            }
            temp = temp.next;
        }
        temp.next = first_pointer == null ? second_pointer : first_pointer;
        return ans.next;
    }
}
