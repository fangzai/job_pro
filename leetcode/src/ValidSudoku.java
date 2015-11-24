/**
 * Created by hduser on 15-11-24.
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ValidSudoku {
    public boolean isValidSudoku(char[][] board) {
        return helper(board);
    }
    private boolean helper(char[][] board) {
        int num = 3;
        int N = 9;
        char sep = '.';
        Boolean[] arr = new Boolean[num * num];
        Arrays.fill(arr, false);
        //List<Boolean> ele = Arrays.asList(arr);

        ArrayList<List<Boolean>> row = new ArrayList<List<Boolean>>();
        ArrayList<List<Boolean>> col = new ArrayList<List<Boolean>>();
        ArrayList<List<Boolean>> box = new ArrayList<List<Boolean>>();
        //　用List而不是数组进行操作
        for (int i = 0; i < N; ++i) {
            List<Boolean> ele = Arrays.asList(Arrays.copyOf(arr, N));
            //这里必须复制否则 数据都是指向同一个对象
            row.add(ele);
            List<Boolean> ele1 = Arrays.asList(Arrays.copyOf(arr, N));
            col.add(ele1);
            List<Boolean> ele2 = Arrays.asList(Arrays.copyOf(arr, N));
            box.add(ele2);
        }
        int value = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == sep) {
                    continue;
                }
                if (board[i][j] > '9' || board[i][j] < '1') {
                    return false;
                }
                value = board[i][j] - '1';
                if(row.get(i).get(value) || col.get(j).get(value)
                        ||box.get((i/3)*3 + j/3).get(value)) {
                    return false;
                }
                row.get(i).set(value, true);
                col.get(j).set(value, true);
                box.get((i/3)*3 + j/3).set(value, true);
            }
        }
        return true;
    }
}
