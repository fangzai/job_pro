/*
time   :  2015-5-14
author :  ht
comment:  让二叉树level等级一样的连成链表
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;


//Definition for a binary tree node.
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
};
struct TreeLinkNode* Node(struct TreeLinkNode* current, int *index, int*value, int nums)
{
	//这个函数用来创建树 创建方式是先序遍历
	current = (struct TreeLinkNode*)malloc(sizeof(struct TreeLinkNode));
	current->next = NULL;
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
void traverse(struct TreeLinkNode*current, struct TreeLinkNode* nodeLeft)
{
	//这里是满二叉树
	if (current->left->left == NULL&&current->left->right == NULL)
	{
		// 到达了叶子节点
		current->left->next = current->right;
	}
	else
	{

		traverse(current->left,nodeLeft);
		current->left->next = current->right;
		traverse(current->right, nodeLeft);
		struct TreeLinkNode*pLeft = NULL, *pRight = NULL;
		
		pLeft = current->left;
		pRight = current->right;
		while (pLeft->right != NULL)  //左右子树链接
		{
			pLeft->right->next = pRight->left;
			
			pLeft = pLeft->right;
			pRight = pRight->left;
		}
		
	}
}

void connect(struct TreeLinkNode *root) {
	int sum = 0;
	if (root == NULL||root->left==NULL)
		return ;
	traverse(root,root);
	//printf("%d \n", sum);
}

int main()
{
	//int value[6] = { 1, -1, 2, 3, -1, 2 };
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 2, 5, -1, -1, 2, -1, -1 };
	//int value[100] = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};  //size =15 满二叉树
	int value[100] = { 1, 2, 4,8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1,3,6,12,-1,-1,13,-1,-1,7,14,-1,-1,15,-1,-1 };  //size =15 满二叉树
	struct TreeLinkNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 31;
	root = Node(root, &index, value, nums);
	connect(root);
	return 0;
}