/*
time   :  2015-5-10
author :  ht
comment:  分层遍历树，好吧！这个程序的性能又落到c++的区域里面去了
		  从下往上
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
int traverse(struct TreeNode** current, int nums, int**result, int** columnSizes)
{
	int level = 0;
	struct TreeNode** output=NULL;
	//这个函数是用来递归当前的节点
	int i = 0;
	int len = 0;
	for (i = 0; i < nums; i++)
	{
		if (current[i]->left != NULL)
		{
			len++;
		}
		if (current[i]->right != NULL)
		{
			len++;
		}
	}
	if (len>0)
	{
		int index = 0;

		output = (struct TreeNode**)malloc(len*sizeof(struct TreeNode*));
		for (i = 0; i < len; i++)
			output[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		//output空间分配，别搞错了

		for (i = 0; i < nums; i++)
		{
			if (current[i]->left != NULL)
			{
				output[index] = current[i]->left;
				index++;
			}
			if (current[i]->right != NULL)
			{
				output[index] = current[i]->right;
				index++;
			}
		}
		//output赋值

		//当前层数（倒数）
		level = traverse(output, len, result, columnSizes) + 1;
		columnSizes[0][level] = nums;
		
		
		result[level] = (int*)malloc(nums*sizeof(int));
		for (i = 0; i < nums; i++)
		{
			//存数据
			result[level][i] = current[i]->val;
		}
		
		for (i = 0; i < len; i++)
		{
			free(output[i]);
		}
		free(output);
		output = NULL;
		
		return level;
	}
	else
	{
		level = 0;
		columnSizes[0][level] = nums;

		result[level] = (int*)malloc(nums*sizeof(int));
		for (i = 0; i < nums; i++)
		{
			//存数据
			result[level][i] = current[i]->val;
		}
		return level;
	}
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	if (root == NULL)
		return NULL;
	//struct TreeNode *output[4000];  //设置最大宽度为4000
	int height = 1000;
	int nums = 1;
	int width = 4000;
	int i;
	columnSizes[0] = (int*)malloc(height*sizeof(int));  // 分配columnSize 设置为height
	int **result = (int**)malloc(height* sizeof(int*)); // 设置为height

	int index = 0;

	int level = traverse(&root,nums,result, columnSizes);

	result[level] = (int*)malloc(nums*sizeof(int));
	result[level][0] = root->val;
	level++;
	returnSize[0] = level;
	//printf("level is %d	\n",level);
	return result;
}

int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	int value[13] = { 1, 2,-1,-1, 4, 5, 3, -1,-1,8,-1,-1,-1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 1;
	root = Node(root, &index, value, nums);
	int* columnSizes;
	int returnSize;
	int** result = levelOrder(root, &columnSizes, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < columnSizes[i]; j++)
		{
			printf("%d", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}