/**
 * Created by hduser on 15-11-24.
 * Write a program to find the node at which the intersection of two singly linked lists begins.


 For example, the following two linked lists:

 A:          a1 → a2
                    ↘
                     c1 → c2 → c3
                    ↗
 B:     b1 → b2 → b3
 begin to intersect at node c1.


 Notes:

 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.
 *
 */
import ht.ListNode;
import java.util.Stack; //可以用压栈

public class IntersectionofTwoLinkedLists {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        return helper(headA, headB);
    }
    private ListNode helper(ListNode headA, ListNode headB) {
        //return circle(headA, headB);
        return stackHelper(headA, headB);
    }
    private ListNode circle(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        ListNode pA = headA, pB = headB;
        ListNode tailA = null, tailB = null;
        while (true) {
            if (pA == null) {
                pA = headB;
            }
            if (pB == null) {
                pB = headA;
            }
            if (pA.next == null) {
                tailA = pA;
            }
            if (pB.next == null) {
                tailB = pB;
            }
            if (tailA != null && tailB != null && tailB !=tailA) {
                return null;
            }
            if(pA == pB) {
                return pA;
            }
            pA = pA.next;
            pB = pB.next;

        }
    }
    private ListNode stackHelper(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        Stack<ListNode> myStackA = new Stack<ListNode>();
        Stack<ListNode> myStackB = new Stack<ListNode>();
        ListNode cur1 = headA, cur2 = null;
        while (cur1 != null) {
            myStackA.push(cur1);
            cur1 = cur1.next;
        }
        cur1 = headB;
        while (cur1 != null) {
            myStackB.push(cur1);
            cur1 = cur1.next;
        }
        if (!myStackA.peek().equals(myStackB.peek())) {
            return null;
        }
        while (!myStackA.empty() && !myStackB.empty() && myStackA.peek().equals(myStackB.peek())) {
            myStackA.pop();
            myStackB.pop();
        }
        if (myStackA.empty()) {
            return headA;
        } else {
            return myStackA.peek().next;
        }
    }
    // 严格来说还有第三种方法，就是快慢指针的问题，先遍历一遍，计算两个链表的长度差值
    //然后快的先走Ｎ步，接着慢的快的同时走，等快的到了尾部的时候，慢的也就是要找的
}