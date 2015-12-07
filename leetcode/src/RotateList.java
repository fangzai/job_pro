/**
 * Created by hduser on 15-12-7.
 * Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
 */
import ht.ListNode;
public class RotateList {
    public ListNode rotateRight(ListNode head, int k) {
        return helper(head, k);
    }
    private ListNode helper(ListNode head, int k) {
        if (k <= 0 ||head == null || head.next == null) {
            return head;
        }
        int len = 0;
        ListNode current = head, tail = null;
        while (current != null) {
            len++;
            if (current.next == null) {
                tail = current;
            }
            current = current.next;
        }
        k %= len;
        int i = 0;
        current = head;
        int range = len - k -1;
        while (i < range) {
            current = current.next;
            i++;
        }
        tail.next = head;
        head = current.next;
        current.next = null;
        return head;
    }
}
