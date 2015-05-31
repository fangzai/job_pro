/*
time   :  2015-5-18
author :  ht
comment:  有障碍物的遍历
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void show(int**matrix, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
int traverse(int **matrix,int m,int n,int i,int j,int direction, int *treturnSize)
{
	if (i == (m-2) &&j == (n-2))
	{
		treturnSize[0]++;
		return 0;//正常退出
	}
	else
	{
		// 否则的话有两种遍历方式  direction 0 是向右 1 是向左
		int index1, index2;
		index1 = i + 1;
		index2 = j + 1;
		if ((matrix[index1][j] == 1) && (matrix[i][index2] == 1))
		{
			//没有路了，被堵住了
			return -1;
		}
		if (matrix[index1][j] != 1)
		{
			traverse(matrix, m, n, index1, j, direction, treturnSize);
		}
		if (matrix[i][index2] != 1)
		{
			traverse(matrix, m, n, i, index2, direction, treturnSize);
		}
		return 1;
	}
}

int uniquePathsWithObstacles1(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
	//递归的方式搜索路径,复杂度太高了
	int m = obstacleGridRowSize;
	int n = obstacleGridColSize;
	int i, j;
	int newM = m + 2;
	int newN = n + 2;
	int **matrix = (int**)malloc((m+2)*sizeof(int*));
	for (i = 0; i < m+2; i++)
	{
		matrix[i] = (int*)malloc((n+2)*sizeof(int));
		for (j = 0; j < n+2; j++)
		{
			matrix[i][j] = 1;
		}
	}

	for (i = 1; i < m + 1; i++)
	{
		for (j =1 ; j < n + 1; j++)
		{
			matrix[i][j] = obstacleGrid[i-1][j-1];
		}
	}
	//show(matrix, m+2, n+2);
	int returnSize = 0;
	int direction,startX =1,startY =1;
	direction= 0;
	int result = traverse(matrix, newM, newN, startX, startY, direction, &returnSize);

	// free
	for (i = 0; i < newM; i++)
		free(matrix[i]);
	free(matrix);
	matrix = NULL;

	return returnSize;
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
	
	int m = obstacleGridRowSize;
	int n = obstacleGridColSize;
	int i, j;
	int **matrix = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
	}
	//if (obstacleGrid[0][0] == 1)
	//{
	//	matrix[0][0] = 0;
	//}
	//else
	//{
	//	matrix[0][0] = 1;
	//}
	matrix[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
	for (i = 1; i < m; i++)
	{
		//第一列赋值为1
		matrix[i][0] = obstacleGrid[i][0] == 1 ? 0 : matrix[i - 1][0];
		//if (obstacleGrid[i][0] == 1)
		//{
		//	matrix[i][0] = 0;
		//}
		//
		//else
		//{
		//	matrix[i][0] = matrix[i-1][0];
		//}
	}
		
	for (i = 1; i < n; i++)
	{
		//第一行赋值为1
		matrix[0][i] = obstacleGrid[0][i] == 1 ? 0 : matrix[0][i - 1];
		//if (obstacleGrid[0][i] == 1)
		//{
		//	matrix[0][i] = 0;
		//}
		//else
		//{
		//	matrix[0][i] = matrix[0][i-1];
		//}
	}
		
	
	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			//这里开一矩阵，计算从起始点到当前位置步骤
			//相当于可以有上面的两个点走到该点
			matrix[i][j] = obstacleGrid[i][j] == 1 ? 0 : matrix[i - 1][j] + matrix[i][j - 1];
			

			//if (obstacleGrid[i][j] == 1)
			//{
			//	matrix[i][j] = 0;
			//}
			//else
			//{
			//	matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
			//}	
		}
	}
	
	int result = matrix[m - 1][n - 1];
	// free
	for (i = 0; i < m; i++)
		free(matrix[i]);
	free(matrix);
	matrix = NULL;

	return result;
}
int main()
{
	int m = 5;
	int n = 5;
	int i, j;
	int **matrix = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
	matrix[2][3] = 1;
	show(matrix, m, n);
	int result = uniquePathsWithObstacles(matrix, m, n);
	printf("%d \n",result);
	return 0;
}