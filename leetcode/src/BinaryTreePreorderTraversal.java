/**
 * Created by hduser on 15-12-3.
 * Given a binary tree, return the preorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
 1
 \
 2
 /
 3
 return [1,2,3].

 Note: Recursive solution is trivial, could you do it iteratively?
 */
import ht.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class BinaryTreePreorderTraversal {
    public List<Integer> preorderTraversal(TreeNode root) {
        return helper(root);
    }
    private List<Integer> helper(TreeNode root) {
        //List<Integer> result = new ArrayList<>();
        //recursive(root, result);
        //return result;
        return iterative(root);
    }
    private void recursive(TreeNode root, List<Integer> result) {
        if (root == null) {
            return;
        } else {
            result.add(root.val);
            recursive(root.left, result);
            recursive(root.right, result);
            return;
        }
    }
    private List<Integer> iterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        LinkedList<TreeNode> treeQueue = new LinkedList<>();
        // 虽然命名为queue，但是实际上是栈
        TreeNode current = root;
        while (current != null || !treeQueue.isEmpty()) {
            if (current != null) {
                treeQueue.push(current);
                result.add(current.val);
                current = current.left;
            } else {
                current = treeQueue.peek();
                treeQueue.pop(); // current 右边节点为null时候，开始弹栈
                current = current.right;
            }
        }
        return result;
    }
}
