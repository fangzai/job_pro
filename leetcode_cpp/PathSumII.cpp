/*
time   :  2015-5-19
author :  ht
comment:  深度遍历一棵树，看是否root->leaf的路径和等于指定的sum
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

TreeNode* Node(TreeNode* current, int *index, int*value, int nums)
{
	//这个函数用来创建树 创建方式是先序遍历
	if (nums <= 0)
		return NULL;
	current = (TreeNode*)malloc(sizeof(TreeNode));
	if (value[index[0]] != -1)
	{

		current->val = value[index[0]];
		current->left = NULL;
		index[0]++;
		if (index[0] < nums)
		{
			current->left = Node(current->left, index, value, nums);
		}
		current->right = NULL;
		if (index[0] < nums)
		{
			current->right = Node(current->right, index, value, nums);
		}
	}
	else
	{
		current = NULL;
		index[0]++;
	}
	return current;
}

int traverse(struct TreeNode* current, int** result, int *returnSize, int** columnSizes, int*trace, int sum, int depth, int target)
{
	//　result用于存储最后的输出结果  returnSize记录result的维数

	//　trace 是记录当前key值， depth表示当前深度，维护trace的下标
	// sum是指定的路径和
	if ((current->left == NULL) && (current->right == NULL))
	{
		trace[depth] = current->val;
		sum += current->val;
		if (sum == target)
		{
			// 找到路径了
			columnSizes[0][returnSize[0]] = depth + 1;
			result[returnSize[0]] = (int*)malloc((depth + 1)*sizeof(int));
			memcpy(result[returnSize[0]], trace, (depth + 1)*sizeof(int));
			returnSize[0]++;
		}
		return depth;
	}
	else
	{
		int left = 0, right = 0;
		trace[depth] = current->val;
		sum += current->val;
		if (current->left != NULL)
		{
			left = traverse(current->left, result, returnSize, columnSizes, trace, sum, depth + 1, target);
		}

		if (current->right != NULL)
		{
			right = traverse(current->right, result, returnSize, columnSizes, trace, sum, depth + 1, target);
		}

		return left>right ? left : right;  //其实返回值没有多大用
	}
}
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {

	if (root == NULL)
		return NULL;
	int maxHeight = 10000;  //最大高度设大一点儿，不然oj不让过
	int *trace = NULL;
	trace = (int*)malloc(maxHeight*sizeof(int));

	//columnSizes = (int**)malloc(1*sizeof(int*));  //只分配一个文件就够了
	columnSizes[0] = (int*)malloc(maxHeight*sizeof(int));


	int maxTimes = 10000;  //出现的次数开始的时候也开大一点儿
	int **result = (int**)malloc(maxTimes * sizeof(int*));  // sum == target 假设最多等于100次
	returnSize[0] = 0;
	
	int depth = 0;

	int target = sum;
	traverse(root, result, returnSize, columnSizes, trace, 0, depth, target);
	return result;
}

int main()
{
	int value[6] = { 1, -1, 2, 3, -1, 2 };
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 4, -1, -1 };
	//这是一颗满树
	//int value[7] = { 1,2,4,-1,-1,-1,3};
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 6;
	root = Node(root, &index, value, nums);

	int returnSize = 0;
	int sum = 8;
	int* columnSizes[1];
	int **result = pathSum(root, sum, columnSizes, &returnSize);
	
	for (int i = 0; i<returnSize; i++)
	{
		for (int j = 0; j < columnSizes[0][i]; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
		
	}
	//printf("\n");
	return 0;
}