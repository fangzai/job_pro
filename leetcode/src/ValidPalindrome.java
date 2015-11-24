import javax.print.DocFlavor;

/**
 * Created by hduser on 15-11-21.
 * Given a string, determine if it is a palindrome, considering
 * only alphanumeric characters and ignoring cases.
 * For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.
 */
public class ValidPalindrome {
    public boolean isPalindrome(String s) {
        return helper(s);
    }
    private boolean helper(String str) {
        int i = 0;
        int j = str.length() - 1;
        while (i < j) {
            while (!isAlphanumeric(str.charAt(i)) && i < j) {
                i++;
            }
            while (!isAlphanumeric(str.charAt(j)) && i < j) {
                j--;
            }
            char a,b;
            if(Character.isDigit(str.charAt(i)) || Character.isDigit(str.charAt(i))) {
                //只要有一个是数字
                if(str.charAt(i) != str.charAt(j)) {
                    return false;
                }
            } else {
                a = Character.toLowerCase(str.charAt(i));
                b = Character.toLowerCase(str.charAt(j));
                if(a != b) {
                    return  false;
                }
            }
            i++;
            j--;
        }
        return true;

    }
    private boolean isAlphanumeric(char a) {
        if(Character.isDigit(a)) {
            return true;
        }
        if(Character.isAlphabetic(a)) {
            return true;
        }
        return false;
    }
}
