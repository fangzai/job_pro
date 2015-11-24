/**
 * Created by hduser on 15-11-23.
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */
import ht.ListNode;

public class MergeTwoSortedLists {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        return helper(l1, l2);
    }
    private ListNode helper(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        ListNode head = new ListNode(Integer.MAX_VALUE);
        ListNode cur1 = l1, cur2 = l2;
        ListNode current = head;
        int num1 = 0, num2 = 0;
        while (cur1 != null || cur2 != null) {
            num1 = Integer.MAX_VALUE;
            num2 = Integer.MAX_VALUE;
            if (cur1 != null) {
                num1 = cur1.val;
            }
            if (cur2 != null) {
                num2 = cur2.val;
            }
            if (num1 < num2) {
               current.next = cur1;
                cur1 = cur1.next;
            } else {
                current.next = cur2;
                cur2 = cur2.next;
            }
            current = current.next;
        }
        return head.next;
    }
}
