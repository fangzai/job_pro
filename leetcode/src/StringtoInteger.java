/**
 * Created by hduser on 15-11-24.
 * Implement atoi to convert a string to an integer.
 */
public class StringtoInteger {
    public int myAtoi(String str) {
        return helper(str);
    }
    private int helper(String str) {
        int index = 0;
        long res = 0;
        // 跳过所有的空白
        char whiteSpace = ' ';
        while (index < str.length() && str.charAt(index) == whiteSpace) {
            index++;
        }
        if (index == str.length()) {
            return 0;
        }
        boolean flag = false;    //　正负号的标记
        if (str.charAt(index) == '+' ) {
            index++;
            flag = false;
        } else if (str.charAt(index) == '-') {
            index++;
            flag = true;
        }
        for(int i = index; i < str.length(); ++i) {
            if (Character.isDigit(str.charAt(i))) {
                res *= 10;
                res += str.charAt(i) - '0';
                //　必须要在中间直接中断返回，因为可能是很长的一段字符
                if (flag && -res < Integer.MIN_VALUE) {
                    return Integer.MIN_VALUE;
                }
                if (!flag && res > Integer.MAX_VALUE) {
                    return Integer.MAX_VALUE;
                }
            } else {
                break;
            }
        }
        if (flag) {
            res = res * (-1);
        }
        return (int)res;
    }
}
