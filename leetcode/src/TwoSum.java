/**
 * Created by hduser on 15-11-30.
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 */
import java.util.*;

public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        return helper(nums, target);
    }
    private int[] helper(int[] nums, int target) {
        return sortRank(nums, target);
        //return mapRank(nums, target);
    }
    private int[] sortRank(int[] nums, int target) {
        class Node {
            int num;
            int index;
        }
        List<Node> data = new ArrayList<Node>();
        //for(int each:nums) {
        for (int i = 0; i < nums.length; ++i) {
            Node tmp = new Node();
            tmp.num  = nums[i];
            tmp.index = i;
            data.add(tmp);
        }
        Comparator<Node> cmp = new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if (o1.num > o2.num) {
                    return 1;
                } else if (o1.num < o2.num) {
                    return -1;
                } else {
                    return 0;
                }
            }
        };
        Collections.sort(data, cmp); // 先排序
        //System.out.println(data);
        int[] res = new int[2];
        int sum = 0;
        int i,j;
        for (i = 0, j = data.size() - 1; i != j;) {
            sum = data.get(i).num + data.get(j).num;
            if (sum == target) {
                if (data.get(j).index > data.get(i).index) {
                    res[0] = data.get(i).index + 1;
                    res[1] = data.get(j).index + 1;
                } else {
                    res[0] = data.get(j).index + 1;
                    res[1] = data.get(i).index + 1;
                }
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
    private int[] mapRank(int[] nums, int target) {
        HashMap<Integer, Integer> data = new HashMap<Integer, Integer>();
        int reflect = 0;
        int[] res = new int[2];
        Arrays.fill(res, 0);
        for (int i = 0;i < nums.length; ++i) {
            if (!data.containsKey(nums[i])) {
                //　这一句话一定要，否则如果有重复的元素就会被自然覆盖
                data.put(nums[i], i);
            }
            reflect = target - nums[i];
            if (data.containsKey(reflect) && data.get(reflect) < i) {
                res[0] = data.get(reflect) + 1;
                res[1] = i + 1;
                break;
            }

        }
        return res;
    }
}
