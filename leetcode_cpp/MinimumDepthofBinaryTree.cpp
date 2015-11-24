/*
time   :  2015-5-10
author :  ht
comment:  求root到叶子节点最近的节点
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
/*
 *这一题和求树的高度不一样，因为要确定叶子节点
 *其次，如果只有一个root的话，那么它到leaf的距离是 1 我去！！什么破规定啊！
 *遍历的时候分四种情况 
 * 1 节点是叶子
 * 2 右节点为空，左节点不空
 * 3 左节点为空，右节点不空
 * 4 左右节点有数据和孩子
 */
int traverse(struct TreeNode* current)
{
	int left = 0;
	int right = 0;
	int height = 0;
	if ((current->left == NULL)&&(current->right == NULL))
	{
		return 0;       
		//一定要确定叶子
		//和ex104最长距离不一样
	}
	else
	{
		if (current->left == NULL)
		{
			return 1 + traverse(current->right);
		}
		if (current->right == NULL)
		{
			return 1+ traverse(current->left);
		}
		right = traverse(current->right);
		left = traverse(current->left);
		height = left > right ? right : left;
		return height + 1;
			
	}
}
int minDepth(struct TreeNode* root) {
	int height = 0;
	if (root == NULL)
		return 0;
	height = traverse(root);
	return height+1;  //这个地方要+1
}

int main()
{
	return 0;
}