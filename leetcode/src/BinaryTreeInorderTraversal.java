/**
 * Created by hduser on 15-12-3.
 * Given a binary tree, return the inorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
 1
 \
 2
 /
 3
 return [1,3,2].

 Note: Recursive solution is trivial, could you do it iteratively?
 *
 */
import ht.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
public class BinaryTreeInorderTraversal {
    public List<Integer> inorderTraversal(TreeNode root) {
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
            recursive(root.left, result);
            result.add(root.val);
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
                current = current.left;
            } else {
                current = treeQueue.peek();
                treeQueue.pop(); // current 右边节点为null时候，开始弹栈
                result.add(current.val);
                current = current.right;
            }
        }
        return result;
    }
}
