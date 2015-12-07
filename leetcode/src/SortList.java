/**
 * Created by hduser on 15-12-7.
 * Sort a linked list in O(n log n) time using constant space complexity.
 */
import ht.ListNode;
public class SortList {
    public ListNode sortList(ListNode head) {
        return helper(head);
    }
    private ListNode helper(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        } else {
            ListNode slow = findMid(head);
            ListNode l1 = head;
            ListNode l2 = slow.next;
            slow.next = null;
            l1 = helper(l1);
            l2 = helper(l2);
            return merge(l1, l2);
        }
    }
    private ListNode findMid(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            if (fast != null) {
                slow = slow.next;
            }
        }
        return slow;
    }
    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(Integer.MIN_VALUE);
        int val1, val2;
        ListNode current = head;
        while (l1 != null || l2 != null) {
            val1 = (l1 == null) ? Integer.MAX_VALUE : l1.val;
            val2 = (l2 == null) ? Integer.MAX_VALUE : l2.val;
            if (val1 < val2) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        return head.next;
    }
}
