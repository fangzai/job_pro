/*
time   :  2015-5-10
author :  ht
comment:  求一个数组内非相邻元素的最大和
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
int rob(int* nums, int numsSize) {
	int i = 0;
	int *dp = (int*)malloc(numsSize*sizeof(int));
	if (numsSize <= 0)
		return 0;

	dp[0] = nums[0];
	dp[1] = max(nums[1],nums[0]);
	/*
	 * 这个地方用的循环，完全可以用递归的方式做
	 * 不过递归的方式消耗栈，然后也可以只维护两个数
	 * 没有必要再开内存空间
	 */
	for (i = 2; i < numsSize; i++)
	{
		dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
	}
	return dp[numsSize-1];
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int numsize = 1;
	printf("%d \n", rob(a, numsize));
	return 0;
}