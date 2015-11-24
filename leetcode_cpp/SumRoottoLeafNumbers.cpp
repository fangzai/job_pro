/*
time   :  2015-5-14
author :  ht
comment:  遍历从root到叶子的节点
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
int traverse(struct TreeNode*current,int tempSum)
{
	tempSum *= 10;
	tempSum += current->val;

	int value1, value2;
	if (current->left == NULL&&current->right ==NULL)
	{
		return tempSum;
		// 到达了叶子节点
	}
	{
		if (current->right == NULL)
		{
			value1 = traverse(current->left, tempSum);
			return value1;
		}
		else
		{
			if (current->left == NULL)
			{
				value2 = traverse(current->right, tempSum);
				return value2;
			}
			else
			{
				value1 = traverse(current->left, tempSum);
				value2 = traverse(current->right, tempSum);
				int value = value1 + value2;
				return value;
			}
		}

	}
}

int sumNumbers(struct TreeNode* root) {
	int sum = 0;
	if (root == NULL)
		return 0;
	sum = traverse(root,sum);
	printf("%d \n",sum);
	return sum;
}

int main()
{
	int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 2, 5, -1, -1, 2, -1, -1 };
	//  int value[100] = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};  //size =15 满二叉树
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 6;
	root = Node(root, &index, value, nums);
	sumNumbers(root);
	return 0;
}