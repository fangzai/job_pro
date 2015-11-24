import ht.ListNode;

/**
 * Created by hduser on 15-11-23.
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */
public class RemoveDuplicatesfromSortedList {
    public ListNode deleteDuplicates(ListNode head) {
        return helper(head);
    }
    private ListNode helper(ListNode head) {
        ListNode current = new ListNode(Integer.MAX_VALUE);
        ListNode p = null;
        current.next = head;
        head = current;
        int last = 0;
        while (current != null) {
            p = current.next;
            last = current.val;
            while (p != null && p.val == last) {
                p = p.next;
            }
            current.next = p;
            current = p;
        }
        return head.next;
    }
}
