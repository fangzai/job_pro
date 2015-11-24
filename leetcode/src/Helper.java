/**
 * Created by hduser on 15-11-18.
 */
import java.util.ArrayList;
import java.util.List;

import ht.ListLink;
import ht.ListNode;
import ht.TreeNode;
import ht.BinaryTree;
public class Helper {
    public static void main(String args[]){
        //System.out.println("Hello world!");
        Helper helper = new Helper();
        //helper.testSingleNumber();
        //helper.testValidParentheses();
        //helper.testCountAndSay();
        //helper.testReverseBit();
        //helper.testCountPrimes();
        //helper.testExcelSheetColumnNumber();
        //helper.testExcelSheetColumnTitle();
        //helper.testCompareVersionNumbers();
        //helper.testImplementStr();
        //helper.testHappyNumber();
        //helper.testNumberofBits();
        //helper.testReverseInteger();
        //helper.testRotateArray();
        //helper.testFactorialTrailingZeroes();
        //helper.testMajorityElement();
        //helper.testValidPalindrome();
        //helper.testIsomorphicStrings();
        //helper.testRemoveElement();
        //helper.testLengthofLastWord();
        //helper.testPlusOne();
        //helper.testAddBinary();
        //helper.testMergeSortedArray();
        //helper.testRemoveDuplicatesfromSortedArray();
        //helper.testClimbingStairs();
        //helper.testPalindromeNumber();
        //helper.testRemoveLinkedListElements();
        //helper.testReverseLinkedList();
        //helper.testRemoveDuplicatesfromSortedList();
        //helper.testRemoveDuplicatesfromSortedListII();
        //helper.testRemoveDuplicatesfromSortedArrayII();
        //helper.testSameTree();
        //helper.testRemoveNthNodeFromEndofList();
        //helper.testMergeTwoSortedLists();
        //helper.testPascalsTriangle();
        //helper.testPascalsTriangleII();
        //helper.testStringtoInteger();
        //helper.testIntersectionofTwoLinkedLists();
        //helper.testValidSudoku();
        //helper.testMinStack();
        //helper.testHouseRobber();
        //helper.testLongestCommonPrefix();
        //helper.testMaximumDepthofBinaryTree();
        //helper.testMinimumDepthofBinaryTree();
        //helper.testBinaryTreeLevelOrderTraversal();
        helper.testBinaryTreeLevelOrderTraversalII();
    }
    public void testBinaryTreeLevelOrderTraversalII() {
        BinaryTreeLevelOrderTraversalII usage = new BinaryTreeLevelOrderTraversalII();
        int[] nums = {1 ,2 , 3, -1, -1, 4, -1, -1, 5};
        BinaryTree myTree = new BinaryTree();
        TreeNode tree = myTree.createBinaryTree(nums);
        System.out.println(usage.levelOrderBottom(null));
    }
    public void testBinaryTreeLevelOrderTraversal() {
        BinaryTreeLevelOrderTraversal usage = new BinaryTreeLevelOrderTraversal();
        int[] nums = {1 ,2 , 3, -1, -1, 4, -1, -1, 5};
        BinaryTree myTree = new BinaryTree();
        TreeNode tree = myTree.createBinaryTree(nums);
        System.out.println(usage.levelOrder(tree));
    }
    public void testMinimumDepthofBinaryTree() {
        MinimumDepthofBinaryTree usage = new MinimumDepthofBinaryTree();
        int[] nums = {1 ,2 , 3, -1, -1, 4, -1, -1, 5};
        BinaryTree myTree = new BinaryTree();
        TreeNode tree = myTree.createBinaryTree(nums);
        System.out.println(usage.minDepth(tree));
    }
    public void testMaximumDepthofBinaryTree() {
        MaximumDepthofBinaryTree usage = new MaximumDepthofBinaryTree();
        int[] nums = {1 ,2 , 3, -1, -1, 4, -1, -1, -1};
        //int[] nums = {1 ,2 , 3, -1, -1, 4, -1, -1, 5, -1, -1};
        BinaryTree myTree = new BinaryTree();
        TreeNode tree = myTree.createBinaryTree(nums);
        System.out.println(usage.maxDepth(null));

    }
    public void testLongestCommonPrefix() {
        String[] strs = {"aca", "cba"};
        LongestCommonPrefix usage = new LongestCommonPrefix();
        System.out.println(usage.longestCommonPrefix(strs));
    }
    public void testHouseRobber() {
        HouseRobber usage = new HouseRobber();
        int[] nums = {1, 4, 2, 5};
        System.out.println(usage.rob(nums));
    }
    public void testMinStack() {
        MinStack usage = new MinStack();
        usage.push(1);
        usage.push(2);
        usage.push(3);
        System.out.println(usage.top());
        System.out.println(usage.dataStack);
        System.out.println(usage.minimum);
        usage.pop();
        usage.pop();
        System.out.println(usage.dataStack);
        System.out.println(usage.minimum);
        usage.pop();
        usage.pop();
        System.out.println(usage.dataStack);
        System.out.println(usage.minimum);

    }
    public void testValidSudoku() {
        List<String> src = new ArrayList<String>();
        src.add("53..7....");
        src.add("6..195...");
        src.add(".98....6.");
        src.add("8...6...3");
        src.add("4..8.3..1");
        src.add("7...2...6");
        src.add(".6....28.");
        src.add("...419..5");
        src.add("....8..79");
        int num = 9;
        char[][] board = new char[num][num];
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board.length; ++j) {
                board[i][j] = src.get(i).charAt(j);
            }
        }
        ValidSudoku usage = new ValidSudoku();
        if (usage.isValidSudoku(board)) {
            System.out.println("This board is valid!");
        } else {
            System.out.println("This board is invalid!");
        }
    }
    public void testIntersectionofTwoLinkedLists() {
        int[] nums1 = {1, 2, 3, 4, 5, 6};
        int[] nums2 = {11, 12};
        ListLink myLink = new ListLink();
        ListNode headB = myLink.createListLink(nums2);
        ListNode tailB = myLink.tail;
        myLink.display();

        ListNode headA = myLink.createListLink(nums1);
        myLink.display();
        myLink.insertMap(4, tailB);
        myLink.display(headB);
        IntersectionofTwoLinkedLists usage = new IntersectionofTwoLinkedLists();
        System.out.println(usage.getIntersectionNode(headA, headB).val);

    }
    public void testStringtoInteger() {
        //String str = new String(" -123");
        String str = new String(Integer.MIN_VALUE + "");
        StringtoInteger usage = new StringtoInteger();
        System.out.println(usage.myAtoi(str));
    }
    public void testPascalsTriangleII() {
        int num = 5;
        PascalsTriangleII usage = new PascalsTriangleII();
        List<Integer> res = usage.getRow(num);
        System.out.println(res);
    }
    public void testPascalsTriangle() {
        int num = 2;
        PascalsTriangle usage = new PascalsTriangle();
        List<List<Integer>> res = usage.generate(num);
        System.out.println(res);
    }
    public void testMergeTwoSortedLists() {
        MergeTwoSortedLists usage = new MergeTwoSortedLists();
        int[] nums1 = {1, 5, 6, 8};
        int[] nums2 = {-2, -1, 8, 10};
        ListLink myLink = new ListLink();
        ListNode head1 = myLink.createListLink(nums1);
        myLink.display();
        ListNode head2 = myLink.createListLink(nums2);
        myLink.display();
        ListNode head = usage.mergeTwoLists(head1, head2);
        myLink.display(head);
    }
    public void testRemoveNthNodeFromEndofList() {
        RemoveNthNodeFromEndofList usage = new RemoveNthNodeFromEndofList();
        int[] nums = {1, 2, 3, 4, 5};
        ListLink myLink = new ListLink();
        ListNode head = myLink.createListLink(nums);
        myLink.display();
        int n = 4;
        head = usage.removeNthFromEnd(head, n);
        myLink.display(head);
    }
    public void testSameTree() {
        SameTree usage = new SameTree();
        int[] nums1 = {1 ,2 , 3, -1, -1, 4, -1, -1, -1};
        int[] nums2 = {1 ,2 , 3, -1, -1, 4, -1, -1, -1};
        BinaryTree myTree = new BinaryTree();
        TreeNode tree1 = myTree.createBinaryTree(nums1);
        TreeNode tree2 = myTree.createBinaryTree(nums2);
        if(usage.isSameTree(tree1, tree2)) {
            System.out.println("两棵树是一样的～～～");
        } else {
            System.out.println("两棵树不是一样～～～～");
        }
    }
    public void testRemoveDuplicatesfromSortedArrayII() {
        RemoveDuplicatesfromSortedArrayII usage = new RemoveDuplicatesfromSortedArrayII();
        //int[] nums = {1, 1, 1, 1, 3, 3, 3, 4};
        int[] nums = {-1, 1, 1};
        displayArray(nums);
        int len = usage.removeDuplicates(nums);
        displayArray(nums, len);
    }
    public void testRemoveDuplicatesfromSortedListII() {
        RemoveDuplicatesfromSortedListII usage = new RemoveDuplicatesfromSortedListII();
        //int[] nums = {1, 1, 2, 3, 3};
        int[] nums = {1, 1, 2, 2, 3, 3};
        ListLink myLink = new ListLink();
        ListNode head = myLink.createListLink(nums);
        myLink.display();
        head = usage.deleteDuplicates(head);
        myLink.display(head);
    }
    public void testRemoveDuplicatesfromSortedList() {
        RemoveDuplicatesfromSortedList usage = new RemoveDuplicatesfromSortedList();
        int[] nums = {1, 1, 1};
        ListLink myLink = new ListLink();
        ListNode head = myLink.createListLink(nums);
        myLink.display();
        head = usage.deleteDuplicates(head);
        myLink.display(head);
    }
    public void testReverseLinkedList() {
        ReverseLinkedList usage = new ReverseLinkedList();
        int[] nums = {1, 2, 3, 4, 5, 6};
        ListLink myLink = new ListLink();
        ListNode head = myLink.createListLink(nums);
        myLink.display();
        head = usage.reverseList(head);
        myLink.display(head);
    }
    public void testRemoveLinkedListElements() {
        RemoveLinkedListElements usage = new RemoveLinkedListElements();
        //int[] vals = {1, 2, 2, 1, 3, 1, 2, 3};
        int[] vals = {1, 1, 1};
        ListLink myLink = new ListLink();
        ListNode head = myLink.createListLink(vals);
        int num = 1;
        myLink.display(head);
        ListNode newHead = usage.removeElements(head, num);
        myLink.display(newHead);
    }
    public void testPalindromeNumber() {
        int num = 1000021;
        PalindromeNumber usage = new PalindromeNumber();
        if (usage.isPalindrome(num)) {
            System.out.println(num + " is palindrome number!");
        } else {
            System.out.println(num + " is not palindrome number!");
        }
    }
    public void testClimbingStairs() {
        int n = 3;
        ClimbingStairs usage = new ClimbingStairs();
        int nums = usage.climbStairs(n);
        System.out.println(nums);
    }
    public void testRemoveDuplicatesfromSortedArray() {
        //int[] nums = {1, 1, 1, 2, 3, 3, 3, 4, 4};
        int[] nums = {1, 1, 1};
        RemoveDuplicatesfromSortedArray usage = new RemoveDuplicatesfromSortedArray();
        displayArray(nums);
        int len = usage.removeDuplicates(nums);
        displayArray(nums, len);
    }
    public void testMergeSortedArray() {
        MergeSortedArray usage = new MergeSortedArray();
        int m = 4;
        int n = 2;
        int[] nums1 = new int[m + n];
        int[] nums2 = {1,6};
        nums1[0] = -2;
        nums1[1] = 2;
        nums1[2] = 4;
        nums1[3] =5;
        displayArray(nums1, m);
        displayArray(nums2, n);
        usage.merge(nums1, m, nums2, n);
        displayArray(nums1, m + n);

    }
    public void testAddBinary() {
        AddBinary usage = new AddBinary();
        String s = new String("111");
        String t = new String("1");
        System.out.println(usage.addBinary(s,t));

    }
    public void testPlusOne() {
        int[] digits = {0};
        PlusOne usage = new PlusOne();
        this.displayArray(digits);
        int[] res = usage.plusOne(digits);
        this.displayArray(res);
    }
    public void testLengthofLastWord() {
        LengthofLastWord usage = new LengthofLastWord();
        String s = new String("world!");
        System.out.println(usage.lengthOfLastWord(s));
    }
    public void testRemoveElement() {
        RemoveElement usage = new RemoveElement();
        int[] nums = {1, 5, 6, 1, 1, 8, 9};
        int val = 9;
        for(int i = 0; i < nums.length; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
        int len = usage.removeElement(nums, val);
        for(int i = 0; i < len; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
    public void testIsomorphicStrings() {
        IsomorphicStrings usage = new IsomorphicStrings();
        String s = new String("ab");
        String t = new String("aa");
        if(usage.isIsomorphic(s, t)) {
            System.out.println(s + " and " + t + " are omorphic strings!");
        } else {
            System.out.println(s + " and " + t + " are not omorphic strings!");
        }
    }
    public void testValidPalindrome() {
        //String str = "A man, a plan, a canal: Panama";
        String str = "1b1";
        ValidPalindrome usage = new ValidPalindrome();
        if(usage.isPalindrome(str)) {
            System.out.println(str + " : is valid palindrome!");
        } else {
            System.out.println(str + " : is not valid palindrome!");
        }
    }
    public void testMajorityElement() {
        int [] nums ={1,3,2,1,1,2,1,1,2};
        MajorityElement usage = new MajorityElement();
        int ele = usage.majorityElement(nums);
        System.out.println(ele);
    }
    public void testFactorialTrailingZeroes() {
        int n = 10;
        FactorialTrailingZeroes usage = new FactorialTrailingZeroes();
        System.out.println(usage.trailingZeroes(n));
    }
    public void testRotateArray() {
        int[] nums = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;
        for(int i = 0; i < nums.length; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
        RotateArray usage = new RotateArray();
        usage.rotate(nums, k);
        for(int i = 0; i < nums.length; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
    public void testReverseInteger() {
        int n = -123;
        n = 1000000003;
        ReverseInteger usage = new ReverseInteger();
        System.out.println(usage.reverse(n));
    }
    public void testNumberofBits() {
        int n = 8;
        NumberofBits usage = new NumberofBits();

        System.out.println(usage.hammingWeight(n));
    }
    public void testHappyNumber() {
        int num = 19;
        HappyNumber usage = new HappyNumber();
        if(usage.isHappy(num)) {
            System.out.println(num + " is Happy Number!");
        } else {
            System.out.println(num + " is not Happy Number!");
        }
    }
    public void testImplementStr() {
        String haystack = "hello word";
        String needle = "wo";
        ImplementStr usage = new ImplementStr();
        System.out.println(usage.strStr(haystack, needle));
    }
    public void testCompareVersionNumbers() {
        String version1 = "1.1";
        String version2 = "1.1.2";
        CompareVersionNumbers usage = new CompareVersionNumbers();
        System.out.println(usage.compareVersion(version1, version2));
    }
    public void testExcelSheetColumnTitle() {
        int n = 28;
        ExcelSheetColumnTitle usage = new ExcelSheetColumnTitle();
        System.out.println(usage.convertToTitle(n));
    }
    public void testExcelSheetColumnNumber() {
        String str = "A";
        ExcelSheetColumnNumber usage = new ExcelSheetColumnNumber();
        System.out.println(usage.titleToNumber(str));
    }
    public void testCountPrimes() {
        CountPrimes usage = new CountPrimes();
        int n = 10;
        System.out.println(usage.countPrimes(n));
    }
    public void testReverseBit() {
        int n = -1;
        long nn =  0x7fffffffffffffffL;
        //System.out.println(Integer.toBinaryString(n));
        //System.out.println(n);
        short m = 0x7fff;
        int num = 0x7fffffff;
        //System.out.println(Long.toHexString(nn));
        //System.out.println(nn);
        ReverseBit usage = new ReverseBit();
        System.out.println(usage.reverseBits(n));
    }
    public void testCountAndSay() {
        CountAndSay usage = new CountAndSay();
        int n = 2;
        String res;
        res = usage.countAndSay(n);
        System.out.println(res);
    }
    public void testValidParentheses() {
        //String str = "()[]{}";
        String str = "(]";
        ValidParentheses usage = new ValidParentheses();
        if(usage.isValid(str)) {
            System.out.println(str + " is valid parentheses!");
        } else {
            System.out.println(str + " is not valid parenteses!");
        }
    }
    public void testSingleNumber()  {
        SingleNumber usage = new SingleNumber();
        int [] nums = {1,2,3,1,3};
        int res = usage.singleNumber(nums);
        System.out.println(res);
    }
    private void displayArray(int[] nums) {
        for(int i = 0; i < nums.length; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
    private void displayArray(int[] nums, int m) {
        for(int i = 0; i < m; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
    private void displayArray(double[] nums) {
        for(int i = 0; i < nums.length; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
    private void displayArray(double[] nums, int m) {
        for(int i = 0; i < m; ++i) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();
    }
}
