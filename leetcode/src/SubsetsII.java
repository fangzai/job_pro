/**
 * Created by hduser on 15-12-3.
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.

 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If nums = [1,2,2], a solution is:

 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
 *
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Arrays;
public class SubsetsII {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        return helper(nums);
    }
    private Comparator<Integer> cmp = new Comparator<Integer>() {
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
        Arrays.sort(nums);

//        List<List<Integer>> result = new ArrayList<>();
//        int[] mark = new int[nums.length];
//        Arrays.fill(mark, 0);
//        int depth = 0;
//        ArrayList<Integer> arr = new ArrayList<>();
//        for (int i = 0; i < nums.length; ++i) {
//            arr.add(nums[i]);
//        }
//        Collections.sort(arr);
//        dfs(mark, result, arr, depth);
//        return result;

        return iterative(nums);
    }
    private List<List<Integer>> iterative(int[] nums) {
        int len = 0;
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();
        result.add(tmp);

        int pre = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i == 0 || nums[i] != nums[i-1]) {
                pre = result.size(); //　如果说没有出现重复元素的话
                // 上一步骤加入了num[i]但是未有出现重复元素　子集的个数
            }

            len = result.size();
            //　起点需要变化因为num[i]和num[i-1]重复，
            // 所以当前num[i]只能加入上一步中有num[i-1]的集合中
            for (int j = len - pre; j < len; ++j) {
                //tmp = (ArrayList<Integer>)((ArrayList)result.get(j)).clone();
                tmp = new ArrayList<>(result.get(j));
                tmp.add(nums[i]);
                result.add(tmp);
            }
        }
        return result;
    }
    private void dfs(int[] mark,List<List<Integer>> result, ArrayList<Integer> nums, int depth) {
        if (depth == nums.size()) {
            // 递归到了底部
            List<Integer> ret = new ArrayList<>();
            for (int i = 0; i < nums.size(); ++i) {
                if (mark[i] != 0) {
                    ret.add(nums.get(i));
                }
            }
            Collections.sort(ret, cmp);
            result.add(ret);
        } else {
            if (depth == 0 || nums.get(depth) != nums.get(depth - 1) ||
                    (nums.get(depth) == nums.get(depth - 1) && (mark[depth - 1] == 1) )) {
                mark[depth] = 0;
                dfs(mark, result, nums, depth + 1);
                mark[depth] = 1;
                dfs(mark, result, nums, depth + 1);
                //　当出现重复的时候，只有当前面的用到过了，后面的才可以用
            } else {
                mark[depth] = 0;
                dfs(mark, result, nums, depth + 1);
            }
        }
    }
}
