/**
 * Created by hduser on 15-11-19.
 * Reverse bits of a given 32 bits unsigned integer.
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
 * return 964176192 (represented in binary as 00111001011110000010100101000000).
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */
public class ReverseBit {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        long num = n&0X0ffffffffL;
        //System.out.println(num);
        return this.hepler(n);
    }
    private int hepler(long n){
        long res = 0;
        long num = n;
        for(int i = 0; i < 32; ++i){
            res = res << 1;
            res += num % 2;
            num = num >> 1;
        }
        //System.out.println(res);
        return (int)(res);
    }
    public long int2long(int n){
        long num = n&0X0ffffffffL;
        return num;
    }
    public long short2int(short n){
        int num = n&0X0ff;
        return num;
    }
}
