/**
 * Created by hduser on 15-11-18.
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}"
 * are all valid but "(]" and "([)]" are not.
 */
import java.util.Stack; //关于stack的用法

public class ValidParentheses {
    public boolean isValid(String s) {
        return helper(s);
    }
    private boolean helper(String s){
        int len = s.length();
        if(len == 0) return true;
        Stack<Character> st = new Stack<Character>();
        //stack的用法，和c++几乎一模一样
        for(int i = 0; i < len; ++i) {
            if (s.charAt(i) =='{' || s.charAt(i) =='(' || s.charAt(i) =='[') {
                st.push(s.charAt(i));
            }else{
                if(st.empty()){
                    return false;
                }else{
                    String match = st.peek().toString();
                    Character s1 = s.charAt(i);
                    match = match.concat(s1.toString());
                    //if(match == "{}" || match == "[]" || match == "()"){
                    // == 符号表示的比较对象的存储地址，而equals才是比较的内容是否一致
                    if(match.equals("{}") || match.equals("[]") || match.equals("()")){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
}
