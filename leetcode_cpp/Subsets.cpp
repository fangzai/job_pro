/*
time   :  2015-5-15
author :  ht
comment:  求一个集合的所有子集，元素互不相同
          该题求子集相当于遍历一棵二叉树
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
		for (int i = 0;i < n; i++)
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
		traverse(nums, n, columnSizes, returnSize, depth + 1, result);
		mark[depth] = 1 - mark[depth];
		traverse(nums, n, columnSizes, returnSize, depth + 1, result);
		return 0;
	}
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
	if (numsSize <= 0)
		return NULL;
	int**result = NULL;
	int len = pow(2, numsSize);
	int i,j;
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
	int nums[8] = {1,1,2,4};
	int numSize = 3;
	int returnSize = 0;
	int *columnSize = NULL;
	int **result = NULL;
	result = subsets(nums, numSize, &columnSize, &returnSize);
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