/**
 * Created by hduser on 15-11-20.
 * Given an array of size n, find the majority element.
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 */

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;

public class MajorityElement {
    public int majorityElement(int[] nums) {
        return helper(nums);
    }
    private int helper(int[] nums) {
        //return sortBrute(nums);
        return vote(nums);
    }
    private int sortBrute(int[] nums) {
        if(nums.length == 0) return -1;
        //下面那个是比较器
        Comparator<Integer> cmp = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if(o1.intValue() > o2.intValue()) {
                    return -1;
                } else if(o1.intValue() < o2.intValue()) {
                    return 1;
                } else {
                    return 0;
                }
            }
        };
        ArrayList<Integer> ar_nums = new ArrayList<Integer>();
        for(int i = 0; i < nums.length; ++i){
            ar_nums.add(nums[i]);
        }
        //System.out.println(ar_nums);
        Collections.sort(ar_nums, cmp);
        //System.out.println(ar_nums);
        return ar_nums.get(ar_nums.size()/2);
    }
    private int vote(int[] nums) {
        if(nums.length == 0) return -1;
        int candidate = nums[0];
        int count = 1;
        for(int i = 1; i < nums.length; ++i) {
            if(candidate != nums[i]) {
                count--;
                if(count <= 0) {
                    candidate = nums[i];
                    count = 1;
                }
            } else {
                count++;
            }
        }
        return candidate;
    }
}
