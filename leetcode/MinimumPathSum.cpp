/*
time   :  2015-5-18
author :  ht
comment:  求最短路径
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


/*
 * 和 ex62 ex63 基本上一样的
 * 其实也可以用递归来做，但是，看着题的架势估计又会说超时了
 */
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
	int m = gridRowSize;
	int n = gridColSize;
	int i, j;
	int **matrix = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
		for (j = 0; j < n; j++)
			matrix[i][j] = 0;
	}
	matrix[0][0] = grid[0][0];
	for (i = 1; i < m; i++)
	{
		matrix[i][0] = grid[i][0] + matrix[i - 1][0];  //第一列赋值
		//printf("%d ",matrix[i][0]);
	}
	//printf("\n");
	for (i = 1; i < n; i++)
	{
		matrix[0][i] = grid[0][i] + matrix[0][i - 1];  //第一行赋值
		//printf("%d ", matrix[0][i]);
	}
	//printf("\n");

	int min;
	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			min = matrix[i - 1][j] < matrix[i][j - 1] ? matrix[i - 1][j] : matrix[i][j - 1];
			matrix[i][j] = grid[i][j]+ min;
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
	int **grid = NULL;
	int m = 2;
	int n = 3;
	grid = (int**)malloc(m*sizeof(int*));
	int nums1[3] = { 1, 2,5};
	int nums2[3] = { 3, 2,1};
	int nums3[3] = { 4, 2, 1 };
	grid[0] = nums1;
	grid[1] = nums2;
	//grid[2] = nums3;

	int result = minPathSum(grid, m, n);
	
	printf("%d \n", result);
	return 0;
}