/*
time   :  2015-5-25
author :  ht
comment:  二叉搜索树的恢复，里面有两个元素交换了
		  需要把这两个找出来，并且恢复原来的tree
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
*平衡树的特性 : root->key  大于  left->key
*               root->key  小于  right->key
*               并且其子树也是平衡树
*/
//能想到要遍历记录三个节点，依次滑动，但是写的时候居然没有自己写出来！！！
void traverse(struct TreeNode* current,struct TreeNode **p1, struct TreeNode**p2, struct TreeNode**pre)
{
	//中序遍历二叉搜索树，违反规则的就是两个mistake
	if (current == NULL) return;
	
	traverse(current->left,p1, p2,pre);
	//这里有了current,先给pre赋值
	if (pre[0] != NULL&&pre[0]->val > current->val)
	{
		//找到违反规则的了  前面的节点一定要比后面的小
		//可以画一个图看看，第一次违反的时候一定是一个波峰，违反的节点是波峰
		//也就是pre

		//第二次违反的时候是一个波谷
		//而违反的节点就是current,所以else语句后面是给p2赋值
		
		//那为什么在if判断里面第一次遇到p1和p2都赋值了？
		//这是因为两个交换的点可能是相邻的，而p1是pre，p2就是current
		//刚好这个波峰波谷的形式和上面两次违反规则的分析是一致的
		if (p1[0] == NULL)
		{
			p1[0] = pre[0];
			p2[0] = current;
		}
		else
		{
			p2[0] = current;
		}
	}
	pre[0] = current;  //窗口滑动，current给pre
	traverse(current->right, p1, p2, pre);  //遍历右子树

}
void recoverTree(struct TreeNode* root) {
	struct TreeNode*p1, *p2, *pre;
	int tmp;
	p1 = NULL;
	p2 = NULL;
	pre = NULL;
	traverse(root, &p1, &p2, &pre);
	//最后交换两个点
	if (p1 != NULL&&p2 != NULL)
	{
		tmp = p1->val;
		p1->val = p2->val;
		p2->val = tmp;
	}
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	int value[15] = { 6, 3, 1, -1, -1, 10, -1, -1, 5, 9, -1, -1, 12, -1, -1 };
	//int value[15] = {1,-1,2,-1,3,-1,-1};
	//int value[15] = { 3, 1, 0, -1, -1, 2, -1, 3, -1, -1, 5, -1, -1 };   //非平衡树 因为有重复元素
	//这是一颗满树
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 15;
	root = Node(root, &index, value, nums);
	int returnSize = 0;
	recoverTree(root);
	return 0;
}