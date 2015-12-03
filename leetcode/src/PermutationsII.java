/**
 * Created by hduser on 15-12-3.
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 *
 */
import java.util.List;
import java.util.ArrayList;
public class PermutationsII {
    public List<List<Integer>> permuteUnique(int[] nums) {
        return helper(nums);
    }
    private List<List<Integer>> helper(int[] nums) {
        ArrayList<Integer> ele = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            ele.add(nums[i]);
        }
        List<List<Integer>> result = new ArrayList<>();
        recursive(result, ele, 0, nums.length - 1);

        return result;
    }
    private void recursive(List<List<Integer>> result, ArrayList<Integer> ls, int m, int k) {
        if (m == k) {
            result.add(( ArrayList<Integer>)ls.clone());
            return;
        } else {
            for (int i = m; i <= k; ++i) {
                // 需要做一个判定　m -> i-1之间有没有元素nums[~]和nums[i]一样
                if (duplicateDeal(ls, m, i)) {
                    continue; //如果有一样的就没有比较交换了，因为重复了
                }
                swap(ls, m, i);
                recursive(result, ls, m + 1, k);
                swap(ls, m, i);
            }
        }
    }
    private void swap(ArrayList<Integer> ls, int i, int j) {
        Integer tmp = ls.get(i);
        ls.set(i, ls.get(j));
        ls.set(j, tmp);
    }
    private boolean duplicateDeal(ArrayList<Integer> ls, int start, int over) {
        for (int i = start; i < over; ++i) {
            if (ls.get(i) == ls.get(over)) {
                //　这里是数值比较而不是对象比较
                return true;
            }
        }
        return false;
    }
}
