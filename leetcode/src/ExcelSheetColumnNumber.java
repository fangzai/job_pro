/**
 * Created by hduser on 15-11-19.
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * For example:
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 */
public class ExcelSheetColumnNumber {
    public int titleToNumber(String s) {
        return helper(s);
    }
    private int helper(String str) {
        int res = 0;
        int range = 26;
        for(int i = 0; i < str.length(); ++i) {
            res *= range;
            res += str.charAt(i) - 'A' + 1;
        }
        return res;
    }
}
