/**
 * Created by hduser on 15-12-3.
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 */
public class NextPermutation {
    public void nextPermutation(int[] nums) {
        helper(nums);
    }
    private void helper(int[] nums) {
        int i = nums.length - 2;

        while(i >= 0 && nums[i] >= nums[i + 1]) {
            i--;  // Find first id that breaks descending order i
        }

        int j = nums.length - 1;
        if(i >= 0) {                                  // If not entirely descending
            while(i < j && nums[j] <= nums[i]) {
                j--;   // Find rightmost first larger number j
            }
            swap(nums, i, j);                         // Switch i and j
        }

        reverse(nums, i + 1, nums.length - 1);        // Reverse the descending sequence
    }

    public void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public void reverse(int[] nums, int i, int j) {
        while(i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
}
