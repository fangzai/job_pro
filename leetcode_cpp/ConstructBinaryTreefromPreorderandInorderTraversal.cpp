/*
time   :  2015-5-19
author :  ht
comment:  通过前序遍历和中序遍历重建二叉树
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
struct TreeNode* reConstruct(int* preorder, int *preStart, int preEnd, int* inorder, int inStart, int inEnd)
{
	if (inStart == inEnd)
	{
		struct TreeNode* current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		//只剩下一个了
		current->val = preorder[preStart[0]];
		current->left = NULL;
		current->right = NULL;
		preStart[0]++;
		return current;
	}
	else
	{
		//先序遍历的第一个元素肯定是当前的根节点 查找该节点在中序遍历的位置
		int keyValue = preorder[preStart[0]];
		int i;
		int index = 0;
		for (i = inStart; i <= inEnd; i++)
		{
			if (keyValue == inorder[i])
			{
				index = i;
				break;
			}
		}
		//index左边是左子树的中序遍历，index的右边是右子树的中序列遍历

		struct TreeNode* current = NULL, *left = NULL, *right = NULL;
		current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		current->val = keyValue;
		preStart[0]++;
		//递归左子树
		if ((index - 1) >= inStart)
		{
			//判定左边是否还有值
			left = reConstruct(preorder, preStart, preEnd, inorder, inStart, index - 1);
		}
		else
		{
			//如果左边没有值的话，那left直接就赋值为空
			left = NULL;
		}

		//递归右子树
		if ((index + 1) <= inEnd)
		{
			//判定右边是否还有值
			right = reConstruct(preorder, preStart, preEnd, inorder, index + 1, inEnd);
		}
		else
		{
			//如果右边没有值的话，那right直接就赋值为空
			right = NULL;
		}
		current->right = right;
		current->left = left;
		return current;
	}
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	//调用reConstruct进行递归
	if (preorderSize <= 0)
	{
		return NULL;
	}
	struct TreeNode* root = NULL;
	int preStart = 0, preEnd = preorderSize - 1;
	int inStart = 0, inEnd = preorderSize - 1;
	root = reConstruct(preorder, &preStart,preEnd, inorder, inStart,inEnd);
	return root;
}

int main()
{
	//int preorder[7] = {1,2,4,5,3,6,7};
	//int inorder[7] = {4,2,5,1,6,3,7};
	//int preorder[6] = {1,2,5,3,6,7};
	//int inorder[6] = {2,5,1,6,3,7};
	int preorder[6] = {1,2,3,4};
	int inorder[6] = {1,3,4,2};
	int numsize = 4;
	TreeNode* root = NULL;

	root = buildTree(preorder,numsize,inorder,numsize);
	return 0;
}