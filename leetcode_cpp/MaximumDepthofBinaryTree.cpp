/*
time   :  2015-5-10
author :  ht
comment:  ÇóÊ÷¸ß
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

int traverse(struct TreeNode* current)
{
	int left = 0;
	int right = 0;
	int height = 0;
	if (current != NULL)
	{
		left = traverse(current->left);
		right = traverse(current->right);
		height = left > right ? left : right;
		return height +1;
	}
	else
	{
		return 0;
	}
		
}
int maxDepth(struct TreeNode* root) 
{
	int height;
	height = traverse(root);
	return height;
}

int main()
{
	return 0;
}