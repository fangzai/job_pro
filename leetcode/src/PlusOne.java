import java.util.Arrays;

/**
 * Created by hduser on 15-11-21.
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list
 */
public class PlusOne {
    public int[] plusOne(int[] digits) {
        return helper(digits);
    }
    private int[] helper(int[] digits) {
        int num = 1;
        for(int i = digits.length-1; i >= 0; --i) {
            if(digits[i] == 9 && num == 1) {
                digits[i] = 0;
                num = 1;
            } else {
                digits[i] += num;
                num = 0;
            }
        }

        if(num == 1){
            int[] res = new int[digits.length + 1];
            res[0] = num;
            for(int i = digits.length-1; i >= 0; --i) {
                res[i+1] = digits[i];
            }
            return res;
        } else {
            return digits;
        }
    }
}
