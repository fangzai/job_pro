/**
 * Created by hduser on 15-12-7.
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.

 1         3     3      2      1
 \       /     /      / \      \
 3     2     1      1   3      2
 /     /       \                 \
 2     1         2                 3
 */
import ht.TreeNode;

import java.util.ArrayList;
import java.util.List;

public class UniqueBinarySearchTreesII {
    public List<TreeNode> generateTrees(int n) {
        return helper(n);
    }
    private List<TreeNode> helper(int n) {
        if (n <=0) {
            return new ArrayList<>();
        }
        return dfs(1, n);
    }
    private List<TreeNode> dfs(int start, int end) {
        List<TreeNode> res = new ArrayList<>();
        if (start > end) {
            res.add(null);
        }
        for (int k = start; k <= end; ++k) {
            List<TreeNode> left = dfs(start, k - 1);
            List<TreeNode> right = dfs(k + 1, end);
            for (TreeNode i:left) {
                for (TreeNode j:right) {
                    TreeNode root = new TreeNode(k);
                    root.left = i;
                    root.right = j;
                    res.add(root);
                }
            }
        }
        return res;
    }
}
