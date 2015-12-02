/**
 * Created by hduser on 15-12-2.
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */
import ht.TreeNode;
public class ConvertSortedArraytoBinarySearchTree {
    public TreeNode sortedArrayToBST(int[] nums) {
        return helper(nums);
    }
    private TreeNode helper(int[] nums) {
        return this.recurrsiveBuilBST(nums, 0, nums.length - 1);
    }
    private TreeNode recurrsiveBuilBST(int[] nums, int start, int end) {
        if (start > end) {
            return null;
        } else {
            int mid = (start + end)/2;
            TreeNode current = new TreeNode(nums[mid]);
            TreeNode left = recurrsiveBuilBST(nums, start, mid - 1);
            TreeNode right = recurrsiveBuilBST(nums, mid + 1, end);
            current.left = left;
            current.right = right;
            return current;
        }
    }
}
