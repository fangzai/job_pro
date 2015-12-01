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
    ArrayList<String> result = new ArrayList<String>();
    public String getPermutation(int n, int k) {
        return helper(n, k);
    }
    private String helper(int n, int k) {
        int len = 1;
        for (int i = 0; i < n; ++i) {
            len *= i +1;
        }
        if (k > len) {
            return "";
        }
        String ls = new String();
        for (int i = 1; i <= n; ++i) {
            ls += i;
        }
        return recursive(ls, n, k);
    }
    private void swap(char a, char b) {
        char tmp = b;
        b = a;
        a = tmp;
    }
    private String recursive(String ls, int m, int k) {
        if (m == k) {
            this.result.add(ls);
        } else {
            for (int i = m; i <= k; ++i) {
                swap(ls.charAt(m), ls.charAt(i));
            }

        }
        return "";
    }
}
