/*
time   :  2015-5-16
author :  ht
comment:  如果一个矩阵中有0的话，就把所有的元素都置为0
 
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
void show(int **matrix,int m,int n)
{
	int i, j;
	printf("========================================\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
//正常情况下用的是o(mn)的算法，直接遍历，发现有0的话
//遍历一次矩阵，所有的元素都为0

//第一种方法是o(m+n)  开两个数组来标记该行该列是否应该置为0
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
	if (matrix == NULL||matrix[0]==NULL)
		return;
	int m = matrixRowSize;
	int n = matrixColSize;
	int*row = (int*)malloc(m*sizeof(int));
	int*col = (int*)malloc(n*sizeof(int));
	int i, j;
	for (i = 0; i < m; i++)  //好奇葩，必须要先置为0 oj才让过
	{
		row[i] = 0;
	}
	for (j = 0; j < n; j++)
	{
		col[j] = 0;
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (row[i] == 1 || col[j] == 1)
				matrix[i][j] = 0;
		}
	}

}

//第二种方法是常数空间内完成
void setZeroes1(int** matrix, int matrixRowSize, int matrixColSize)
{
	//用第一行和第一列来表示某一行和某一列是否应该置为0
	if (matrix == NULL || matrix[0] == NULL)
		return;
	int m = matrixRowSize;
	int n = matrixColSize;
	int i, j;
	bool firstRow = false;  //第一行的标记
	bool firstCol = false;
	for (i = 0; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			firstCol = true;  //存第一列有没有0
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (matrix[0][i] == 0)
		{
			firstRow = true; //存第一行有没有0
			break;
		}
	}

	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;  
				//从第二行 第二列开始遍历，如果遇到0,
				//就将该行的第一个元素或者该列的第一个元素置为0
				matrix[0][j] = 0;
			}
		}
	}


	for (i = 1; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			for (j = 1; j < n; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	for (i = 1; i < n; i++)
	{
		if (matrix[0][i] == 0)
		{
			for (j = 1; j < m; j++)
			{
				matrix[j][i] = 0;
			}
		}

	}
	//最后遍历第一行 和第一列
	if (firstRow)
	{
		for (i = 0; i < n; i++)
		{
			matrix[0][i] = 0;
		}
	}
	if (firstCol)
	{
		for (i = 0; i < m; i++)
		{
			matrix[i][0] = 0;
		}
	}

}

int main()
{
	int m, n,i,j;
	m = 5;
	n = 6;
	int ** matrix;
	matrix = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = 1;
		}
	}
	matrix[1][3] = 0;
	//int**matrix; 
	//matrix = (int**)malloc(m*sizeof(int*)); 
	//for (int i = 0; i < m; i++)
	//{
	//	matrix[i] = (int*)malloc(n*sizeof(int));
	//}
	//matrix[0][0] = INT_MIN;
	//matrix[1][0] = 2;
	//matrix[2][0] = 3;
	show(matrix,m,n);
	setZeroes1(matrix, m, n);
	show(matrix, m, n);
	return 0;
}