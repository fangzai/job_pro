/*
time   :  2015-5-11
author :  ht
comment:  判定是否是平衡二叉树
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
 *  平衡二叉树，又称AVL树。它或者是一棵空树，或者是具有下列性质的二叉树：
 *  它的左子树和右子树都是平衡二叉树，且左子树和右子树的高度之差之差的绝
 *  对值不超过1。
 */
int Depth(struct TreeNode* current,bool*label)  
{
	//求树的高度  并且同时把该子树的AVL平衡性求出来
	//存在label里面
	int left = 0;
	int right = 0;
	int height = 0;
	if (current != NULL)
	{
		bool mark1,mark2;
		left = Depth(current->left,&mark1);
		right = Depth(current->right,&mark2);
		
		int dist = abs(left - right);
		if (dist <= 1)
		{
			label[0] = mark1&& mark2;
		}
		else
		{
			label[0] = false;
		}
		
		height = left > right ? left : right;
		return height + 1;
	}
	else
	{
		label[0] = true;
		return 0;
	}

}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	//bool leftBalanced = isBalanced(root->left);
	bool label;

	int leftHeight = Depth(root,&label);
	return label;
}
int main()
{
	return 0;
}