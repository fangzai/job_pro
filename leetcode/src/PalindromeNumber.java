/**
 * Created by hduser on 15-11-23.
 * Determine whether an integer is a palindrome. Do this without extra space.
 */
public class PalindromeNumber {
    public boolean isPalindrome(int x) {
        return helper(x);
    }
    private boolean helper(int x) {
        if (x < 0) {
            return false;
        }
        int base = 1;
        int num = x;
        while (num >= 10) {
            num /= 10;
            base *= 10;
        }
        int up = 0, low = 0;
        num = x;
        while (base > 1) {
            up = num / base;
            num %= base;
            low = num % 10;
            num /= 10;
            base /= 100;
            if (up != low) {
                return false;
            }
        }
        return true;
    }
}
