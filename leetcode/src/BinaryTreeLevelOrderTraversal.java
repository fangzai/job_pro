/**
 * Created by hduser on 15-11-24.
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
      3
     / \
    9  20
  /  \
 15   7
 return its level order traversal as:
 [
 [3],
 [9,20],
 [15,7]
 ]
 */

import ht.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
public class BinaryTreeLevelOrderTraversal {
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        return helper(root);
    }
    private List<List<Integer>> helper(TreeNode root) {
        //return bfs(root);
        dfs(root, 0);
        return this.result;
    }
    private List<List<Integer>> bfs(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
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
