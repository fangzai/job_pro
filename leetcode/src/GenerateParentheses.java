/**
 * Created by hduser on 15-12-2.
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */
import java.util.ArrayList;
import java.util.List;
public class GenerateParentheses {
    private List<String> result = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        return helper(n);
    }
    private List<String> helper(int n) {
        StringBuilder str = new StringBuilder();
        dfs(str, n, n);
        return this.result;
    }
    private void dfs(StringBuilder str, int left, int right) {
        if (left == 0 && right == 0) {
            result.add(str.toString());
            //return;
        } else {
            if (left < right) {
                if (left > 0) {
                    dfs(str.append("("), left - 1, right);
                    str.deleteCharAt(str.length() - 1);
                    //因为java是默认引用，所以递归出来的时候应该去掉最后一个字符
                }
                if (right > 0) {
                    dfs(str.append(")"), left, right - 1);
                    str.deleteCharAt(str.length() - 1);
                }

            } else {
                dfs(str.append("("), left - 1, right);
                str.deleteCharAt(str.length() - 1);
            }
        }
    }
    //　非递归的太难了，不会写
    private List<String> iterative(int n) {
        List<String>[] temp = new ArrayList[n + 1];
        temp[0] = new ArrayList<> ();
        temp[0].add("");

        for (int i = 1; i <= n; i++){
            temp[i] = new ArrayList<> ();
            for(int j = 0; j < i; j++){
                for (String t1 : temp[j])
                    for(String t2 : temp[i - 1 - j])
                        temp[i].add( "(" + t1 + ")" + t2 );
            }
        }

        return temp[n];
    }
}
