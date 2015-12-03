/**
 * Created by hduser on 15-12-3.
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the
 * values in the list, only nodes itself can be changed.
 *
 */
import ht.ListNode;
public class SwapNodesinPairs {
    public ListNode swapPairs(ListNode head) {
        return helper(head);
    }
    private ListNode helper(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode current = new ListNode(Integer.MIN_VALUE);
        current.next = head;
        head = current;
        current = head;  //　添加一个fake　head

        ListNode p1 = null;
        ListNode p2 = null;
        ListNode cache = null;
        while (current.next != null && current.next.next != null) {
            p1 = current.next;
            p2 = p1.next;
            cache = p2.next;

            current.next = p2;
            p2.next = p1;
            p1.next = cache;

            current = p1;
        }
        return head.next;
    }
}
