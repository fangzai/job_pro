/**
 * Created by hduser on 15-12-2.
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */
import ht.TreeNode;
import ht.ListNode;
public class ConvertSortedListtoBinarySearchTree {
    public TreeNode sortedListToBST(ListNode head) {
        return helper(head);
    }
    private TreeNode helper(ListNode head) {
        //return this.recurrsiveBuildBST(head);
        return recurrsiveMid(head, null);
    }
    private TreeNode recurrsiveBuildBST(ListNode head) {
        if (head == null) {
            return null;
        } else {
            // 这个递归程序就比较复杂，为了找到中点前面的位置，做了一个循环
            // 还需要判定slow.next是否是null, 不是很直观，而findＭiddle函数就比较直观了
            ListNode fast = head, slow = head;
            while (fast != null && fast.next !=null) {
                fast = fast.next.next;
                if (fast != null && fast.next != null) {
                    slow = slow.next;
                }
            }
            if (slow.next == null) {
                return new TreeNode(slow.val);
            }
            TreeNode current = new TreeNode(slow.next.val);
            fast = slow.next.next;
            slow.next = null;

            current.left = recurrsiveBuildBST(head);
            current.right = recurrsiveBuildBST(fast);
            return current;
        }
    }
    private TreeNode recurrsiveMid(ListNode head, ListNode tail) {
        if (head == tail) {
            //　貌似这个地方不能用head.equals(tail) 因为tail有可能不是object只是null
            return null; //表示首尾重合了
        } else {
            ListNode mid = findMiddle(head, tail);
            TreeNode current = new TreeNode(mid.val);
            current.left = recurrsiveMid(head, mid);  //没有算mid
            current.right = recurrsiveMid(mid.next, tail);
            return current;
        }
    }
    private ListNode findMiddle(ListNode head, ListNode tail) {
        ListNode fast = head, slow =head;  //并没有破坏链表结构
        while (fast != tail && fast.next != tail)
        {
            fast = fast.next.next;
            //if (fast->next != tail)
            slow = slow.next;
        }
        //System.out.println(slow.val);
        return slow;
    }
}
