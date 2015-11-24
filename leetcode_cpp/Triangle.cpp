/*
time   :  2015-5-13
author :  ht
comment:  分数转化为字符串输出
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
void traverse(int**triangle, int i,int j,int current,int numRows,int*index,int*data)
{
	//暴力遍历，和遍历树是差不多的  空间复杂度是 2^n
	if ((i+1) == numRows)
	{
		index[0]++;
		//printf("%d ===  %d \n",index[0], current);
		data[index[0] - 1] = current;
		//return current;
	}
	else
	{
		int temp1 = current +triangle[i+1][j];
		traverse(triangle, i + 1, j, temp1, numRows, index, data);

		int temp2 = current + triangle[i+1][j+1];
		traverse(triangle, i + 1, j + 1, temp2, numRows, index, data);
	}
}
int minimumTotal(int **triangle, int numRows) {
	int i = 0, j;
	if (numRows <= 0)
		return 0;
	int numSize = pow(2, numRows - 1);
	int *data = (int*)malloc(numSize*sizeof(int));
	for (i = 0; i < numSize; i++)
	{
		data[i] = 0;
	}

	int index = 0;
	traverse(triangle, 0, 0, triangle[0][0], numRows, &index, data);
	int min = data[0];

	for (i = 1; i < numSize; i++)
	{
		if (min > data[i])
		{
			min = data[i];
		}
		printf("%d ==========%d  \n", i, data[i]);
	}

	return min;
}
void reTraverse(int**triangle,int numRows, int index, int*data)
{
	// 逆向遍历，空间复杂度是 n
	// 因为前面好多是重复的  所以这个只需要比较当前的较小值就可以了
	int i;
	if ((index+1) == numRows)
	{

		for (i = 0; i <= index; i++)
		{
			data[i] = triangle[index][i];
			//最后一层上给data赋值，往上遍历
			//printf("%d ", data[i]);
		}
		//printf("\n");
	}
	else
	{
		index++;
		reTraverse(triangle, numRows, index, data);
		//这个地方的遍历边界要减掉1  因为前面 +1了
		for (i = 0; i <= index-1; i++)
		{
			data[i] = data[i] < data[i + 1] ? data[i] : data[i + 1];
			data[i] += triangle[index-1][i];
			//printf("%d ", data[i]);
		}
		//printf("\n");
	}
	
}
int minimumTotal1(int **triangle, int numRows) {
	int i = 0, j;
	if (numRows <= 0)
		return 0;
	int numSize = numRows;
	int *data = (int*)malloc(numSize*sizeof(int));
	for (i = 0; i < numSize; i++)
	{
		data[i] = 0;
	}
	int min = data[0];
	int index = 0;
	reTraverse(triangle, numRows, index, data);
	i = 0;
	return data[0];
}


int main()
{
	int num1[1] = {2};
	int num2[2] = { 3,4 };
	int num3[3] = { 6, 5 ,7};
	int num4[4] = { 4, 1, 8,3 };
	int num5[5] = { 4, 1, 8, 3 ,10};
	int *nums[5];
	nums[0] = num1;
	nums[1] = num2;
	nums[2] = num3;
	nums[3] = num4;
	nums[4] = num5;
	printf("%d \n", minimumTotal1(nums, 4));
	return 0;
}