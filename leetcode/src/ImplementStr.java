import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by hduser on 15-11-19.
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */
public class ImplementStr {
    public int strStr(String haystack, String needle) {
        return helper(haystack, needle);
    }
    private int helper(String haystack, String needle){
        // 暴力搜索的方法
        //return bruteSearch(haystack, needle);
        return briefKMP(haystack, needle);
    }
    private int bruteSearch(String haystack, String needle){
        int i = 0, j = 0;
        while (j < needle.length() && i < haystack.length()){
            if( haystack.charAt(i + j)== needle.charAt(j)){
                j++;
            }else{
                j = 0;
                i++;
            }
        }
        if(j == needle.length()) return i;
        else return -1;
    }
    // 下面实现kmp算法
    private void generateNextValue(String pattern, ArrayList<Integer> next){
        int i = 0;
        int j = -1;
        next.add(-1);//第一个前固定没有 就是-1
        while ((i+1) < pattern.length()){
            if(j == -1 || pattern.charAt(i) == pattern.charAt(j)){
                i++;j++;
                if(pattern.charAt(i) != pattern.charAt(j)) next.add(j);
                else next.add(next.get(j));
            }else j = next.get(j).intValue();
        }
    }
    private int briefKMP(String haystack, String needle){
        //时间复杂度是O(n+m) 空间复杂度O(m)
        if(needle.length() == 0) return 0; //第一个位置就是
        if(haystack.length() == 0 ) return -1;//此时已经排除了needle为空的情况
        ArrayList<Integer> next = new ArrayList();
        //next.add(3);
        //next.add(4);
        //System.out.println(next.getClass());
        generateNextValue(needle, next);
        //System.out.println(next);
        int i, j;
        i = j = 0;
        int index = 0;
        while ( i< haystack.length() && j < needle.length()){
            if(haystack.charAt(i) == needle.charAt(j)){
                i++;
                j++;//和暴力搜索是一样的
            }else{
                //根据next数组里面的值来确定跳过的步
                index += j - next.get(j).intValue();
                if(next.get(j).intValue() != -1) j = next.get(j).intValue();
                else{
                    j = 0; // 表示kmp算法并没有用上
                    i++;
                }
            }
        }
        if(j == needle.length()) return index;
        else return -1;
    }
}
