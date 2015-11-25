/**
 * Created by hduser on 15-11-25.
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * For example, this binary tree is symmetric:
 *   1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following is not:
    1
   / \
  2   2
  \   \
  3    3
 */
import ht.TreeNode;

import java.util.LinkedList;

public class SymmetricTree {
    public boolean isSymmetric(TreeNode root) {
        return helper(root);
    }
    private boolean helper(TreeNode root) {
        /*if (root == null) {
            return true;
        }
        return dfs(root.left, root.right);*/
        return bfs(root);
    }
    private boolean dfs(TreeNode left, TreeNode right) {
        if (left == null && right == null) {
            return true;
        }
        if (left == null || right == null) {
            return false;
        }
        if (left.val == right.val) {
            return dfs(left.left, right.right) && dfs(left.right, right.left);
        } else {
            return false;
        }
    }
    private boolean bfs(TreeNode root) {
        if (root == null) {
            return true;
        }
        TreeNode pA = root.left;
        TreeNode pB = root.right;
        LinkedList<TreeNode> treeQueue = new LinkedList<TreeNode>();
        treeQueue.add(pA);
        treeQueue.add(pB);
        while (!treeQueue.isEmpty()) {
            pA = treeQueue.peek();
            treeQueue.pop();
            pB = treeQueue.peek();
            treeQueue.pop();

            if (pA == null && pB == null) {
                continue;
            }
            if (pA == null || pB == null) {
                return false;
            }
            if (pA.val != pB.val) {
                return false;
            }
            treeQueue.add(pA.left);
            treeQueue.add(pB.right);
            treeQueue.add(pA.right);
            treeQueue.add(pB.left);
        }
        return true;
    }
}
