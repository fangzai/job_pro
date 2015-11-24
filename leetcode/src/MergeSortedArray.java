/**
 * Created by hduser on 15-11-21.
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n)
 * to hold additional elements from nums2. The number of elements initialized in
 * nums1 and nums2 are m and n respectively.
 */
public class MergeSortedArray {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        helper(nums1, m, nums2, n);
    }
    private void helper(int[] nums1, int m, int[] nums2, int n) {
        int[] nums = new int[m + n];
        int i = 0, j = 0;
        int val1, val2;
        int index = 0;
        while (i < m || j < n) {
            val1 = Integer.MAX_VALUE;
            val2 = Integer.MAX_VALUE;
            if (i < m) {
                val1 = nums1[i];
            }
            if (j < n) {
                val2 = nums2[j];
            }
            if (val1 < val2) {
                nums[index] = val1;
                i++;
            } else {
                nums[index] = val2;
                j++;
            }
            index++;
        }

        for (i = 0; i < m + n; ++i) {
            nums1[i] = nums[i];
        }
    }
}
