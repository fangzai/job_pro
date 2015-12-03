/**
 * Created by hduser on 15-12-3.
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */
import ht.ListNode;
public class ReverseLinkedListII {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        return helper(head, m, n);
    }
    private ListNode helper(ListNode head, int m, int n) {
        if (head == null) {
            return head;
        }
        ListNode current = new ListNode(Integer.MAX_VALUE);
        current.next = head;
        head = current;
        current = head;

        int i = 1;
        ListNode pre = current;
        while (i < m) {
            pre = pre.next;
            //　防止ｍ越界
            if (pre.next == null) {
                return head.next;
            }
            i++;
        }
        ListNode root = null;
        ListNode p = null;
        current = pre.next;
        ListNode tail = pre.next; //记住尾部
        while (i <= n) {
            p = current.next;
            current.next = root;
            root = current;
            current = p;
            //　防止n越界
            if (current == null) {
                break;
            }
            i++;
        }
        pre.next = root;
        tail.next = p;
        return head.next;
    }
}
