/**
 * Created by hduser on 15-11-30.
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Note: Do not modify the linked list.
 * Follow up:
 * Can you solve it without using extra space?
 *
 */
import ht.ListNode;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class LinkedListCycleII {
    public ListNode detectCycle(ListNode head) {
        return helper(head);
    }
    private ListNode helper(ListNode head) {
        //return speedPointer(head);
        return mapRecord(head);
    }
    private ListNode speedPointer(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null && slow != null) {
            // 快慢指针的话就是需要注意判定条件
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                fast = head;
                //　这里面的几何关系有点儿诡异，需要仔细思考一下
                while (slow != fast) {
                    fast = fast.next;
                    slow = slow.next;
                }
                return slow;
            }
        }
        return null;
    }
    private ListNode mapRecord(ListNode head) {
        if (head == null) {
            return null;
        }
        Comparator<ListNode> cmp = new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                return o1.toString().compareTo(o2.toString());
            }
        };
        Map<ListNode, Boolean> record = new TreeMap<ListNode, Boolean>(cmp);
        // 两种map做记录　一个是treemap一个是hashmap
        HashMap<ListNode, Boolean> hashRecord = new HashMap<ListNode, Boolean>();
        ListNode current = head;
        while (current != null) {
//            if (record.containsKey(current)) {
//                return true;
//            }
//            record.put(current, true);
            if (hashRecord.containsKey(current)) {
                return current;
            }
            hashRecord.put(current, true);
            current = current.next;
        }
        return null;
    }
}
