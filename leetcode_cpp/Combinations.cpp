/*
time   :  2015-5-15
author :  ht
comment:  n个数字中k的排列
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

void swap(int*a, int*b)
{
	int temp = a[0];
	a[0] = b[0];
	b[0] = temp;
}
void Perm(int *wList, int start, int end,int k, int*list,int**result, int* returnSize,int depth)
{
	//非字典序列
	int i = 0;
	if (depth>=k)
	{
		//退出条件	一定需要递归深度来进行判断
		// list用来保存临时变量  wList是原来的序列
		// k是要挑选的个数  result最后返回的， returnSize记录个数 其实可以不用
		memcpy(result[returnSize[0]], list, k*sizeof(int));
		returnSize[0]++;
	}
	else
	{
		for (i = start; i <= end; i++)
		{
			list[depth] = wList[i];
			Perm(wList, i + 1, end,k, list, result, returnSize,depth+1);
		}
	}
}
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** combine(int n, int k, int** columnSizes, int* returnSize) {

	returnSize[0] = 0;
	int len = 1, i;
	int num = n;
	int count = k;  //先求排列组合一共有多少种，开始算错了
	//没有除以 1 2 3 。。。 k导致len特别大，提交到 oj又runtime error
	if (k > n / 2)
	{
		count = n - k;
	}
	for (i = 0; i<count ; i++)
	{
		len *= num;
		num--;
	}
	for (i = 0; i<count; i++)
	{
		len /= (i+1);
	}
	//if (len > 10000)
		//return NULL;
	int**result = (int**)malloc(len*sizeof(int*));
	//第一个恶心的runtime error说的是要求自己分配columSizes的空间！！！！！！！
	//columnSizes = (int**)malloc(len*sizeof(int*));
	for (i = 0; i < len; i++)
	{
		result[i] = (int*)malloc(k*sizeof(int));
		
	}
	columnSizes[0] = (int*)malloc(len*sizeof(int));
	
	
	int end = n - 1, start = 0;
	int *list = (int*)malloc(k*sizeof(int));
	int *wList = (int*)malloc(n*sizeof(int));
	for (i = 1; i <= n; i++)
	{
		wList[i-1] = i;
	}
	int depth = 0;
	Perm(wList, start, end, k, list, result, returnSize,depth);
	for (i = 0; i < len; i++)
	{
		columnSizes[0][i] = k;
	}
	return result;
}

int main()
{
	int list[7] = { 1, 2,3,4 };
	int numsSize = 13, k = 13;
	int returnSize = 0;
	int *columnSizes =NULL;
	int** result = combine(numsSize, k, &columnSizes, &returnSize);
	printf("%d\n", returnSize);
	int i, j;
	//for (j = 0; j < returnSize; j++)
	//{
	//	printf("%d  ===================================== ", j);
	//	for (i = 0; i < columnSizes[j]; i++)
	//	{
	//		printf("%d ", result[j][i]);
	//	}
	//	printf("\n");
	//}
	return 0;
}