/**
 * Created by hduser on 15-12-7.
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

 For example,
 Given n = 3, there are a total of 5 unique BST's.

 1         3     3      2      1
 \       /     /      / \      \
 3     2     1      1   3      2
 /     /       \                 \
 2     1         2                 3
 */
public class UniqueBinarySearchTrees {
    public int numTrees(int n) {
        return helper(n);
    }
    private int helper(int n) {
        if (n <= 0) {
            return 1;
        }
        int[] result = new int[n + 1];
        result[0] = 1;
        result[1] = 1;
        //result[2] = 2;
        for (int i = 2; i <= n; ++i) {
            result[i] = 0;
            for (int j = 0; j < i; ++j) {
                result[i] += result[j] * result[i - j -1];
                //左子树分j个节点，右子树分i-j-1个节点
            }
        }
        return result[n];
    }
}
