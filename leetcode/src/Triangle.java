/**
 * Created by hduser on 15-12-2.
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

 For example, given the following triangle
 [
 [2],
 [3,4],
 [6,5,7],
 [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 */
import java.util.ArrayList;
import java.util.List;

public class Triangle {
    public int minimumTotal(List<List<Integer>> triangle) {
        return helper(triangle);
    }
    private int helper(List<List<Integer>> triangle) {
        if (triangle.size() <= 0) {
            return 0;
        }
        ArrayList<Integer> dp = new ArrayList<Integer>();
        int end = triangle.size();
        for (int i = 0; i < triangle.get(end - 1).size(); ++i) {
            dp.add(0);
        }
        for (int i = end - 1; i >= 0; --i) {
            for (int j = 0; j < triangle.get(i).size(); ++j) {
                dp.set(j, triangle.get(i).get(j) + dp.get(j));
                //dp.set(j, Math.min(triangle.get(i).get(j) + dp.get(j), triangle.get(i).get(j + 1) + dp.get(j + 1)));
            }
            for (int j = 0; j < triangle.get(i).size() - 1; ++j) {
                dp.set(j, Math.min(dp.get(j), dp.get(j + 1)));
            }
            //如果说只用上面的一句话会出现bug,导致最后一次循环执行不到
            //for (int j = 0; j < triangle.get(i).size() - 1; ++j) {
                //dp.set(j, Math.min(triangle.get(i).get(j) + dp.get(j), triangle.get(i).get(j + 1) + dp.get(j + 1)));
            //}
        }
        return dp.get(0);
    }
}
