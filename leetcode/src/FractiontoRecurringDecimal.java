import java.util.HashMap;

/**
 * Created by hduser on 15-12-1.
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * For example,
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 *
 */
public class FractiontoRecurringDecimal {
    public String fractionToDecimal(int numerator, int denominator) {
        return helper(numerator, denominator);
    }
    private String helper(long numerator, long denominator) {
        if (denominator == 0) {
            return "";
        } else if (numerator == 0) {
            return "0";
        }
        StringBuilder res = new StringBuilder();
        if ((numerator < 0) ^(denominator < 0)) {
            res.append("-");
        }
        numerator = Math.abs(numerator);  //这两句话一定要放在if外面
        denominator = Math.abs(denominator);

        // integer part
        if (numerator / denominator == 0) {
            res.append("0");
        } else {
            long quotient = numerator / denominator;
            res.append(quotient);
            if (numerator % denominator == 0) {
                return res.toString(); //divisible
            } else {
                // not divisible, numerator as remainder
                numerator -= quotient * denominator;
            }
        }
        // decimal part
        res.append(".");

        StringBuilder demcial;
        HashMap<Long, Integer> store = new HashMap<Long, Integer>();
        long remainder = numerator;
        while (remainder > 0) {
            if (store.containsKey(remainder)) {
                res.insert(store.get(remainder).intValue(), "(");
                res.append(")");
                break;
            }
            store.put(remainder, res.length());
            remainder *= 10;
            res.append(remainder / denominator);
            remainder %= denominator;
        }

        return res.toString();
    }
}
