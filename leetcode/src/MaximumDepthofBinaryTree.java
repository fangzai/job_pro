/**
 * Created by hduser on 15-11-24.
 */
import ht.TreeNode;
import java.util.LinkedList;

public class MaximumDepthofBinaryTree {
    public int maxDepth(TreeNode root) {
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
            int left = dfs(root.left) + 1;
            int right = dfs(root.right) + 1;
            return Math.max(left, right);
        }
    }
    private int bfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        //LinkedList实现了Ｑueue的接口
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
            if (count == 0) {
                depth++;
                count = treeQueue.size();
            }
        }
        return depth;
    }
}
