/**
 * Created by hduser on 15-12-7.
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */
import ht.ListNode;

import java.util.PriorityQueue;   // 优先队列
import java.util.Comparator;

public class MergekSortedLists {
    public ListNode mergeKLists(ListNode[] lists) {
        return helper(lists);
    }
    private ListNode helper(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }
        //return recursive(lists, 0, lists.length - 1);
        return heapMethod(lists);
    }
    private ListNode recursive(ListNode[] lists, int begin, int end) {
        if (begin == end) {
            return lists[begin];
        } else {
            int mid = begin + (end - begin) / 2;
            ListNode l1 = recursive(lists, begin, mid);
            ListNode l2 = recursive(lists, mid + 1, end);
            return merge(l1, l2);
        }
    }
    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(Integer.MIN_VALUE);
        int val1, val2;
        ListNode current = head;
        while (l1 != null || l2 != null) {
            val1 = (l1 == null) ? Integer.MAX_VALUE : l1.val;
            val2 = (l2 == null) ? Integer.MAX_VALUE : l2.val;
            if (val1 < val2) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        return head.next;
    }
    private ListNode heapMethod(ListNode[] lists) {
        if (lists.length == 0)
            return null;
        PriorityQueue<ListNode>pq = new PriorityQueue<ListNode>(lists.length, new Comparator<ListNode>() {
            public int compare(ListNode l1, ListNode l2) {
                return l1.val - l2.val; //minHeap: l1.val > l2.val, so the root is the minimum
            }
        });
        for (ListNode l : lists) {
            if (l != null) {
                pq.offer(l);  //　将l插入队列中
            }
        }
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while (!pq.isEmpty()) {
            ListNode cur = pq.poll(); // 获取队列头，并且移除
            tail.next = cur;
            tail = tail.next;// Step forward
            if (cur.next != null) {
                pq.offer(cur.next);  // 处理过某个队列后，删掉头了，把余下的链表加入最小堆中
            }
        }
        return dummy.next;
    }
}
