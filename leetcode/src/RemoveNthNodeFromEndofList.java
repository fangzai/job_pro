/**
 * Created by hduser on 15-11-23.
 * Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 */
import ht.ListNode;
//import ht.ListLink;
public class RemoveNthNodeFromEndofList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        return  helper(head, n);
    }
    private ListNode helper(ListNode head, int n) {
        ListNode fast = head;
        ListNode slow = new ListNode(Integer.MAX_VALUE);
        //在前面附加一个假节点
        slow.next = head;
        head = slow;
        int i = 0;
        while (i < n) {
            if (fast != null) {
                fast = fast.next;
            } else {
                return head.next; //表示里面的元素不足n个
            }
            ++i;
        }
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        // 删除slow指向的节点
        slow.next = slow.next.next;
        return head.next;
    }
}
