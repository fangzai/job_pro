/**
 * Created by hduser on 15-12-2.
 * A peak element is an element that is greater than its neighbors.
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that num[-1] = num[n] = -∞.
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *
 */
public class FindPeakElement {
    public int findPeakElement(int[] nums) {
        if (nums.length <= 0) {
            return -1;
        }
        return helper(nums);
    }
    private int helper(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        int mid = 0;
        //　下面是binary search
        //int leftVal = 0;
        //int rightVal = 0;
        long leftVal = 0;
        long rightVal = 0;
        //　这个地方不能是int　因为给的测试集合里面有一个[Integer.MIN_VALUE]
        // 特别缺德
        while (left <= right) {
            mid = (left + right) / 2;
            leftVal = (mid - 1) < 0 ? Long.MIN_VALUE : nums[mid - 1];
            rightVal = (mid + 1) > nums.length - 1 ? Long.MIN_VALUE : nums[mid + 1];

            if (leftVal < nums[mid] && rightVal < nums[mid]) {
                return mid;
            }

            if (mid > 0 && nums[mid - 1] > nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
}
