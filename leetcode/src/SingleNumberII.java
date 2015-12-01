import java.util.Arrays;

/**
 * Created by hduser on 15-12-1.
 * Given an array of integers, every element appears three times except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 *
 */
public class SingleNumberII {
    public int singleNumber(int[] nums) {
        return helper(nums);
    }
    private int helper(int[] nums) {
        return bitnum(nums);
    }
    private int bitnum(int[] nums) {
        if (nums.length < 1) {
            return -1;
        }
        int[] bits = new int[32];
        Arrays.fill(bits, 0);
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < nums.length; ++j) {
                bits[i] += (nums[j] >> i)&1;
            }
            res |= (bits[i] % 3) << i;
        }
        return res;
    }
}
