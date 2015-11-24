/**
 * Created by hduser on 15-11-21.
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example,
 * Given s = "Hello World",
 * return 5.
 */
public class LengthofLastWord {
    public int lengthOfLastWord(String s) {
        return helper(s);
    }
    private int helper(String str) {
        if(str.length() == 0) return 0;
        int i = str.length() - 1;

        while (i >= 0 && !Character.isAlphabetic(str.charAt(i))) {
            i--;
        }
        int len = 0;
        while (i >= 0 && Character.isAlphabetic(str.charAt(i))) {
            i--;
            len++;
        }
        return len;
    }
}
