import javafx.scene.CacheHint;

import java.util.Arrays;

/**
 * Created by hduser on 15-11-21.
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 * For example,
 * Given "egg", "add", return true.
 * Given "foo", "bar", return false.
 * Given "paper", "title", return true.
 * Note:
 * You may assume both s and t have the same length.
 */
import java.util.Collection;
import java.util.Map;
import java.util.HashMap;

public class IsomorphicStrings {
    public boolean isIsomorphic(String s, String t) {
        return helper(s, t);
    }
    private boolean helper(String s, String t) {
        //
        //return arrayMethod(s, t);
        return mapMethod(s, t);
    }
    private boolean mapMethod(String s, String t) {
        if(s.length() == 0) return true;
        Map<Character, Character> myMaps = new HashMap<Character, Character>();
        Map<Character, Character> myMapt = new HashMap<Character, Character>();
        Character a = null;
        Character b = null;
        for(int i = 0; i < s.length(); ++i) {
            a = new Character(s.charAt(i));
            b = new Character(t.charAt(i));
            if(!myMaps.containsKey(a) && !myMapt.containsKey(b)) {
                myMaps.put(a, b);
                myMapt.put(b, a);
            } else {
                //if(!myMaps.get(a).equals(b) || !myMapt.get(b).equals(a))
                //不能直接用上面的那句话需要判定myMaps.get(a)是不是null
                if((myMaps.containsKey(a) && !myMaps.get(a).equals(b)) ||
                        ( myMapt.containsKey(b) && !myMapt.get(b).equals(a))) {
                    return false;
                }
            }
        }
        return true;
    }
    private boolean arrayMethod(String s, String t) {
        if(s.length() == 0) return true;
        int n = 256;      //字母总共就只有256
        char initChar = (char)0;
        char[] myMaps = new char[n];
        Arrays.fill(myMaps, initChar);
        char[] myMapt = new char[n];
        Arrays.fill(myMaps, initChar);
        int index1 = 0;
        int index2 = 0;
        for(int i = 0; i < s.length(); ++i) {
            index1 = 0 + s.charAt(i);
            index2 = 0 + t.charAt(i);
            if(myMaps[index1] == initChar && myMapt[index2] == initChar) {
                //必须要两个都没有被替换过才能替换
                myMaps[index1] = t.charAt(i);
                myMapt[index2] = s.charAt(i);
            } else {
                if(myMaps[index1] != t.charAt(i) || myMapt[index2] != s.charAt(i)) {
                    return false;
                }
            }
        }
        return true;
    }
}
