/**
 * Created by hduser on 15-12-3.
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 *
 */
public class FindMinimuminRotatedSortedArray {
    public int findMin(int[] nums) {
        //int target = 10;
        //int res = binarySearch(nums, target);
        //System.out.println(res);
        return helper(nums);
    }
    private int helper(int[] nums) {
        if (nums.length == 0) {
            return -1;
        }
        int left = 0, right = nums.length - 1;
        int mid = 0;
        while (nums[left] > nums[right]) {
            mid = left + (right - left) / 2;
            if (nums[left] > nums[mid]) {
                right = mid;  //　最小的值可能是nums[mid]
            } else {
                left = mid + 1;
            }
        }
        //　循环外面必然是 nums[left] <= nums[right]
        return nums[left];
    }
    private int binarySearch(int[] nums, int target) {
        int left = 0,right = nums.length - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
}
