/**
 * Created by hduser on 15-12-4.
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * click to show more practice.
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 */
public class MaximumSubarray {
    public int maxSubArray(int[] nums) {
        return helper(nums);
    }
    private int helper(int[] nums) {
        //return dynamicProgram2(nums);
        return recursive(nums);
    }
    private int dynamicProgram(int[] nums) {
        // dp[i] = max(dp[i-1] + nums[i], nums[i])
        if (nums.length == 0) {
            return 0;
        }
        int ps = 0, pe = 0;
        int ts = 0, te = 0;
        int maxValue = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (sum <= 0) {
                ts = i;
                te = i;
                sum = nums[i];
            } else {
                sum += nums[i];
                te = i;
            }
            if (sum > maxValue) {
                ps = ts;
                pe = te;
                maxValue = sum;
            }
        }
        return maxValue;
    }
    private int dynamicProgram2(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int maxValue = dp[0];
        for (int i = 1; i < nums.length; ++i) {
            dp[i] = Math.max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > maxValue) {
                maxValue = dp[i];
            }
        }
        return maxValue;
    }
    private int recursive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] res = findMaxSubArray(nums, 0, nums.length - 1);
        return res[2];
    }
    private int[] findMaxSubArray(int[] nums, int start, int end) {
        if (start == end) {
            int[] label = {start, end, nums[start]};
            return label;
        } else {
            int mid = (start + end) / 2;
            int[] leftRes = findMaxSubArray(nums, start, mid);
            int[] rightRes = findMaxSubArray(nums, mid + 1, end);
            int[] crossRes = crossSubArray(nums, start, mid, end);
            if (leftRes[2] >= rightRes[2] && leftRes[2] >= crossRes[2]) {
                return leftRes;
            } else if (rightRes[2] >= leftRes[2] && rightRes[2] >= crossRes[2]) {
                return rightRes;
            } else {
                return crossRes;
            }
        }
    }
    private int[] crossSubArray(int[] nums, int start, int mid, int end) {
        int leftSum = Integer.MIN_VALUE, rightSum = Integer.MIN_VALUE;
        int leftStart = 0, rightEnd = 0;
        int sum = 0;
        int i, j;
        for (i = mid; i >= 0; i--) {
            sum += nums[i];
            if (sum > leftSum) {
                leftSum = sum;
                leftStart = i;
            }
        }
        sum = 0;
        for (j = mid + 1; j <= end; j++) {
            sum += nums[j];
            if (sum > rightSum) {
                rightSum = sum;
                rightEnd = j;
            }
        }
        int[] label ={leftStart, rightEnd, leftSum + rightSum};
        return label;
    }
}
