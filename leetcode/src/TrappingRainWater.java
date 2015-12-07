/**
 * Created by hduser on 15-12-7.
 * Given n non-negative integers representing an elevation map where
 * the width of each bar is 1, compute how much water it is able to trap after raining.
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */
public class TrappingRainWater {
    public int trap(int[] height) {
        return helper(height);
    }
    private int helper(int[] height) {

        //　如果出现两个最高峰的话，这个方法就不能用了
        //int res = 0;
        //res += scan(height);
        //reverse(height);
        //res += scan(height);
        // res;
        // 第二种方法　直接依次遍历一遍做两个循环但是第二个的界限需要限定一下
        //return streamFlow(height);
        // 第三种方法　简化了遍历过程 从两边向中间遍历
        return simplifyFlow(height);
    }
    private void reverse(int[] height) {
        int ps = 0, pe = height.length -1, tmp;
        while (ps < pe) {
            tmp = height[pe];
            height[pe] = height[ps];
            height[ps] = tmp;
            pe--;ps++;
        }
    }
    private int scan(int[] height) {
        if (height.length <= 1) {
            return 0;
        }
        int ps = 0, pe = 1;
        int low = 0, sum = 0, res = 0;
        // 从左往右扫描一次
        while (pe < height.length) {
            low = height[ps];
            sum = 0;
            while (pe <= height.length - 1 && height[ps] > height[pe]) {
                sum += low - height[pe];
                pe++;
            }
            if (pe <= height.length - 1 && height[ps] <= height[pe]){
                res += sum;
            }
            ps = pe;
            pe++;
        }
        return res;
    }
    private int streamFlow(int[] height) {
        if (height.length <= 1) {
            return 0;
        }
        int ps = 0, pe = 1;
        int low = 0, sum = 0, res = 0;
        // 从左往右扫描一次
        while (pe < height.length) {
            low = height[ps];
            sum = 0;
            while (pe <= height.length - 1 && height[ps] > height[pe]) {
                sum += low - height[pe];
                pe++;
            }
            if (pe <= height.length - 1 && height[ps] <= height[pe]){
                res += sum;
                ps = pe;
            }
            pe++;
        }
        int left = ps;
        // 从右往左扫描一次
        pe = height.length -1;
        ps = pe - 1;
        while (ps >= left) {
            low = height[pe];
            sum = 0;
            while (ps >= 0 && height[ps] < height[pe]) {
                sum += low - height[ps];
                ps--;
            }
            if (ps >= 0 && height[ps] >= height[pe]) {
                res += sum;
                pe = ps;
            }
            ps--;
        }
        return res;
    }
    private int simplifyFlow(int[] height) {
        if (height.length <= 1) {
            return 0;
        }
        int ps = 0, pe = height.length - 1;
        int low = 0, res = 0, secondHec = 0;
        while (ps < pe) {
            if (height[ps] < height[pe]) {
                secondHec = Math.max(height[ps], secondHec);
                res += secondHec - height[ps];
                ps++;
            } else {
                secondHec = Math.max(height[pe], secondHec);
                res += secondHec - height[pe];
                pe--;
            }
        }
        return res;
    }
}
