/**
 * Created by hduser on 15-11-24.
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have security
 * system connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money
 * of each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 */
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class HouseRobber {
    public int rob(int[] nums) {
        return helper(nums);
    }
    private int helper(int[] nums) {
        Integer[] ele = new Integer[nums.length + 1];
        Arrays.fill(ele, 0);
        List<Integer> dp = Arrays.asList(ele);
        if (nums.length == 0) {
            return 0;
        }
        dp.set(0, nums[0]);

        if (nums.length == 1) {
            return dp.get(0);
        }
        dp.set(1, Math.max(nums[0], nums[1]));
        for (int i = 2; i < nums.length; ++i) {
            dp.set(i, Math.max(nums[i] + dp.get(i - 2), dp.get(i-1).intValue()));
        }
        return dp.get(nums.length - 1);
    }
}
