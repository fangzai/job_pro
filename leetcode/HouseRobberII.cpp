/*
time   :  2015-5-20
author :  ht
comment:  house robber的升级版本
          求一个数组内非相邻元素的最大和
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

//动态规划的思想
/*维护一个数组dp，dp[i]表示到了i，非相邻元素的最大和
*这样的可以得到dp{i] = max(num[i]+dp[i-2],dp[i-1))
*/

int max(int a, int b)
{
	return a > b ? a : b;
}
/*
 * 关于原来的house robber,再归纳一遍
 * 假设dp[i]是偷到i家时候的最大值
 * dp[0] = nums[0]  因为只有一家
 * dp[1] = max(nums[0],num[1])
 * 当偷到第三家的时候，dp[2] = max(dp[1],dp[0]+nums[2])  因为偷了第二家不可能再偷第三家
 * 但是偷了第一家后可以偷第三家
 */
int traverse(int* nums, int numsSize)
{
	int i = 0;
	int *dp = (int*)malloc(numsSize*sizeof(int));
	if (numsSize <= 0)
		return 0;

	dp[0] = nums[0];
	dp[1] = max(nums[1], nums[0]);

	int pre1, pre2;
	for (i = 2; i < numsSize; i++)
	{
		dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
	}
	int result = dp[numsSize - 1];
	//free(dp);
	//dp = NULL;
	return result;
}
int rob(int* nums, int numsSize) {
	if (numsSize <= 0)
		return 0;
	if (numsSize == 1)
		return nums[0];
	int result1, result2;
	result1 = traverse(nums + 1, numsSize - 1);//从第二家到最后
	result2 = traverse(nums, numsSize - 1);   //从第一家到倒数第二家
	return max(result1, result2);
}

int main()
{
	int a[10] = { 2, 1, 1, 1, 5, 6, 7, 8, 9, 10 };
	int numsize = 4;
	printf("%d \n", rob(a, numsize));
	return 0;
}