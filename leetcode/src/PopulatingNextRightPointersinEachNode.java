/**
 * Created by hduser on 15-12-2.
 * Populate each next pointer to point to its next right node. If there is no next right node,
 * the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 * Note:
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same level,
 * and every parent has two children).
 * For example,
 Given the following perfect binary tree,
 1
 /  \
 2    3
 / \  / \
 4  5  6  7
 After calling your function, the tree should look like:
 1 -> NULL
 /  \
 2 -> 3 -> NULL
 / \  / \
 4->5->6->7 -> NULL
 *
 *
 */
import ht.TreeLinkNode;
public class PopulatingNextRightPointersinEachNode {
    public void connect(TreeLinkNode root) {
        helper(root);
    }
    private void helper(TreeLinkNode root) {
        //dfs(root);
        bfs(root);
    }
    private void dfs(TreeLinkNode root) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            return;
        } else {
            root.left.next = root.right;
            dfs(root.left);
            dfs(root.right);
            // 连接左右子树的空隙
            TreeLinkNode pLeft = root.left;
            TreeLinkNode pRight = root.right;
            while (pLeft != null) {
                pLeft.next = pRight;
                pLeft = pLeft.right;
                pRight = pRight.left;
            }
        }
    }
    private void bfs(TreeLinkNode root) {
        // 层级遍历
        if (root == null) {
            return;
        }
        TreeLinkNode pre = root;
        TreeLinkNode current = null;
        while (pre != null) {
            current = pre;
            while (current != null) {
                if (current.left == null) {
                    return;
                }
                current.left.next = current.right;
                if (current.next != null) {
                    current.right.next = current.next.left;
                }
                current = current.next;
            }
            pre = pre.left;  //　一直向左移动,向下移动一层
        }
        return;
    }
}
