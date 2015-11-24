/**
 * Created by hduser on 15-11-23.
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */
public class RemoveDuplicatesfromSortedArrayII {
    public int removeDuplicates(int[] nums) {
        return helper(nums);
    }
    private int helper(int[] nums) {
        int last = 0;
        int i = 0, j = 0;
        int count = 0;
        // 思路：　维护两个坐标i表示当前可以存的位置，j表示和last值进行比较的位置
        //　　　　 如果count小于２则可以从j->i复制元素，否则不能复制，j直接往后遍历
        while (j < nums.length && i < nums.length) {
            last = nums[j];
            count = 0;
            while (j < nums.length && last == nums[j]) {
                count++;
                if(count <= 2) {
                    nums[i] = nums[j];
                    i++;
                }
                j++;
            }
        }
        return i;
    }
}
