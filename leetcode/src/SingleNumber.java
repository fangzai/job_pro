/**
 * Created by hduser on 15-11-18.
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
public class SingleNumber {
    public int singleNumber(int[] nums) {
        if(nums.length < 1) return 0;
        int res = nums[0];
        for(int i = 1; i < nums.length; ++i){
            res ^=nums[i];
        }
        return res;
    }
}
