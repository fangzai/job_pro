package ht;

/**
 * Created by hduser on 15-11-23.
 */
public class ListLink {
    public ListNode first = null;
    public ListNode tail = null;
    //private int pos = -1;  //节点的位置

    public ListLink() {
        this.first = null;
        this.tail = null;
    }
    public ListLink(ListLink ele) {
        //　这里假设　传入的链表是合法的
        //　没有完成　　这里需要全部copy一遍
    }
    public ListNode createListLink(int[] vals) {
        ListNode last = null;
        for (int i = 0; i < vals.length; ++i) {
            ListNode cur = new ListNode(vals[i]);
            cur.next =null;
            if (i == 0) {
                this.first = cur;
                last = cur;
            } else {
                last.next = cur;
                last = cur;
            }
        }
        this.tail = last;
        return this.first;
    }
    public ListNode createListLink(int[] vals, int len) {
        if (vals.length < len) {
            return null;
        }
        ListNode last = null;
        for (int i = 0; i < len; ++i) {
            ListNode cur = new ListNode(vals[i]);
            cur.next =null;
            if (i == 0) {
                this.first = cur;
                last = cur;
            } else {
                last.next = cur;
                last = cur;
            }
        }
        this.tail = last;
        return this.first;
    }
    public ListNode addFirstLink(int vals) {
        //　添加第一个首节点
        ListNode node = new ListNode(vals);
        node.next = first;
        this.first = node;
        return this.first;
    }
    public ListNode addLink(int vals) {
        ListNode node = new ListNode(vals);
        node.next = null;
        this.tail.next = node;
        this.tail = node;
        return this.first;
    }
    public ListNode reverse() {
        ListNode root = null;
        ListNode cur = this.first, p = null;
        while (cur != null) {
            p = cur.next;
            cur.next = root;
            root = cur;
            cur = p;
        }
        return root;
    }
    public ListNode insert(int pos, int val) {
        if (pos == 0) {
            addFirstLink(val);
            return this.first;
        }
        ListNode cur = this.first, p = null;
        int i = 0;
        while (i < pos - 1 && cur.next != null) {
            cur = cur.next;
        }
        if(cur.next == null) {
            addLink(val);
        } else {
            p = cur.next;
            ListNode tmp = new ListNode(val);
            cur.next = tmp;
            tmp.next = p;

        }
        return this.first;
    }
    public void insertMap(int pos, ListNode ele) {
        ListNode cur = this.first;
        int i = 0;
        while (i < pos && cur != null) {
            cur = cur.next;
            i++;
        }
        ele.next = cur;
    }
    public ListNode deleteHead() {
        //删除头节点；
        this.first = first.next;
        return this.first;
    }
    public void display(ListNode head) {
        if (head == null) {
            System.out.println("This linklist is null!");
        }
        ListNode cur = head;
        while (cur != null) {
            System.out.print(cur.val + " -> ");
            cur = cur.next;
        }
        System.out.println();
    }
    public void display() {
        if (this.first == null) {
            System.out.println("This linklist is null!");
        }
        ListNode cur = this.first;
        while (cur != null) {
            System.out.print(cur.val + " -> ");
            cur = cur.next;
        }
        System.out.println();
    }
}
