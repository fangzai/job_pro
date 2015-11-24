/**
 * Created by hduser on 15-11-21.
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
public class RemoveElement {
    public int removeElement(int[] nums, int val) {
        return helper(nums, val);
    }
    private int helper(int[] nums, int val) {
        if(nums.length == 0) return 0;
        int current = 0, i = 0;
        while(i < nums.length) {
            if(nums[i] != val) {
                nums[current] = nums[i];
                current++;
            }
            i++;
        }
        return current;
    }
}
