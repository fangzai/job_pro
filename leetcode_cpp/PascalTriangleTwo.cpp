/*
time   :  2015-5-9
author :  ht
comment:  产生piscal 三角形  和118功能很相似
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int* getRow(int rowIndex, int* returnSize) {
	if (rowIndex < 0)
	{
		return NULL;
	}
	int *result = (int*)malloc((rowIndex+1)*sizeof(int));  //注意空间分配
	returnSize[0] = rowIndex+1;
	int i = 0;

	result[0] = 1;
	for (i = 1; i <= rowIndex; i++)
	{
		result[0] = 1;
		result[i] = 1;
		for (int j = i / 2; j >= 1; j--)
		{
			result[j] = result[j] + result[j - 1];
		}
		for (int j = i / 2 + 1; j <= i; j++)
		{
			result[j] = result[i - j];
		}
				
		
			
	}
	return result;

}

int main()
{
	int num = 6;
	int returnSize;
	int*result = getRow(num,&returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}