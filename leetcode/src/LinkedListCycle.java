/**
 * Created by hduser on 15-11-30.
 * Given a linked list, determine if it has a cycle in it.
 * Follow up:
 * Can you solve it without using extra space?
 */
import ht.ListNode;

import java.util.Comparator;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.Map;

public class LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        return helper(head);
    }
    private boolean helper(ListNode head) {
        //return speedPointer(head);
        return mapRecord(head);
    }
    private boolean speedPointer(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null && slow != null) {
            // 快慢指针的话就是需要注意判定条件，否则遇到边界条件就跪了
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
    private boolean mapRecord(ListNode head) {
        if (head == null) {
            return false;
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
                return true;
            }
            hashRecord.put(current, true);
            current = current.next;
        }
        return false;
    }
}
