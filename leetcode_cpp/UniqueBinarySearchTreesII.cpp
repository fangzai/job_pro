/*
time   :  2015-5-16
author :  ht
comment:  1.....n可以生成BST 二叉搜索树
		  返回所有的二叉搜索树
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// 这个用c语言写太麻烦，尤其是每次都返回的不同的那个left和right存的东西
class Solution {
public:
	Solution(){};
	vector<TreeNode *> generateTrees(int n) {
		return createTree(1, n);
	}

	vector<TreeNode *> createTree(int start, int end)
	{
		vector<TreeNode *> results;
		if (start>end)
		{
			results.push_back(NULL);
			return results;
		}

		for (int k = start; k <= end; k++)
		{
			//确定root节点
			vector<TreeNode *> left = createTree(start, k - 1);
			vector<TreeNode *> right = createTree(k + 1, end);
			for (int i = 0; i<left.size(); i++)
			{
				for (int j = 0; j<right.size(); j++)
				{
					TreeNode * root = new TreeNode();
					root->val = k;
					root->left = left[i];
					root->right = right[j];
					results.push_back(root);
				}
			}
		}
		return results;
	}
};

/*
 * c语言实现版本 表示是我自己写的  5-19日
 */
struct TreeNode** reConstruct(int start, int end, int *size)
{
	struct TreeNode** result = NULL;
	if (start >= end)
	{
		result = (struct TreeNode**)malloc(1 * sizeof(struct TreeNode*));
		size[0]++;
		if (start > end)
		{
			result[0] = NULL;  //最后一个数都没有了
		}
		else
		{
			result[0] = (struct TreeNode*)malloc(1 * sizeof(struct TreeNode));
			result[0]->val = start;//只剩一个数字了
			result[0]->left = NULL;
			result[0]->right = NULL;
		}

		return result;
	}
	else
	{
		int k, i, j;

		//首先，选一个k作为keyValue
		int leftSize = 0, rightSize = 0;

		result = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
		//没有办法控制result的大小，所以提前开大一点儿
		int count = 0;
		for (k = start; k <= end; k++)
		{
			//会返回一堆可行的left和right;
			leftSize = 0;
			rightSize = 0;
			struct TreeNode** left = reConstruct(start, k - 1, &leftSize);
			//左边生成的集合

			struct TreeNode** right = reConstruct(k + 1, end, &rightSize);
			//右边生成的集合
			for (i = 0; i < leftSize; i++)
			{
				for (j = 0; j < rightSize; j++)
				{
					struct TreeNode*root = (struct TreeNode*)malloc(1 * sizeof(struct TreeNode*));
					root->val = k;  //k为当前root
					root->left = left[i];
					root->right = right[j];
					result[count] = root;
					count++;
				}
			}
		}
		size[0] = count;  //表示当前集合的大小
		return result;
	}
}

struct TreeNode** generateTrees(int n, int* returnSize) {
	int count = 0;
	struct TreeNode** root = reConstruct(1, n, &count);
	returnSize[0] = count;
	return root;
}
int main()
{
	//Solution UBST;
	//int n = 3;
	//UBST.generateTrees(3);

	int returnSize = 0;
	int n = 3;
	struct TreeNode** root = generateTrees(n, &returnSize);
	return 0;
}

/*
time   :  2015-5-19
author :  ht
comment:  下面是用c代码实现的，对于内存的管理没有那么严格

*/
/*

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

struct TreeNode** reConstruct(int start, int end, int *size)
{
	struct TreeNode** result = NULL;
	if (start >= end)
	{
		result = (struct TreeNode**)malloc(1 * sizeof(struct TreeNode*));
		size[0]++;
		if (start > end)
		{
			result[0] = NULL;  //最后一个数都没有了
		}
		else
		{
			result[0] = (struct TreeNode*)malloc(1 * sizeof(struct TreeNode));
			result[0]->val = start;//只剩一个数字了
			result[0]->left = NULL;
			result[0]->right = NULL;
		}

		return result;
	}
	else
	{
		int k, i, j;

		//首先，选一个k作为keyValue
		int leftSize = 0, rightSize = 0;

		result = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
		//没有办法控制result的大小，所以提前开大一点儿
		int count = 0;
		for (k = start; k <= end; k++)
		{
			//会返回一堆可行的left和right;
			leftSize = 0;
			rightSize = 0;
			struct TreeNode** left = reConstruct(start, k - 1, &leftSize);
			//左边生成的集合

			struct TreeNode** right = reConstruct(k + 1, end, &rightSize);
			//右边生成的集合
			for (i = 0; i < leftSize; i++)
			{
				for (j = 0; j < rightSize; j++)
				{
					struct TreeNode*root = (struct TreeNode*)malloc(1 * sizeof(struct TreeNode*));
					root->val = k;  //k为当前root
					root->left = left[i];
					root->right = right[j];
					result[count] = root;
					count++;
				}
			}
		}
		size[0] = count;  //表示当前集合的大小
		return result;
	}
}

struct TreeNode** generateTrees(int n, int* returnSize) {
	int count = 0;
	struct TreeNode** root = reConstruct(1, n, &count);
	returnSize[0] = count;
	return root;
}

int main()
{
	int returnSize = 0;
	int n = 3;
	struct TreeNode** root = generateTrees(n, &returnSize);
	return 0;
}
*/