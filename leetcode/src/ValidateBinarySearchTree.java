/**
 * Created by hduser on 15-12-4.
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 Assume a BST is defined as follows:
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
 *
 */
import ht.TreeNode;
public class ValidateBinarySearchTree {
    public boolean isValidBST(TreeNode root) {
        return helper(root);
    }
    private boolean helper(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (root.left != null) {
            TreeNode l = root.left;
            while (l != null) {
                if (l.val >= root.val) {
                    return false;
                }
                l = l.right;
            }
        }
        if (root.right != null) {
            TreeNode r = root.right;
            while (r != null) {
                if (r.val <= root.val) {
                    return false;
                }
                r = r.left;
            }
        }
        return helper(root.left) && helper(root.right);
    }
}
