/**
 * Created by hduser on 15-11-19.
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * For example:
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB
 */
public class ExcelSheetColumnTitle {
    public String convertToTitle(int n) {
        return helper(n);
    }
    private String helper(int n) {
        int num = n;
        int range = 26;
        StringBuilder myRes = new StringBuilder();
        while (num > 0) {
            num--; //这里减1是因为区余数的时候方便和序号对应
            int tmp = num % range;
            char s = (char)('A' + tmp);
            // char对应的Character就类似与int 对应于Integer
            // 这里相加之后需要有一个强制转换
            myRes.append(s);
            num = num / range;
        }
        return myRes.reverse().toString();
    }
}
