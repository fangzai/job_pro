/*
time   :  2015-5-15
author :  ht
comment:  求存在重复元素集合的子集
*/

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;


/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int *mark;
int traverse(int*nums, int n, int**columnSizes, int *returnSize, int depth, int**result)
{
	if (depth >= n)
	{
		//递归退出条件
		int counter = 0;
		for (int i = 0; i < n; i++)
		{
			if (mark[i] == 1)
			{
				counter++;
			}
		}
		columnSizes[0][returnSize[0]] = counter;
		result[returnSize[0]] = (int*)malloc(counter*sizeof(int));
		counter = 0;
		for (int i = 0; i < n; i++)
		{
			if (mark[i] == 1)
			{
				result[returnSize[0]][counter] = nums[i];
				counter++;
			}
		}
		returnSize[0]++;
		return 0;
	}
	else
	{
		//用一个数组来记录某个数字是否被使用过，
		//如果前面的数字和本数相同，则前面的数必须被使用过本数才能被使用。
		//这几句和ex78里面的不一样
		// http://www.cnblogs.com/remlostime/archive/2012/11/15/2772209.html
		if (depth >= 1 && nums[depth] == nums[depth - 1])
		{
			//如果当前的元素和前面一个元素一样的话
				if (mark[depth - 1] == 1)
				{
					//必须前面的元素已经在mark里面了，这里才能正常选择
					traverse(nums, n, columnSizes, returnSize, depth + 1, result);
					mark[depth] = 1 - mark[depth];
					traverse(nums, n, columnSizes, returnSize, depth + 1, result);
				}
				else
				{
					//否则的话，这里只能跳过去了
					mark[depth] = 0;
					traverse(nums, n, columnSizes, returnSize, depth + 1, result);
				}
				return 0;
		}
		else
		{
			//如果当前的元素和前面一个元素不一样的话，那么它正常选择
			traverse(nums, n, columnSizes, returnSize, depth + 1, result);
			mark[depth] = 1 - mark[depth];
			traverse(nums, n, columnSizes, returnSize, depth + 1, result);
		}
		return 0;
	}
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize){
	if (numsSize <= 0)
		return NULL;
	int**result = NULL;
	int len = pow(2, numsSize);
	int i, j;
	mark = (int*)malloc(numsSize*sizeof(int));
	for (i = 0; i < numsSize; i++)
	{
		mark[i] = 0;
	}
	int temp;
	for (i = 0; i < numsSize; i++)
	{
		for (j = i; j < numsSize; j++)
		{
			if (nums[j] < nums[i])
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	for (i = 0; i < numsSize; i++)
	{

		//printf("%d", nums[i]);;
	}
	returnSize[0] = 0;
	result = (int**)malloc(len*sizeof(int*));
	columnSizes[0] = (int*)malloc(len*sizeof(int));
	traverse(nums, numsSize, columnSizes, returnSize, 0, result);
	return result;
}

int main()
{
	int nums[8] = { 1, 1, 2, 4 };
	int numSize = 3;
	int returnSize = 0;
	int *columnSize = NULL;
	int **result = NULL;
	result = subsetsWithDup(nums, numSize, &columnSize, &returnSize);
	//printf("%d\n", returnSize);
	int i, j;
	for (i = 0; i < returnSize; i++)
	{
		printf("{");
		for (j = 0; j < columnSize[i]; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("}\n");
	}
	return 0;
}