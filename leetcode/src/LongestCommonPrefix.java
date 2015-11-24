/**
 * Created by hduser on 15-11-24.
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
public class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        return helper(strs);
    }
    private String helper(String[] strs) {
        if (strs.length <= 0) {
            return "";
        }
        if (strs.length == 1) {
            return strs[0];
        }
        StringBuilder res = new StringBuilder();
        int len = Integer.MAX_VALUE;
        for (int i = 0; i < strs.length; ++i) {
            if ( strs[i].length() < len) {
                len = strs[i].length();
            }
        }
        boolean flag = false;
        for (int i = 0; i < len; ++i) {
            flag = true;
            for (int j = 1; j < strs.length; ++j) {
                if (strs[j].charAt(i) != strs[0].charAt(i)) {
                    flag =false;
                    break;
                }
            }
            if (flag) {
                res.append(strs[0].charAt(i));
            } else {
                break;
            }
        }
        return res.toString();
    }
}
