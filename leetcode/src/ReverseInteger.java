/**
 * Created by hduser on 15-11-20.
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */
public class ReverseInteger {
    public int reverse(int x) {
        return helper(x);
    }
    private int helper(int x){
        long num = x;
        boolean flag = false;
        if( x < 0) {
            flag = true;
            num = -num;
        }
        long res = 0;
        long mid;
        while (num > 0){
            mid = num % 10;
            res *= 10;
            res += mid;
            num = num / 10;
        }
        if(flag) res = -res;
        // 判断是否越界
        if(res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) return 0;
        else return (int)res;
    }
}
