/**
 * Created by hduser on 15-11-25.
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more than 1.
 */
import ht.TreeNode;

import java.util.Comparator;
import java.util.LinkedList;
import java.util.Map;
import java.util.TreeMap;
import java.util.Stack;

public class BalancedBinaryTree {
    public boolean isBalanced(TreeNode root) {
        return helper(root);
    }
    private boolean helper(TreeNode root) {
        return postTraverseHelper(root);
        //return dfs(root);
    }
    private boolean postTraverseHelper(TreeNode root) {
        if (root == null) {
            return true;
        }
        Comparator<TreeNode> cmp = new Comparator<TreeNode>() {
            @Override
            public int compare(TreeNode o1, TreeNode o2) {
                return o1.toString().compareTo(o2.toString());
            }
        };
        Map<TreeNode, Integer> heightRecord = new TreeMap<TreeNode, Integer>(cmp);
        Stack<TreeNode> treeStack = new Stack<TreeNode>();

        treeStack.push(root);
        TreeNode current = null;
        while (!treeStack.isEmpty()) {
            current = treeStack.peek();
            treeStack.pop();
            if ((current.left == null || (current.left != null && heightRecord.containsKey(current.left))) &&
                    current.right == null || (current.right != null && heightRecord.containsKey(current.right))) {
                int left = current.left == null? 0 : heightRecord.get(current.left);
                int right = current.right== null? 0 : heightRecord.get(current.right);
                if (Math.abs(left - right) > 1) {
                    return false;
                }
                heightRecord.put(current, Math.max(left, right) + 1);
            } else if (current.left != null && !heightRecord.containsKey(current.left)) {
                treeStack.push(current);
                treeStack.push(current.left);
            } else {
                treeStack.push(current);
                treeStack.push(current.right);
            }
        }
        return true;
    }
    private boolean dfs(TreeNode root) {
        return depth(root) != -1;
    }
    private int depth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftHeight = depth(root.left);
        int rightHeight = depth(root.right);
        if (leftHeight == -1) {
            return -1;
        }
        if (rightHeight == -1) {
            return -1;
        }
        if (Math.abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + Math.max(leftHeight, rightHeight);
    }
}
