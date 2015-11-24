/*
time   :  2015-5-9
author :  ht
comment:  比较两个树
*/

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	bool left, right;
	if(p != NULL&&q!=NULL)
	{
		if (p->val != q->val)
		{
			return false;
		}
		if (isSameTree(p->left, q->left))
		{
			left = true;
		}
		else
		{
			left = false;
		}
		if (isSameTree(p->right, q->right))
		{
			right = true;
		}
		else
		{
			right = false;
		}
		return left&&right;

	}
	else
	{
		if (p == NULL&&q == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}