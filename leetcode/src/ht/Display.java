package ht;

/**
 * Created by hduser on 15-11-25.
 */
public class Display {
    public void displayArray(int[] nums) {
        for(int i = 0; i < nums.length; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
    public void displayArray(int[] nums, int m) {
        for(int i = 0; i < m; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
    public void displayArray(double[] nums) {
        for(int i = 0; i < nums.length; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
    public void displayArray(double[] nums, int m) {
        for(int i = 0; i < m; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
}
