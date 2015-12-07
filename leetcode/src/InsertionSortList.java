/**
 * Created by hduser on 15-12-7.
 * Sort a linked list using insertion sort.
 */
import ht.ListNode;
public class InsertionSortList {
    public ListNode insertionSortList(ListNode head) {
        return helper(head);
    }
    private ListNode helper(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode fake = new ListNode(Integer.MIN_VALUE);
        ListNode current = head, p = null;
        while (current != null) {
            p = current.next;
            fake = insert(fake, current);
            current = p;
        }
        return fake.next;
    }
    private ListNode insert(ListNode head, ListNode target) {
        //target.next = null;  // 先断开target的链接
        if (head == null) {
            return target;
        }
        ListNode current = head, p = null;
        while (current.next != null && current.next.val < target.val) {
            current = current.next;
        }
        p = current.next;
        current.next = target;
        target.next = p;
        return head;
    }
}
