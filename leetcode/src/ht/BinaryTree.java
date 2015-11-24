package ht;

/**
 * Created by hduser on 15-11-23.
 */
public class BinaryTree {
    public TreeNode root = null;
    public TreeNode createBinaryTree(int[] nums) {
        //用先序遍历的方式创建二叉树，遇到-1则表示该节点为null
        int[] index = new int[1];
        index[0] = 0;
        int len = nums.length;
        root = helpTree(index, nums, len);
        return this.root;
    }
    public TreeNode createBinaryTree(int[] nums, int len) {
        if (nums.length < len) {
            return null;
        }
        //用先序遍历的方式创建二叉树，遇到-1则表示该节点为null
        int[] index = new int[1];
        index[0] = 0;
        root = helpTree(index, nums, len);
        return this.root;
    }
    private TreeNode helpTree(int[] index, int[] data, int len) {
        /*
        * current 表示当前节点，需要分配空间，也就是
        * 因为java里面不能传引用，所以这里就需要传一个数组了
        * data表示创建的tree的数组
        * len表示数组的长度
        * */
        TreeNode current = null;
        if (data[index[0]] != -1) {
            current = new TreeNode(data[index[0]]);
            index[0]++;
            if(index[0] < len) {
                current.left = helpTree(index, data, len);
            }
            if(index[0] <len) {
                current.right = helpTree(index, data, len);
            }

        } else {
            //current = null;
            index[0]++;
        }
        return current;
    }
}
