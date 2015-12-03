/**
 * Created by hduser on 15-12-3.
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * For example,
 If n = 4 and k = 2, a solution is:

 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]
 */
import java.util.ArrayList;
import java.util.List;
public class Combinations {
    public List<List<Integer>> combine(int n, int k) {
        return helper(n, k);
    }
    private List<List<Integer>> helper(int n, int k) {
        int depth = 0;
        ArrayList<Integer> src = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            src.add(i + 1);
        }
        List<List<Integer>> result = new ArrayList<>();
        ArrayList<Integer> ls = new ArrayList<>();
        int start = 0;
        dfs(result, ls, src, depth, k, start);
        return result;
    }
    private void dfs(List<List<Integer>> result, ArrayList<Integer> ls,
                     ArrayList<Integer> src, int depth, int k, int start) {
        // result 保存最后结果
        // ls　临时结果
        //　src原list
        // depth递归深度
        if (depth >= k) {
            result.add((List<Integer>) ls.clone());
            return;
        }else {
            for (int i = start; i < src.size(); ++i ) {
                ls.add(src.get(i));
                dfs(result, ls, src, depth + 1, k, i + 1);
                ls.remove(ls.size() - 1);
            }
        }
    }
}
