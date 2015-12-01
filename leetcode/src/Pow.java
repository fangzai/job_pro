/**
 * Created by hduser on 15-12-1.
 */
public class Pow {
    public double myPow(double x, int n) {
        return helper(x, n);
    }
    private double helper(double x, int n) {
        //return linear(x, n);
        return binary(x, n);
    }
    private double linear(double x, int n) {
        boolean flag = false;
        if (n < 0) {
            flag = true;
        }
        double num = 1;
        for (int i = 0; i < n; ++i) {
            num *= x;
        }
        if (flag) {
            num = 1 / num;
        }
        return num;
    }
    private double binary(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        if (n < 0) {
            if (n == Integer.MIN_VALUE) {
                return 1 / (binary(x, Integer.MAX_VALUE) * x);
            } else {
                return 1.0/ binary(x, -n);
            }
        } else {
            double half = binary(x, n>>1);
            if (n % 2 == 1) {
                return half * half * x;
            } else {
                return half * half;
            }

        }
    }
}
