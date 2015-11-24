/*
time   :  2015-5-19
author :  ht
comment:  分层遍历树，不过在偶数层的时候需要逆序
          这个程序的性能又落到c++的区域里面去了
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
int traverse(struct TreeNode** current, int nums, struct TreeNode** output)
{
	//这个函数是用来获取下一层不是NULL的节点
	//并返回下层非NULL的个数
	int i = 0;
	int len = 0;
	for (i = 0; i < nums; i++)
	{
		if (current[i]->left != NULL)
		{
			output[len] = current[i]->left;
			len++;
		}
		if (current[i]->right != NULL)
		{
			output[len] = current[i]->right;
			len++;
		}
	}
	return len;
}

int reverse(int *nums, int numSize)
{
	int*temp = (int*)malloc(numSize*sizeof(int));
	int i = 0, j = numSize - 1;
	while (i < numSize)
	{
		temp[i] = nums[j];
		i++;
		j--;
	}
	memcpy(nums, temp, numSize*sizeof(int));
	free(temp);
	temp = NULL;
	return 0;

}
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize){
	if (root == NULL)
		return NULL;
	struct TreeNode* input[4000], *output[4000];
	int height = 1000;
	int nums = 1;
	int width = 4000;
	int i;
	columnSizes[0] = (int*)malloc(height*sizeof(int));
	int **result = (int**)malloc(height* sizeof(int*));

	for (i = 0; i < width; i++)
	{
		input[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		output[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	}
	int len = 0;

	result[len] = (int*)malloc(nums*sizeof(int));
	result[len][0] = root->val;  //这是root层
	columnSizes[0][0] = nums;

	nums = traverse(&root, nums, output);
	memcpy(input, output, nums*sizeof(struct TreeNode*));
	//获取到下层之后，复制到input里面去
	len++;
	result[len] = (int*)malloc(nums*sizeof(int));
	while (nums >= 1)
	{

		for (i = 0; i < nums; i++)
		{
			result[len][i] = output[i]->val;//复制到result里面去
		}
		columnSizes[0][len] = nums;

		len++;
		nums = traverse(input, nums, output);
		result[len] = (int*)malloc(nums*sizeof(int));//动态分配空间
		memcpy(input, output, nums*sizeof(struct TreeNode*));
		//获取到下层之后，复制到input里面去
	}
	returnSize[0] = len;
	for (i = 0; i < len; i ++)
	{
		if (i % 2 == 0)
		{
			//left ->right
		}
		else
		{
			//right->left
			reverse(result[i], columnSizes[0][i]);
		}
	}

	return result;
}

int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2,-1,-1, 4, 5, 3, -1,-1,8,-1,-1,-1 };
	int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 15;
	root = Node(root, &index, value, nums);
	int* columnSizes;
	int returnSize;
	int** result = zigzagLevelOrder(root, &columnSizes, &returnSize);
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