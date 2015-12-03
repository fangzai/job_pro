/**
 * Created by hduser on 15-12-3.
 * Given a collection of numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 */
import java.util.List;
import java.util.ArrayList;
public class Permutations {
    public List<List<Integer>> permute(int[] nums) {
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
}
