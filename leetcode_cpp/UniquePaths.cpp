/*
time   :  2015-5-18
author :  ht
comment:  求搜索路径的条数，其实是排列组合问题
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

long long int combination(int m, int n)
{
	int i, j;
	int num = m;
	long long int result = 1;
	int index = 1;
	for (i = 0; i < n; i++)
	{
		result = result*num/index;
		index++;
		num = num - 1;
	}
	return result;
}
int uniquePaths1(int m, int n) {
	if (m <= 1)
	{
		return 1;
	}
	if (n <= 1)
	{
		return 1;
	}
	int totalStep = m + n - 2;
	int down = n - 1;

	if (down > totalStep / 2)
	{
		down = totalStep - down;
	}

	long long int result = combination(totalStep,down);
	return result;
}
int uniquePaths(int m, int n) {
	//网上看到一个方法，用滚动数组的方法求解
	int i, j;
	int **matrix = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < m; i++)
		matrix[i][0] = 1;  //第一列赋值为1
	for (i = 0; i < n; i++)
		matrix[0][i] = 1;  //第一行赋值为1

	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
		}
	}
	int result = matrix[m - 1][n - 1];
	for (i = 0; i < m; i++)
		free(matrix[i]);
	free(matrix);

	return result;
}
int main()
{
	int m = 51;
	int n = 9;
	printf("%d \n",uniquePaths(m,n));
	return 0;
}