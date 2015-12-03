/**
 * Created by hduser on 15-12-3.
 * Given a binary tree, return the postorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
 1
 \
 2
 /
 3
 return [3,2,1].

 Note: Recursive solution is trivial, could you do it iteratively?
 */
import ht.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
public class BinaryTreePostorderTraversal {
    public List<Integer> postorderTraversal(TreeNode root) {
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
            recursive(root.right, result);
            result.add(root.val);
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
        TreeNode current = null;
        treeQueue.push(root);
        while (!treeQueue.isEmpty()) {
            current = treeQueue.peek();
            treeQueue.pop();
            if (current != null) {
                //　下面这三句话加起来是先序遍历
                //result.add(current.val);
                //treeQueue.push(current.right);
                //treeQueue.push(current.left);
                // 变换顺序　逆转一下就是后续遍历
                result.add(current.val);
                treeQueue.push(current.left);
                treeQueue.push(current.right);
            }
        }
        Collections.reverse(result);
        return result;
    }
}
