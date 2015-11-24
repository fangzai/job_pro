/**
 * Created by hduser on 15-11-23.
 * Given numRows, generate the first numRows of Pascal's triangle.

 For example, given numRows = 5,
 Return

 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 */
import java.util.ArrayList;
import java.util.List;
public class PascalsTriangle {
    public List<List<Integer>> generate(int numRows) {
        return helper(numRows);
    }
    private List<List<Integer>> helper(int num) {
        List<Integer> lst = new ArrayList<Integer>();
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (num <= 0) {
            return res;
        }
        lst.add(1);
        res.add(lst);
        if (num == 1) {
            return res;
        }
        lst = new ArrayList<Integer>();
        lst.add(1);
        lst.add(1);
        res.add(lst);
        if (num == 2) {
            return res;
        }
        for (int i = 2; i < num; ++i) {
            lst = new ArrayList<Integer>();
            lst.add(1);
            for (int j = 1; j < i; ++j) {
                lst.add(res.get(i - 1).get(j - 1) + res.get(i - 1).get(j));
            }
            lst.add(1);
            res.add(lst);
        }
        return res;
    }
}
