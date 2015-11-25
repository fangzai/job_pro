package ht;

import java.util.Comparator;

/**
 * Created by hduser on 15-11-25.
 */
public class ListNodeComparator implements Comparator<ListNode> {
    public int compare(ListNode o1, ListNode o2) {
        if (o1.val > o2.val) {
            return 1;
        } else if (o1.val < o2.val) {
            return -1;
        } else {
            return 0;
        }
    }
}