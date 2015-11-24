/**
 * Created by hduser on 15-11-23.
 */
import ht.TreeNode;
public class SameTree {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return helper(p, q);
    }
    private boolean helper(TreeNode p, TreeNode q) {
        return dfs(p, q);
    }
    private boolean dfs(TreeNode p, TreeNode q) {
        if(q != null && p != null) {
            if (q.val == p.val) {
                return dfs(p.left, q.left) && dfs(p.right, q.right);
            } else {
                return false;
            }
        } else if(p == null && q == null) {
            return true;
        } else {
            return false;
        }
    }
}
