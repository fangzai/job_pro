/**
 * Created by hduser on 15-11-23.
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example,
 * Given input array nums = [1,1,2],
 * Your function should return length = 2, with the first two
 * elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 */
public class RemoveDuplicatesfromSortedArray {
    public int removeDuplicates(int[] nums) {
        return helper(nums);
    }
    private int helper(int[] nums) {
        if (nums.length <= 0) {
            return 0;
        }
        int last = Integer.MAX_VALUE;
        int count = 0;
        int cur = 0;      //记录当前移动的下标
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == last) {
                count++; //traverse index i will continue normally
            } else {
                last = nums[i];
                nums[cur] = nums[i];
                cur++;
            }
        }
        return cur;
    }
}
