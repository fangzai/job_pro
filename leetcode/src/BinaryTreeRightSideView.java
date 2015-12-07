/**
 * Created by hduser on 15-12-7.
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 For example:
 Given the following binary tree,
 1            <---
 /   \
 2     3         <---
 \     \
 5     4       <---
 You should return [1, 3, 4].
 */
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import ht.TreeNode;

public class BinaryTreeRightSideView {
    public List<Integer> rightSideView(TreeNode root) {
        return helper(root);
    }
    public List<Integer> helper(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        LinkedList<TreeNode> treeQueue = new LinkedList<>();
        int count = 1;
        int depth = 0;
        TreeNode current = null;
        treeQueue.add(root);
        while (!treeQueue.isEmpty()) {
            current = treeQueue.peek();
            treeQueue.pop();
            count--;
            if (current.left != null) {
                treeQueue.add(current.left);
            }
            if (current.right != null) {
                treeQueue.add(current.right);
            }
            if (count == 0) {
                count = treeQueue.size();
                depth++;
                result.add(current.val);
            }
        }
        return result;
    }
}
