/**
 * Created by hduser on 15-12-7.
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
 */
import ht.ListNode;
public class PartitionList {
    public ListNode partition(ListNode head, int x) {
        return helper(head, x);
    }
    private ListNode helper(ListNode head, int x) {
        ListNode fake = new ListNode(x);
        ListNode tail = fake;

        ListNode current = new ListNode(Integer.MIN_VALUE);
        current.next = head;
        head = current;
        current = head;
        while (current != null && current.next != null) {
            if (current.next.val < x) {
                current = current.next;
            } else {
                tail.next = current.next;
                tail = tail.next;
                current.next = current.next.next;
            }
        }
        tail.next = null;
        current.next = fake.next;
        return head.next;
    }
}
