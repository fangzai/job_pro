/**
 * Created by hduser on 15-11-19.
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 */
public class CountPrimes {
    public int countPrimes(int n) {
        return helper(n);
    }
    private int helper(int n) {
        if(n < 2) return 0;
        if(n == 2) return 1;
        boolean []mark = new boolean[n];
        mark[1] = false; //不是质数
        mark[2] = true;  //是质数
        for(int i = 2; i < n; ++i) mark[i] = true;
        int count = 0;
        for(int i = 2; i < n; ++i) {
            if(mark[i]) {
                count++;
                //System.out.print(i + "\t");
                for(int j = i+i; j <n; j+=i){
                    mark[j] = false;
                }//这个语句放在里面更加省时间
            }
        }
        return count;
    }
}
