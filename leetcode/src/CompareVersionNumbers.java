/**
 * Created by hduser on 15-11-19.
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three",
 * it is the fifth second-level revision of the second first-level revision.
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 */
public class CompareVersionNumbers {
    public int compareVersion(String version1, String version2) {
        return hepler(version1, version2);
    }
    private int hepler(String s1, String s2) {
        int i = 0, j = 0;
        int v1,v2;
        char sep = '.';
        while (i < s1.length() || j<s2.length()) {
            v1 = 0;  //重置计数起点
            v2 = 0;
            while (i < s1.length() && s1.charAt(i) != sep) {
                v1 *= 10;
                v1 += s1.charAt(i) - '0';
                i++;
            }
            i++;//跳过分割点
            while (j < s2.length() && s2.charAt(j) != sep) {
                v2 *= 10;
                v2 += s2.charAt(j) - '0';
                j++;
            }
            j++;//跳过分割点
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;

        }
        return 0;
    }
}
