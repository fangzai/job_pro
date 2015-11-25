/**
 * Created by hduser on 15-11-25.
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding
 * up all the values along the path equals the given sum.
 * For example:
 * Given the below binary tree and sum = 22,
       5
      / \
     4   8
    /   / \
   11  13  4
  /  \      \
 7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22
 *
 */
import ht.TreeNode;
import java.util.LinkedList;

public class PathSum {
    public boolean hasPathSum(TreeNode root, int sum) {
        return helper(root, sum);
    }
    private boolean helper(TreeNode root, int sum) {
        int val = 0;
        if (root == null) {
            return false;
        }
        return dfs(root, val, sum);
        //return bfs(root, sum);
    }
    private boolean dfs(TreeNode root, int sum, int target) {
        if (root.left == null && root.right == null) {
            return (sum + root.val) == target;
        } else {
            if (root.left == null) {
                return dfs(root.right, sum + root.val, target);
            } else if (root.right == null) {
                return dfs(root.left, sum + root.val, target);
            } else {
                return dfs(root.left, sum + root.val, target) ||
                        dfs(root.right, sum + root.val, target);
            }
        }
    }
    private boolean bfs(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        LinkedList<TreeNode> treeQueue = new LinkedList<TreeNode>();
        LinkedList<Integer> dataSum = new LinkedList<Integer>();

        treeQueue.push(root);
        dataSum.push(root.val);
        int count = 1;
        int depth = 0;
        TreeNode current = null;
        Integer tmpSum = 0;
        while (!treeQueue.isEmpty()) {
            current = treeQueue.peek();
            treeQueue.pop();
            count--;
            tmpSum = dataSum.peek();
            dataSum.pop();
            if (null == current.right && current.left == null && tmpSum == sum) {
                return true;
            }
            if (current.left != null) {
                treeQueue.push(current.left);
                dataSum.push(tmpSum + current.left.val);
            }
            if(current.right != null) {
                treeQueue.push(current.right);
                dataSum.push(tmpSum + current.right.val);
            }

            if(count == 0) {
                depth++;
                count = treeQueue.size();
            }
        }
        return false;
    }
}
