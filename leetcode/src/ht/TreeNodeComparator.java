package ht;

import java.util.Comparator;

/**
 * Created by hduser on 15-11-25.
 */
public class TreeNodeComparator implements Comparator<TreeNode>{
    public int compare(TreeNode o1, TreeNode o2) {
        /*if (o1.val > o2.val) {
            return 1;
        } else if (o1.val < o2.val) {
            return -1;
        } else {
            return 0;
        }*/
        return o1.toString().compareTo(o2.toString());
    }
}
