/**
 * Created by hduser on 15-11-25.
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding
 * up all the values along the path equals the given sum.
 * For example:
 * Given the below binary tree and sum = 22,
       5
      / \
     4   8
    /   / \
   11  13  4
  /  \    /  \
 7    2   5   1
 return的结果就是这样
 [
 [5,4,11,2],
 [5,8,4,5]
 ]
 */
import ht.TreeNode;
import ht.TreeNodeComparator;
import java.util.*;

public class PathSumII {
    private List<List<Integer>> result = new ArrayList<List<Integer>>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        return helper(root, sum);
    }
    private List<List<Integer>> helper(TreeNode root, int sum) {
        //ArrayList<Integer> path = new ArrayList<Integer>();
        //int val = 0;
        //if (root != null) {
        //    dfs(root, path, val, sum);
        //}
        //return this.result;
        return bfs(root, sum);
    }
    private List<List<Integer>> bfs(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (root == null) {
            return res;
        }
        //TreeNodeComparator nodeComparator = new TreeNodeComparator();
        //上面一句是把ht包里面的import进来了之后直接使用的，也就是下面的内容
        Comparator nodeComparator = new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
                return o1.toString().compareTo(o2.toString());
            }
        };

        Map<TreeNode, TreeNode> prePath = new TreeMap<TreeNode, TreeNode>(nodeComparator);
        //　建立一个反向映射
        LinkedList<TreeNode> treeQueue = new LinkedList<TreeNode>();
        LinkedList<Integer> dataSum = new LinkedList<Integer>();
        List<TreeNode> mid = new ArrayList<TreeNode>();

        treeQueue.add(root); //最好都用add，push是压栈的方法
        dataSum.push(root.val);
        int count = 1;
        int depth = 0;
        TreeNode current = null;
        Integer tmpSum = 0;
        while (!treeQueue.isEmpty()) {
            current = treeQueue.peek();
            treeQueue.pop();
            count--;
            tmpSum = dataSum.peek();
            dataSum.pop();
            if (null == current.right && current.left == null && tmpSum == sum) {
                mid.add(current); //记录中间结果，等后面再重建路径
            }
            if (current.left != null) {
                treeQueue.add(current.left);
                dataSum.add(tmpSum + current.left.val);
                prePath.put(current.left, current); // 反向映射
            }
            if(current.right != null) {
                treeQueue.add(current.right);
                dataSum.add(tmpSum + current.right.val);
                prePath.put(current.right, current); //反向映射
            }

            if(count == 0) {
                depth++;
                count = treeQueue.size();
            }
        }
        for (TreeNode each:mid) {
            current = each;
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            while (current != root) {
                tmp.add(current.val);
                current = prePath.get(current);
            }
            tmp.add(root.val);
            Collections.reverse(tmp);
            res.add(tmp);
        }
        /*for (int i = 0; i < mid.size(); ++i) {
            current = mid.get(i);
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            while (current != root) {
                tmp.add(current.val);
                current = prePath.get(current);
            }
            tmp.add(root.val);
            Collections.reverse(tmp);
            res.add(tmp);
        }*/
        return res;
    }
    private void dfs(TreeNode root, ArrayList<Integer>path,int sum, int target) {
        path.add(root.val);

        if (root.left == null && root.right == null) {
            if (sum + root.val == target) {
                ArrayList<Integer> tmp = new ArrayList<Integer>();
                //Collections.copy(tmp, path);
                //tmp.addAll(path); //这句话和下面等效
                tmp = (ArrayList<Integer>)path.clone();
                this.result.add(tmp);
            }
        } else {
            if (root.left != null) {
                dfs(root.left, path, sum + root.val, target);
            }
            if (root.right != null) {
                dfs(root.right, path, sum + root.val, target);
            }
        }
        path.remove(path.size() - 1); //pop出来
        return;
    }
}
