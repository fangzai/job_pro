/*
time   :  2015-5-16
author :  ht
comment:  将一棵二叉树变为只有右子树的树，类似一条链表
//题目说了，需要原址重排，不能改变root的地址，改了也没用
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

int traverse(struct TreeNode* current, int *index, int* result, int depth)
{
	if ((current->left == NULL) && (current->right == NULL))
	{

		return 0;
	}
	else
	{
		struct TreeNode* left = NULL, *right = NULL,*p=NULL;
		if (current->left != NULL)
		{
			left = current->left;
			traverse(current->left, index, result, depth + 1);
			if (current->right != NULL)
			{
				current->left = NULL;
				
				right = current->right;
				
				current->right = left;
				
				p = left;
				//关键点在这个循环上，因为当左子树添加到右子树上的时候
				//必须找到左子树的最右节点，然后最右节点链接到以前的右子树上
				while (p->right != NULL)
					p = p->right;


				p->right = right;
				traverse(right, index, result, depth + 1);
				return 1;
			}
			//右边是空的直接把左边的接上去就行了
			current->left = NULL;
			current->right = left;
			return 2;
			
		}
		else
		{
			//左子树是空，什么也不用做，直接遍历右子树即可
			traverse(current->right, index, result, depth + 1);
			return 3;  //其实返回值没有多大用
		}
		
	}
}
void flatten(struct TreeNode* root) {
	if (root == NULL)
		return;
	int index = 0;
	int size = 10000;
	int *result = (int*)malloc(size*sizeof(int));
	int depth = traverse(root, &index, result, 0);
}

int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
	//这是一颗满树
	int value[7] = { 1,2,4,-1,-1,-1,3};
	//int value[6] = { 1, 2, -1, -1, -1 };
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 7;
	root = Node(root, &index, value, nums);

	int returnSize = 0;
	flatten(root);
	return 0;
}