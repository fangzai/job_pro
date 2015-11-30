/**
 * Created by hduser on 15-11-30.
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
import ht.ListNode;
public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return helper(l1, l2);
    }
    private ListNode helper(ListNode l1, ListNode l2) {
        ListNode cur1 = l1;
        ListNode cur2 = l2;
        ListNode head = null;
        ListNode p = null;
        ListNode pre = null;
        int num = 0;
        int value1 = 0;
        int value2 = 0;
        while (cur1 != null || cur2 != null) {
            value1 = 0;
            value2 = 0;
            if (cur1 != null) {
                value1 = cur1.val;
                cur1 = cur1.next;
            }
            if (cur2 != null) {
                value2 = cur2.val;
                cur2 = cur2.next;
            }
            num += value1 + value2;
            p = new ListNode(num % 10);
            num /= 10;
            if (head == null) {
                head = p;
            } else {
                pre.next = p;
            }
            pre = p;
        }
        if (num != 0) {
            p = new ListNode(num);
            pre.next = p;
        }
        return head;
    }
}
