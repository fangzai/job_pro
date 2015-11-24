/**
 * Created by hduser on 15-11-24.
 */
import ht.TreeNode;

import java.util.LinkedList;

public class MinimumDepthofBinaryTree {
    public int minDepth(TreeNode root) {
        return helper(root);
    }
    private int helper(TreeNode root) {
        //return dfs(root);
        return bfs(root);
    }
    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        } else {
            int left = dfs(root.left);
            int right = dfs(root.right);
            if (left == 0) {
                return right + 1;
            } else if (right == 0 ) {
                return left + 1;
            } else {
                return Math.min(left, right) + 1;
            }

        }
    }
    private int bfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        LinkedList<TreeNode> treeQueue = new LinkedList<TreeNode>();
        treeQueue.add(root);
        int depth = 0;
        int count = 1;
        TreeNode current = null;
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
            if (current.right == null && current.left == null) {
                return depth + 1;
            }
            if (count == 0) {
                depth++;
                count = treeQueue.size();
            }
        }
        return depth;
    }
}
