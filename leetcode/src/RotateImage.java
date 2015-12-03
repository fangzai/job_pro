/**
 * Created by hduser on 15-12-3.
 * You are given an n x n 2D matrix representing an image.

 Rotate the image by 90 degrees (clockwise).

 Follow up:
 Could you do this in-place?
 *
 */
public class RotateImage {
    public void rotate(int[][] matrix) {
        helper(matrix);
        return;
    }
    private void helper(int[][] matrix) {
        //　最笨的办法就是一圈一圈模拟
        //　比较巧妙的方法，先上下对折，接着对角线对折
        int n = matrix.length, tmp;
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = tmp;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        return;
    }
}
