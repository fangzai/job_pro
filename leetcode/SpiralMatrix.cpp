/*
time   :  2015-5-14
author :  ht
comment:  顺时针读取矩阵
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void show(int **matrix, int m, int n)
{
	int i, j;
	printf("========================================\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {

	int m = matrixRowSize;
	int n = matrixColSize;
	int i, j, k,p;

	int min = (m>n ? n : m);
	int len;
	if (min % 2 == 0)
	{
		len = (min) / 2;
	}
	else
	{
		len = (min) / 2;
		len++;
	}
	
	int index = 0;
	if (n <= 0 || m <= 0)
		return NULL;
	int *result = (int*)malloc(m*n*sizeof(int));
	if (m == 1)
	{
		memcpy(result,matrix[0],n*sizeof(int));
		return result;
	}
	if (n == 1)
	{
		
		for (i = 0; i < m; i++)
		{
			result[i] = matrix[i][0];
		}
		return result;
	}
	int start,end;
	for (k = 0; k <len; k++)
	{
		i = k;
		//第一个坐标是(i,i)
		start = i;
		end = n - 1 - i;
		for (j = i; j < n-1-i; j++)
		{
			result[index] = matrix[i][j];
			index++;
		}
		if ((index + 1) >= m*n)   
		{
			//如果是奇数话，读到这里就结束了
			result[index] = matrix[i][ n - 1 - i];
			index++;
			break;
		}

		//第二个坐标是(i,n-1-i)

		start = i;
		end = m - 1 - i;
		j = n - 1 - i;
		for (p = i; p < m-1-i; p++)
		{
			result[index] = matrix[p][j];
			index++;
		}

		//第三个坐标是(m-1-i,n-1-i)
		start = n - 1 - i;
		end = i;
		p = m - 1 - i;
		for (j = n - 1 - i; j > i; j--)
		{
			result[index] = matrix[p][j];
			index++;
		}
		//第四个坐标是(m-1-i,i)
		start = m - 1 - i;
		end = i;
		j = i;
		for (p = m - 1 - i; p > i; p--)
		{
			result[index] = matrix[p][j];
			index++;
		}
		if (index >= m*n)
			break;
	}
	printf("%d \n",index);
	return result;
}

int main()
{
	int m = 3;
	int n = 6;
	int **matrix = (int**)malloc(m*sizeof(int*));
	int i, j,index =1;
	for (i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = index;
			index++;
		}
	}
	show(matrix, m, n);
	int *result = spiralOrder(matrix, m, n);
	for (i = 0; i < m*n; i++)
	{
		printf("%d ", result[i]);
		//printf("%d============ %d\n",i, result[i]);
	}
	printf("\n");
	return 0;
}