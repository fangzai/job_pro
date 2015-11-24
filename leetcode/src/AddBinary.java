/**
 * Created by hduser on 15-11-21.
 * Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */
public class AddBinary {
    public String addBinary(String a, String b) {
        return helper(a, b);
    }
    private String helper(String a, String b) {
        StringBuilder str = new StringBuilder();
        int i = a.length() - 1;
        int j = b.length() - 1;
        int s, t;
        int num = 0;
        int cur = 0;
        while (i >= 0 || j >= 0) {
            s = 0;
            t = 0;
            if (i >= 0) {
                s = a.charAt(i) - '0';
            }
            if (j >= 0) {
                t = b.charAt(j) - '0';
            }
            num += s + t ;
            cur = num % 2;
            num = num / 2;
            str.append(cur);
            i--;
            j--;
        }
        if (num == 1) {
            str.append(num);
        }
        str = str.reverse();
        return str.toString();
    }
}
