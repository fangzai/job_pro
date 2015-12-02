/**
 * Created by hduser on 15-12-2.
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

 An example is the root-to-leaf path 1->2->3 which represents the number 123.

 Find the total sum of all root-to-leaf numbers.

 For example,

   1
  / \
 2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.

 Return the sum = 12 + 13 = 25.
 *
 */
import ht.TreeNode;

import java.util.LinkedList;

public class SumRoottoLeafNumbers {
    private int result = 0;
    public int sumNumbers(TreeNode root) {
        return helper(root);
    }
    private int helper(TreeNode root) {
        if (root == null) {
            return result;
        }
        //dfs(root, 0);
        //return result;
        return bfs(root);
    }
    private void dfs(TreeNode root, int sum) {
        if (root.left == null && root.right == null) {
            //　到达叶子节点
            result += sum * 10 + root.val;
        } else {
            int res = sum * 10 + root.val;
            if (root.left != null) {
                dfs(root.left, res);
            }
            if (root.right != null) {
                dfs(root.right, res);
            }
        }
    }
    private int bfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        LinkedList<TreeNode> treeQueue = new LinkedList<>();
        LinkedList<Integer> resQueue = new LinkedList<>();
        treeQueue.add(root);
        resQueue.add(root.val);
        int count = 1;
        int depth = 0;

        int res = 0;

        TreeNode current = null;
        int num = 0;
        while (!treeQueue.isEmpty()) {
            current = treeQueue.peek();
            treeQueue.pop();
            count--;
            num = resQueue.peek();
            resQueue.pop();
            if (current.left == null && current.right == null) {
                res += num;
            } else {
                if (current.left != null) {
                    treeQueue.add(current.left);
                    resQueue.add(num * 10 + current.left.val);
                }
                if (current.right != null) {
                    treeQueue.add(current.right);
                    resQueue.add(num * 10 + current.right.val);
                }
            }
            if (count == 0) {
                count = treeQueue.size();
                depth++;
            }
        }
        return res;
    }
}
