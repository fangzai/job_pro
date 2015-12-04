import java.util.ArrayList;
import java.util.List;

/**
 * Created by hduser on 15-12-4.
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * For example,
 Given n = 3,
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 */
public class SpiralMatrixII {
    public int[][] generateMatrix(int n) {
        return helper(n);
    }
    private int[][] helper(int num) {
        int[][] matrix = new int[num][num];
        if (num == 0) {
            return matrix;
        }
        int[] nx = {0, 1, 0, -1};
        int[] ny = {1, 0, -1, 0};
        int x = 0, y = -1; //　因为是从(0, 0) 开始的
        int m = matrix.length, n = matrix[0].length;
        int i = 0, k = 0, index = 1;
        while (m > 0 && n > 0) {
            if (i % 2 == 0) {
                k = n;  //　走的行
                m--;    //　少了一行
            } else {
                k = m;  // 走的列
                n--;    // 少了一列
            }
            while (k > 0) {
                x += nx[i];
                y += ny[i];
                matrix[x][y] = index;
                index++;
                k--;
            }
            i++;
            i %= 4;
        }
        return matrix;
    }
}
