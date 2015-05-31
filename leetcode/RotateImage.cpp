/*
time   :  2015-5-15
author :  ht
comment:  矩阵旋转 90度
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

void show(int** matrix, int m, int n)
{
	int i, j;
	printf("the matrix is ===========================================\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
/*
 *
 * 开始矩阵是这样排序的
 * 1 2 3 4 
 * 5 6 7 8
 * 9 10 11 12
 * 13 14 15 16
 *后来变成
 * 13 9 5 1
 *14 10 6 2
 * 15 11 7 3
 * 16 12 8 4
 * 可以看到它下标是从最右边开始的
 */

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
	int i, j,k;
	int len = matrixRowSize / 2;
	int temp1,temp2;
	int n = matrixRowSize;
	for (k = n - 1; k >= len; k--)
	{
		// 有了k就可以算出i了
		i = n - 1 - k;
		//从外围到里面
		for (j = i; j < k; j++)
		{
			temp1 = matrix[i][j];  
			//那么（i,j）的上一个节点是（n-j,i）
			matrix[i][j] = matrix[n-1 - j][i];

			// （i,j）的下一个节点是（j,n-i）
			temp2 = matrix[j][n-1 - i];
			matrix[j][n-1 - i] = temp1;

			//（j,n-i）的下一个节点是(n-i,n-j)

			temp1 = matrix[n-1 - i][n-1 - j];
			matrix[n-1 - i][n-1 - j] = temp2;

			// (n-i,n-j)下一个节点是 （n-j,i）
			matrix[n-1 - j][i] = temp1;
		}
		//show(matrix, n, n);
	}

}

int main()
{
	int n = 4;
	int **matrix = (int**)malloc(n*sizeof(int*));
	int i, j, index = 1;;
	for (i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(n*sizeof(int));
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = index;
			index++;
		}
	}
	show(matrix, n, n);
	rotate(matrix, n, n);
	show(matrix, n, n);
	return 0;
}