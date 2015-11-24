/**
 * Created by hduser on 15-11-24.
 * 正常的level遍历倒置过来就可以了
 */
import ht.TreeNode;

import java.util.*;

public class BinaryTreeLevelOrderTraversalII {
    List<List<Integer>> result = new ArrayList<List<Integer>>();

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        return helper(root);
    }
    private List<List<Integer>> helper(TreeNode root) {
        //return bfs(root);
        dfs(root, 0);
        Collections.reverse(this.result);
        return this.result;
    }
    private List<List<Integer>> bfs(TreeNode root) {
        ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
        if (root == null) {
            return res;
        }
        LinkedList<TreeNode> treeQueue = new LinkedList<TreeNode>();
        treeQueue.add(root);
        int count = 1;
        int depth = 0;
        List<Integer> ele = new ArrayList<Integer>();
        TreeNode current = null;
        while (!treeQueue.isEmpty()) {
            current = treeQueue.peek();
            treeQueue.pop();
            count--;
            ele.add(current.val);

            if (current.left != null) {
                treeQueue.add(current.left);
            }
            if (current.right != null) {
                treeQueue.add(current.right);
            }
            if (count == 0) {
                depth++;
                count = treeQueue.size();
                res.add(ele);
                ele = new ArrayList<Integer>();
            }
        }
        Collections.reverse(res);
        return res;
    }
    private void dfs(TreeNode root, int depth) {
        if (root == null) {
            return;
        }
        if (result.size() == depth) {
            List<Integer> ele = new ArrayList<Integer>();
            result.add(ele);
        }
        result.get(depth).add(root.val);
        dfs(root.left, depth + 1);
        dfs(root.right, depth + 1);
        return;
    }
}
