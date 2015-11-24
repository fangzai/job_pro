/**
 * Created by hduser on 15-11-20.
 * Write a function that takes an unsigned integer
 * and returns the number of ’1' bits it has (also known as the Hamming weight).
 * For example, the 32-bit integer ’11' has binary
 * representation 00000000000000000000000000001011,
 * so the function should return 3.
 */
public class NumberofBits {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        return helper(n);
    }
    private int helper(int n){
        long num = n&0x0ffffffffL; //unsigned用int存不了，就转换成long
        int count = 0;
        for(int i = 0; i < 32; ++i){
            if((num &0x01) == 1) count++;
            num = num >> 1;
        }
        return count;
    }
}
