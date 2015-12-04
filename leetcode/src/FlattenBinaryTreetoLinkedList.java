/**
 * Created by hduser on 15-12-4.
 * Given a binary tree, flatten it to a linked list in-place.

 For example,
 Given

     1
    / \
   2   5
  / \   \
 3   4   6
 The flattened tree should look like:
 1
 \
 2
 \
 3
 \
 4
 \
 5
 \
 6
 If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
 */
import ht.TreeNode;
public class FlattenBinaryTreetoLinkedList {
    public void flatten(TreeNode root) {
        helper(root);
    }
    private void helper(TreeNode root) {
        //TreeNode head = new TreeNode(Integer.MAX_VALUE);
        //head.left = root;
        //TreeNode tail = new TreeNode(Integer.MIN_VALUE);
        //head = dfs(head, tail);
        //root = head.right;
        //TreeNode[] label = dfs2(head);
        //root = head.right;
        TreeNode[] tail = new TreeNode[1];
        tail[0] = null;
        dfs3(root, tail);
        return;
    }
    private TreeNode dfs(TreeNode root, TreeNode tail) {
        if (root.right == null && root.left == null) {
            tail.right = root;
            return root;
        } else {
            if (root.left == null || root.right == null) {
                root.left = root.right == null ? root.left : root.right;
                TreeNode head = dfs(root.left, tail);
                root.right = head;
                root.left = null;
                return root;
            } else {
                TreeNode current = root.right;
                TreeNode head = dfs(root.left, tail);
                root.right = head;
                root.left = null;

                TreeNode tmpTail = new TreeNode(Integer.MIN_VALUE);
                head = dfs(current, tmpTail);
                tail.right.right = head;
                tail.right = tmpTail.right;
                return root;
            }
        }
    }
    private TreeNode[] dfs2(TreeNode root) {
        // 每次递归返回首尾节点
        if (root.right == null && root.left == null) {
            TreeNode[] label = {root, root};
            return label;
        } else {
            if (root.left == null || root.right == null) {
                root.left = root.right == null ? root.left : root.right;
                TreeNode[] leftLabel = dfs2(root.left);
                root.right = leftLabel[0];
                root.left = null;
                leftLabel[0] = root;
                return leftLabel;
            } else {
                TreeNode current = root.right;
                TreeNode[] leftLabel = dfs2(root.left);
                root.right = leftLabel[0];
                root.left = null;

                TreeNode[] rightLabel = dfs2(current);
                leftLabel[1].right = rightLabel[0];
                rightLabel[0] = root;
                return rightLabel;
            }
        }
    }
    private TreeNode dfs3(TreeNode root, TreeNode[] tail) {
        // 这个递归是最简洁的
        if (root == null) {
            return tail[0];
        }
        TreeNode[] head = new TreeNode[1];
        head[0] = dfs3(root.right, tail);
        root.right = dfs3(root.left, head);
        root.left = null;
        return root;
    }
}
