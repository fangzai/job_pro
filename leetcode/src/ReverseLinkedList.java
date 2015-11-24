import ht.ListNode;

/**
 * Created by hduser on 15-11-23.
 * Reverse a singly linked list.
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */
public class ReverseLinkedList {
    public ListNode reverseList(ListNode head) {
        return helper(head);
    }
    private ListNode helper(ListNode head) {
        //return iterativeReverse(head);
        return recursiveReverse(head);
    }
    private ListNode iterativeReverse(ListNode head) {
        ListNode root = null, p = null;
        ListNode current = head;
        while (current != null) {
            p = current.next;
            current.next = root;
            root = current;
            current = p;
        }
        return root;
    }
    private ListNode recursiveReverse(ListNode head) {
        return recursiveHelper(head, null);
    }
    private ListNode recursiveHelper(ListNode head, ListNode revrseHead) {
        //每次传入的参数都是递归的头，和下一次的尾部
        if (head == null) {
            return revrseHead;
        } else {
            ListNode nextHead = head.next;
            head.next = revrseHead;
            return recursiveHelper(nextHead, head);
        }
    }
}
