/*
time   :  2015-5-14
author :  ht
comment:  将已经排过序列的数组构造为平衡二叉搜索树
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {  
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeNode* Node(struct TreeNode* current, int*array, int nums)
{
	//这个函数用来创建树 创建方式是先序遍历
	current = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
	int midIndex = nums / 2;

	if (nums<= 2)
	{
		if (nums == 1)
		{
			current->val = array[0];
			current->left = NULL;
			current->right = NULL;
		}
		else
		{
			current->val = array[1];
			current->left = Node(current->left, array, 1);
			//只剩下一个了
			current->right = NULL;
		}

	}
	else
	{
		current->val = array[midIndex];
		int len1 = midIndex;
		current->left = Node(current->left, array, midIndex);
		//left这边的是从array中 0开始到midIndex-1
		int start = 1 + midIndex;
		int len2 = nums - start;
		current->right = Node(current->right, array +start ,len2 );
	}

	return current;

}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	struct TreeNode* root = NULL;
	if (numsSize <= 0)
		return NULL;
	root = Node(root, nums, numsSize);
	return root;
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	int value[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 2, 5, -1, -1, 2, -1, -1 };
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 13;
	for (int i = 0; i < nums; i++)
		value[i] -= 1;
	//root = Node(root, value, nums);
	root = sortedArrayToBST(value,nums);
	return 0;
}