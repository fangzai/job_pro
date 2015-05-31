/*
time   :  2015-5-16
author :  ht
comment:  二叉搜索树的验证
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
                 root->key  小于  right->key
				 并且其子树也是平衡树
 */
int* traverse(struct TreeNode* current)
{
	
	//需要构造一个数组，每次返回当树的 BST特性的判断  以及该树的最大元素和最小元素
	if ((current->left == NULL) && (current->right == NULL))
	{
		int *result = (int*)malloc(3*sizeof(int));
		result[0] = 1;
		result[1] = current->val;  //最小值  left  
		result[2] = current->val;  //最大值  right
		return result;
	}
	else
	{
		int *result = (int*)malloc(3 * sizeof(int));
		int *leftResult=NULL,*rightResult=NULL;

		if (current->left != NULL)
		{
			if (current->right != NULL)
			{
				leftResult = traverse(current->left);
				rightResult = traverse(current->right);
				if (rightResult[0] && leftResult[0]&&current->val>leftResult[2]&&current->val<rightResult[1])
				{
					result[0] = 1;
					result[1] = leftResult[1]; //左子树的最小值
					result[2] = rightResult[2];//右子树的最大值
				}
				else
				{
					result[0] = 0;
				}
				free(leftResult);  //内存回收
				leftResult = NULL;
				free(rightResult);
				rightResult = NULL;

			}
			else
			{
				leftResult = traverse(current->left);
				if (leftResult[0] && current->val > leftResult[2])
				{
					result[0] = 1;
					result[1] = leftResult[1]; //最小元素不变
					result[2] = current->val;  //最大元素更新为当前root的node值
				}
				else
				{
					result[0] = 0;
				}
				free(leftResult);     //内存回收
				leftResult = NULL;
			}
			
		}
		else
		{
			rightResult = traverse(current->right);
			if (rightResult[0] && current->val < rightResult[1])
			{
				result[0] = 1;
				result[1] = current->val;    //最小元素更新为当前root的node值
				result[2] = rightResult[2];  //最大元素不变
			}
			else
			{
				result[0] = 0;
			}
			free(rightResult);   //内存回收
			rightResult = NULL;
			
		}
		return result;
	}
}
bool isValidBST(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int *result = traverse(root);
	bool mark = result[0];
	
	
	free(result);     //内存回收
	result = NULL;  
	return  mark;
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	//int value[13] = { 1, 2, -1, -1, 4, 5, 3, -1, -1, 8, -1, -1, -1 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
	//int value[15] = {1,-1,2,-1,3,-1,-1};
	int value[15] = { 3,1,0,-1,-1,2,-1,3,-1,-1,5,-1,-1 };   //非平衡树 因为有重复元素
	//这是一颗满树
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 11;
	root = Node(root, &index, value, nums);
	int returnSize = 0;
	if (isValidBST(root))
	{
		printf("Is BST!\n");
	}
	else
	{
		printf("Not BST!\n");
	}
	return 0;
}