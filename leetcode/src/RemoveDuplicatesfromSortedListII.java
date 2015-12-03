import ht.ListNode;

/**
 * Created by hduser on 15-11-23.
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */
public class RemoveDuplicatesfromSortedListII {
    public ListNode deleteDuplicates(ListNode head) {
        return helper(head);
    }
    private ListNode helper(ListNode head) {
        ListNode current = new ListNode(Integer.MAX_VALUE);
        current.next = head;
        head = current;
        ListNode p = null;
        int last = 0;
        boolean flag = false;
        while (current != null && current.next != null) {
            p = current.next;
            last = p.val;
            flag = false;    //　是否有重复元素的标记
            while (p != null && p.next != null && p.val == p.next.val) {
                p = p.next;
                flag = true;
            }
            if (flag) {
                //　如果有重复元素的话，current的位置是不用改变的
                current.next = p.next;
            } else {
                current.next = p;
                current = current.next;
            }
        }
        return head.next;
    }
}
