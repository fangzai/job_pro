/**
 * Created by hduser on 15-12-3.
 * Given a set of distinct integers, nums, return all possible subsets.

 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If nums = [1,2,3], a solution is:

 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
 */

import java.util.*;

public class Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        return helper(nums);
    }
    Comparator<Integer> cmp = new Comparator<Integer>() {
        @Override
        public int compare(Integer o1, Integer o2) {
            if (o1 > o2) {
                return 1;
            } else if (o1 < o2) {
                return -1;
            } else {
                return 0;
            }
        }
    };
    private List<List<Integer>> helper(int[] nums) {
//        List<List<Integer>> result = new ArrayList<>();
//        int[] mark = new int[nums.length];
//        Arrays.fill(mark, 0);
//        int depth = 0;
//        dfs(mark, result, nums, depth);
//        return result;
        return iterative(nums);
    }
    private List<List<Integer>> iterative(int[] nums) {
        int len = (int)Math.pow(2, nums.length);
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < len; ++i) {
            ArrayList<Integer> tmp = new ArrayList<>();
            for (int j = 0; j < nums.length; ++j) {
                if ((i & (1<<j)) != 0) {
                    tmp.add(nums[j]);
                }
            }
            Collections.sort(tmp, cmp);
            result.add(tmp);
        }
        return result;
    }
    //　下面用的是动态规划
    private List<List<Integer>> iterative2(int[] nums) {
        int len = 0;
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();
        result.add(tmp);
        for (int i = 0; i < nums.length; ++i) {
            len = result.size();
            for (int j = 0; j < len; ++j) {
                //tmp = (ArrayList<Integer>)((ArrayList)result.get(j)).clone();
                tmp = new ArrayList<>(result.get(j));
                tmp.add(nums[i]);
                result.add(tmp);
            }
        }
        return result;
    }
    private void dfs(int[] mark,List<List<Integer>> result, int[] nums, int depth) {
        if (depth == nums.length) {
            // 递归到了底部
            List<Integer> ret = new ArrayList<>();
            for (int i = 0; i < nums.length; ++i) {
                if (mark[i] != 0) {
                    ret.add(nums[i]);
                }
            }
            Collections.sort(ret, cmp);
            result.add(ret);
        } else {
            mark[depth] = 0;
            dfs(mark, result, nums, depth + 1);
            mark[depth] = 1;
            dfs(mark, result, nums, depth + 1);
        }
    }
}
