/*
time   :  2015-5-10
author :  ht
comment:  求root到叶子节点路径和是否等于给定的值
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
/*
*这一题和求树的高度不一样，因为要确定叶子节点
*其次，如果只有一个root的话，那么它到leaf的距离是 1 我去！！什么破规定啊！
*遍历的时候分四种情况
* 1 节点是叶子
* 2 右节点为空，左节点不空
* 3 左节点为空，右节点不空
* 4 左右节点有数据和孩子
*/
bool traverse(struct TreeNode* current,int currentValue,int sum)
{
	int total = 0;
	total = current->val + currentValue;
	if ((current->left == NULL) && (current->right == NULL))
	{
		if (total == sum)
			return true;
		return false;
		//一定要确定叶子
	}
	else
	{
		if (current->left == NULL)
		{
			return traverse(current->right, total, sum);
		}
		if (current->right == NULL)
		{
			return traverse(current->left, total, sum);
		}
		bool left = traverse(current->left, total, sum);
		bool right = traverse(current->right, total, sum);
		
		return left||right;

	}
}
bool hasPathSum(struct TreeNode* root, int sum) {
	
	if (root == NULL)
	{ 
		return false;
	}
	int value = 0;
	//int value = root->val;
	
	bool mark = traverse(root, value, sum);
	return mark;
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 0;
	root = Node(root, &index, value, nums);
	int sum = 0;

	if (hasPathSum(root, sum))
	{
		printf("in sum......");
	}
	else
	{
		printf("Not in sum......");
	}
	return 0;
}