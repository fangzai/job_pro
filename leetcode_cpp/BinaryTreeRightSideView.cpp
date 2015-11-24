/*
time   :  2015-5-16
author :  ht
comment:  输出一棵二叉树每一层的最后一个元素
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

int traverse(struct TreeNode* current, int* result, int depth)
{
	//int  depth = index[0];
	// 这一题目是  Bi​nary Tree Right Side View
	if ((current->left == NULL) && (current->right == NULL))
	{
		result[depth] = current->val;
		return depth;
	}
	else
	{
		int left = 0, right = 0;
		result[depth] = current->val;
		//先遍历左边的，如果右边同一层有元素的话，会覆盖掉左边的赋值的操作
		if (current->left != NULL)
		{
			left = traverse(current->left, result, depth + 1);
		}

		if (current->right != NULL)
		{
			right = traverse(current->right, result, depth + 1);
		}

		return left>right ? left : right;  //其实返回值没有多大用
	}
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
	returnSize[0] = 0;
	if (root == NULL)
		return NULL;
	int size = 1000;
	int *result = (int*)malloc(size*sizeof(int));

	returnSize[0] = traverse(root, result, 0) + 1;

	return result;
}
int main()
{
	int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
	//这是一颗满树
	//int value[7] = { 1,2,4,-1,-1,-1,3};
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 6;
	root = Node(root, &index, value, nums);

	int returnSize = 0;
	int *result = rightSideView(root, &returnSize);
	for (int i = 0; i<returnSize; i++)
	{
		printf("%  d", result[i]);
	}
	printf("\n");
	return 0;
}