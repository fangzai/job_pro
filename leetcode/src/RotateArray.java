/**
 * Created by hduser on 15-11-20.
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7]
 * is rotated to [5,6,7,1,2,3,4].
 * Note:
 * Try to come up as many solutions as you can,
 * there are at least 3 different ways to solve this problem.
 */
public class RotateArray {
    public void rotate(int[] nums, int k) {
        helper(nums, k);
    }
    private void helper(int[] nums, int k) {
        //extraSpace(nums, k);
        inPlace(nums, k);
    }
    private void extraSpace(int[] nums, int k) {
        if(nums.length == 0 )return;
        k = k % nums.length;
        int[] res = new int[nums.length];
        //直接用copy函数
        System.arraycopy(nums, nums.length - k, res, 0, k);
        System.arraycopy(nums, 0, res, k, nums.length - k);
        System.arraycopy(res, 0, nums, 0, nums.length);
    }
    private void inPlace(int[] nums, int k) {
        //原地翻转三次就行了
        if(nums.length == 0 )return;
        k = k % nums.length;
        reverse(nums, 0, nums.length - 1 );
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
        return;
    }
    private void reverse(int[] arr, int st, int en) {
        if(arr == null || arr.length == 1) return;
        int tmp;

        for(int i = 0 ; i < (en - st + 1)/2; ++i) {
            tmp = arr[st + i];
            arr[st + i] = arr[en - i];
            arr[en - i] = tmp;
        }
        /*
        int i = st, j = en;
        while(i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }*/

    }
}
