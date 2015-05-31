/*
time   :  2015-5-19
author :  ht
comment:  通过后序遍历和中序遍历重建二叉树
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
struct TreeNode* reConstruct(int* postorder, int postStart, int *postEnd, int* inorder, int inStart, int inEnd)
{
	//postEnd这个指针在递归过程中需要一直递减，且全局有效
	if (inStart == inEnd)
	{
		struct TreeNode* current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		//只剩下一个了
		current->val = postorder[postEnd[0]];
		current->left = NULL;
		current->right = NULL;
		postEnd[0]--;
		return current;
	}
	else
	{
		//后序遍历的第最后一个元素肯定是当前的根节点 查找该节点在中序遍历的位置
		int keyValue = postorder[postEnd[0]];
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
		postEnd[0]--;

		//这个地方递归左右子树的顺序和ex105 通过先序+中序 重构树的顺序不一样
		//可以简单推一下，对于后序遍历keyValue的后面一个值肯定是右子树的keyValue
		//递归右子树
		if ((index + 1) <= inEnd)
		{
			//判定右边是否还有值
			right = reConstruct(postorder, postStart, postEnd, inorder, index + 1, inEnd);
		}
		else
		{
			//如果右边没有值的话，那right直接就赋值为空
			right = NULL;
		}

		//递归左子树
		if ((index - 1) >= inStart)
		{
			//判定左边是否还有值
			left = reConstruct(postorder, postStart, postEnd, inorder, inStart, index - 1);
		}
		else
		{
			//如果左边没有值的话，那left直接就赋值为空
			left = NULL;
		}


		current->right = right;
		current->left = left;
		return current;
	}
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	//调用reConstruct进行递归
	if (postorderSize <= 0)
	{
		return NULL;
	}
	struct TreeNode* root = NULL;
	int postStart = 0, postEnd = postorderSize - 1;
	int inStart = 0, inEnd = postorderSize - 1;
	root = reConstruct(postorder, postStart, &postEnd, inorder, inStart, inEnd);
	return root;
}

int main()
{
	//int preorder[7] = {1,2,4,5,3,6,7};
	//int inorder[7] = {4,2,5,1,6,3,7};
	//int postorder[7] = {4,5,2,6,7,3,1};
	//int preorder[6] = {1,2,5,3,6,7};
	//int inorder[6] = {2,5,1,6,3,7};
	//int postorder[6] = { 5,2,6,7,3,1 };
	//int preorder[6] = { 1, 2, 3, 4 };
	int inorder[6] = { 1, 3, 4, 2 };
	int postorder[6]={4,3,2,1};
	int numsize = 4;
	TreeNode* root = NULL;

	root = buildTree(inorder, numsize, postorder, numsize);
	return 0;
}