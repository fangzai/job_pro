/**
 * Created by hduser on 15-12-7.
 * Given n non-negative integers a1, a2, ..., an, where each represents
 * a point at coordinate (i, ai). n vertical lines are drawn such that
 * the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
 * which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container.
 */
public class ContainerWithMostWater {
    public int maxArea(int[] height) {
        return helper(height);
    }
    private int helper(int[] height) {
        // 从两边开始收缩
        if (height.length <= 1) {
            return 0;
        }
        int res = 0;
        int ps = 0, pe = height.length - 1;
        while (ps < pe) {
            int tmp = Math.min(height[ps], height[pe]) * (pe - ps);
            res = Math.max(res, tmp);
            // 从较小的边开始收缩
            if (height[ps] < height[pe]) {
                int l = height[ps];
                while (ps <pe && height[ps] <= l) {
                    ps++;
                }
            } else {
                int r = height[pe];
                while (pe > ps && height[pe] <= r) {
                    pe--;
                }
            }
        }
        return res;
    }
}
