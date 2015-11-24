/*
time   :  2015-5-13
author :  ht
comment: 1-n的数字生成全排列，并输出
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
void Perm(int *list, int k, int m, int**result , int* returnSize)
{
	//非字典序列
	int i = 0;
	if (k == m)
	{
		//退出条件	
		memcpy(result[returnSize[0]],list,(m+1)*sizeof(int));
		returnSize[0]++;

	}
	else
	{
		for (i = k; i <= m; i++)
		{
			swap(&list[k], &list[i]);
			Perm(list, k + 1, m,result,returnSize);
			swap(&list[k], &list[i]);
		}
	}
}
/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int** permute(int* nums, int numsSize, int* returnSize) {
	
	returnSize[0] = 0;
	int len = 1,i;
	for (i = 1; i <= numsSize; i++)
	{
		len *= i;
	}
	int**result = (int**)malloc(len*sizeof(int*));
	for (i = 0; i < len; i++)
	{
		result[i] = (int*)malloc(numsSize*sizeof(int));
	}

	int m = numsSize - 1, k =0 ;
	Perm(nums, k, m, result , returnSize);
	return result;

}

int main()
{
	int list[3] = { 0, 1, 2 };
	int numsSize = 2;
	int returnSize = 0;
	int** result = permute(list, numsSize,&returnSize);
	
	int i,j;
	for (j = 0; j < returnSize; j++)
	{
		printf("%d  ===================================== ",j);
		for (i = 0; i < numsSize; i++)
		{
			printf("%d ", result[j][i]);
		}
		printf("\n");
	}
	return 0;
}