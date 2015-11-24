/**
 * Created by hduser on 15-11-20.
 * Given an integer n, return the number of trailing zeroes in n!.
 * Note: Your solution should be in logarithmic time complexity.
 */
public class FactorialTrailingZeroes {
    public int trailingZeroes(int n) {
        return helper(n);
    }
    private int helper(int n) {
        if(n < 1) return 0;
        int res = 0;
        //相当于计算５的个数
        int num = n;
        while(num > 0) {
            num = num / 5;
            res += num;
        }
        return res;
    }
}
