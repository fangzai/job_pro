/**
 * Created by hduser on 15-11-23.
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,
 * Return [1,3,3,1].
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class PascalsTriangleII {
    public List<Integer> getRow(int rowIndex) {
        return helper(rowIndex);
    }
    private List<Integer> helper(int num) {
        //List<Integer> res = new ArrayList<Integer>(num + 1);
        Integer[] ele = new Integer[num + 1];
        Arrays.fill(ele, 1);
        List<Integer> res = Arrays.asList(ele);

        if (num <= 0) {
            return res;
        }
        if (num == 1) {
            return  res;
        }
        System.out.println(res);
        for (int i = 2; i <= num; ++i) {
            for (int j = i - 1; j >= (i + 1)/2; --j) {
                res.set(j, res.get(j - 1) + res.get(j));
            }
            for (int j = 1; j < (i + 1)/2; ++j) {
                res.set(j, res.get(i -j));
            }
        }
        return res;
    }
}
