/*
time   :  2015-5-25
author :  ht
comment:  层级遍历二叉树，然后将每一层的都连接起来
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
using namespace std;


//Definition for a binary tree node.
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left,*right,*next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		traverse(root);
	}
	void traverse(TreeLinkNode *root)
	{
		queue<TreeLinkNode*> myQueue1;
		queue<TreeLinkNode*> myQueue2;
		myQueue1.push(root);

		TreeLinkNode* current,*pre=NULL;
		int count = 0;
		while (!myQueue1.empty() || !myQueue2.empty())
		{
			count = 0;
			while (!myQueue1.empty())
			{
				current = myQueue1.front();
				myQueue1.pop();
				if (count > 0)
				{
					pre->next = current;
				}
				if (current->left != NULL)
				{
					myQueue2.push(current->left);
				}
				if (current->right != NULL)
				{
					myQueue2.push(current->right);
				}
				pre = current;
				count++;
			}
			pre->next = NULL;
			
			count = 0;
			while (!myQueue2.empty())
			{
				current = myQueue2.front();
				myQueue2.pop();
				if (count > 0)
				{
					pre->next = current;
				}
				if (current->left != NULL)
				{
					myQueue1.push(current->left);
				}
				if (current->right != NULL)
				{
					myQueue1.push(current->right);
				}
				pre = current;
				count++;
			}
			pre->next = NULL;
		}

	}
};

int main()
{
	//int value[6] = { 1, -1, 2, 3, -1, 2 };
	int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 2, 5, -1, -1, 2, -1, -1 };
	//int value[100] = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};  //size =15 满二叉树
	//int value[100] = { 1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, 12, -1, -1, 13, -1, -1, 7, 14, -1, -1, 15, -1, -1 };  //size =15 满二叉树
	struct TreeLinkNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 13;
	root = Node(root, &index, value, nums);
	Solution mine;

	mine.connect(root);
	return 0;
}