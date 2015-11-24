/**
 * Created by hduser on 15-11-18.
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 */
public class CountAndSay {
    public String countAndSay(int n) {
        return hepler(n);
    }
    private String hepler(int n) {
        String res = null;
        if(n <= 0) return res;
        res = "1";
        for(int i = 1; i < n; ++i) {
            res = res.concat("\n");
            //这里append 最后一个特别的字符 是因为generateNext函数不会识别最后一个字符
            res = generateNext(res);
            //System.out.println(i + "......" + res);
        }
        return res;
    }
    private String generateNext(String str) {
        Character last = str.charAt(0);  //记录上一个字符
        StringBuilder mySB = new StringBuilder(); //StringBuilder更加类似于的用法
        String res;
        int count = 0;
        for(int i = 0; i < str.length(); ++i) {
            if(str.charAt(i) == last){
                count++;//如果和前面的字符一样，就一直计数
            } else {
                mySB.append(count + "");
                //不一样的时候才开始输出
                mySB.append(last);
                count = 1;
                last = str.charAt(i);
            }
        }
        return mySB.toString();
    }
}
