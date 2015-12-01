/**
 * Created by hduser on 15-12-1.
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * You must do this in-place without altering the nodes' values.
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */
import ht.ListNode;
public class ReorderList {
    public void reorderList(ListNode head) {
        helper(head);
    }
    private void helper(ListNode head) {
        if (head == null) {
            return;
        }
        ListNode current = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            if (fast != null) {
                current = current.next;
            }
        }
        fast = current.next;
        current.next = null;

        fast = this.reverse(fast); //　先reverse一下，然后merge
        current = head;
        ListNode p1 = null, p2 = null;
        while (current != null && fast != null) {
            p1 = current.next;
            p2 = fast.next;

            current.next = fast;
            fast.next = p1;

            current = p1;
            fast = p2;
        }
    }
    private ListNode reverse(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode root = null;
        ListNode p = null, current = head;
        while (current != null) {
            p = current.next;
            current.next = root;
            root = current;
            current = p;
        }
        return root;
    }
}
