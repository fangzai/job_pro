import ht.ListNode;

/**
 * Created by hduser on 15-11-23.
 * Remove all elements from a linked list of integers that have value val.
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */
public class RemoveLinkedListElements {
    public ListNode removeElements(ListNode head, int val) {
        return helper(head, val);
    }
    public ListNode helper(ListNode head, int val) {
        ListNode fake = new ListNode(Integer.MAX_VALUE);
        fake.next = head;
        ListNode current = fake;
        while (current.next != null) {
            if (current.next.val == val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return fake.next;
    }
}
