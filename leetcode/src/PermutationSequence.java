import java.util.ArrayList;

/**
 * Created by hduser on 15-12-1.
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 *
 */
public class PermutationSequence {
    private ArrayList<String> result = new ArrayList<String>();
    public String getPermutation(int n, int k) {
        return helper(n, k);
    }
    public void display() {
        for (String each : result) {
            System.out.println(each);
        }
    }
    private String helper(int n, int k) {
        int len = 1;
        for (int i = 0; i < n; ++i) {
            len *= i +1;
        }
        if (k > len) {
            return "";
        }
        StringBuilder ls = new StringBuilder();
        for (int i = 1; i <= n; ++i) {
            ls.append(i + "");
        }
        //recursive(ls, 0, ls.length() - 1);
        //return this.result.get(k - 1);
        //return  this.iterative(ls, k);
        return iterativeLehmer(ls, n, k);
    }
    private void recursive(StringBuilder ls, int m, int k) {
        if (m == k) {
            this.result.add(ls.toString());
        } else {
            for (int i = m; i <= k; ++i) {
                char tmp = ls.charAt(i);
                ls.setCharAt(i, ls.charAt(m));
                ls.setCharAt(m, tmp);

                recursive(ls, m + 1, k);

                tmp = ls.charAt(i);
                ls.setCharAt(i, ls.charAt(m));
                ls.setCharAt(m, tmp);
            }
        }
    }
    private String iterative(StringBuilder ls, int k) {
        String str = ls.toString();
        for (int i = 0; i < k - 1; ++i) {
            str = generateNext(str);
        }
        return str;
    }
    private String generateNext(String str) {
        StringBuilder ls = new StringBuilder(str);
        int j = ls.length() - 1;
        while (((j - 1) >= 0) && (ls.charAt(j - 1) > ls.charAt(j))) {
            j--; //找第一个违反规则的index
        }
        int start = j - 1;
        j = ls.length() - 1;
        while (ls.charAt(j) <= ls.charAt(start)) {
            j--;
        }
        int end = j;
        char tmp = ls.charAt(start);
        ls.setCharAt(start, ls.charAt(end));
        ls.setCharAt(end, tmp);

        String pre = ls.substring(0, start + 1);
        StringBuilder post = new StringBuilder(ls.substring(start + 1));
        post.reverse();
        pre += post.toString();
        return pre;
    }
    private String iterativeLehmer(StringBuilder ls, int n, int k) {
        ArrayList<Integer> factor = new ArrayList<Integer>();
        factor.add(1);
        int last = 1;
        for (int i = 1; i < n; ++i) {
            factor.add(factor.get(i - 1) * i);
        }
        k--; //从０开始
        String s;
        StringBuilder res = new StringBuilder();
        for (int i = n-1; i >= 0; --i) {
            int code = k / factor.get(i);
            k %= factor.get(i);
            res.append(ls.charAt(code));
            ls.deleteCharAt(code);
        }
        return res.toString();
    }
}
