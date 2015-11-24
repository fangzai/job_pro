/**
 * Created by hduser on 15-11-20.
 * Write an algorithm to determine if a number is "happy".
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 * Example: 19 is a happy number
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */
import java.util.ArrayList;
public class HappyNumber {
    private ArrayList<Integer> myFoot = new ArrayList<Integer>();
    public boolean isHappy(int n) {
        return helper(n);
    }
    private boolean helper(int n) {
        if(n < 0) return false;
        int num = n;
        while (true) {
            myFoot.add(num);
            num = generateNextNumber(num);//这个地方给的测试例子可能是num = 1
            if(myFoot.contains(num) && num != 1) return false;
            else {
                if(num == 1) return true;
            }
        }
    }
    private int generateNextNumber(int num) {
        int res = 0;
        int n = num;
        int mid;
        while(n > 0) {
            mid = n % 10;
            res += mid * mid;
            n = n/10;
        }
        return res;
    }
}
