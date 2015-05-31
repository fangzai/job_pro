/*
time   :  2015-5-14
author :  ht
comment:  求数组内的最大和
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int maxProfit(int* prices, int pricesSize) {
	// 暴力搜索  复杂度是o(你n^2)
	int i, j;
	int ps, pe;
	int max = INT_MIN;  //初始化最小值

	int sum = 0;
	for (i = 0; i < pricesSize; i++)
	{
		sum = 0;
		for (j = i; j < pricesSize; j++)
		{
			sum += prices[j];
			if (sum > max)
			{
				max = sum;
				ps = i;  //保留位置
				pe = j;
			}
		}
	}
	printf("from %d  to from %d  == %d\n", ps, pe, max);
	return max;
}
// 第二种方法是是递归的 将数组划分成两半，然后出现三种情况
// 1 子组在右边  
// 2 子组在左边
// 3 子组跨越了  写程序的时候这部分单独写，剩余的部分递归
// 复杂度是 nlogn 但是我估计我写不出来，递归要求都特别高
int maxProfit1(int* prices, int pricesSize) {
	// 动态规划  复杂度是o(n)
	// 递推公式是 dp[i] = max(dp[i-1]+nums[i],nums[i])

	/*
	 *该算法基于的思想也很简单，最大连续子序列和的第一个元素不可能是负数，
	 *这点很好证明（反证），假设a[i…j]为最大的连续子序列且a[i]为负，那我
	 *a[i+1…j]的和将会大于a[i…j]的和，所以与原假设矛盾，这就能推出最大子
	 *序列和的第一个元素不可能是负数。得到这个结论我们就可以进一步进行推广，
	 *那就是如果一个子序列的和为负数，那么这个序列不可能是最大连续子序列中
	 *的开始的一段序列（类似于第一个元素的方法可得到证明即把这段和看做是一个元素）
	 */
	int i, j;
	int ps, pe;
	int ts, te;  //记录临时起点和终点
	int max = INT_MIN;  //初始化最小值
	if (pricesSize <= 0)
		return 0;
	int sum = 0;
	for (i = 0; i < pricesSize; i++)
	{
		if (sum <= 0)
		{
			sum = prices[i]; //把当前值赋给sum
			ts = i;  // 临时下标计数重置
			te = i;
		}
		else
		{
			sum += prices[i];  
			// 如果sum为正数，把后面这个放进去
			te = i;
		}

		if (sum > max)
		{
			//记录最大序列的和以及起点和终点
			max = sum;
			ps = ts;
			pe = te;
		}
	}
	printf("from %d  to from %d  == %d\n", ps, pe, max);
	return max;
}
int maxProfit2(int* prices, int pricesSize)
{
	//题目理解错了，应该是j>i  然后max(price[j]-prices[i]) 
	// 可以转化为动态规划
	int i, j;
	int ps, pe;
	int max = INT_MIN;  //初始化最小值

	int sum = 0;
	for (i = 0; i < pricesSize-1; i++)
	{
		prices[i] = prices[i+1] - prices[i];
	}
	
	int profit = maxProfit1(prices, pricesSize - 1);
	if (profit < 0)
	{
		profit = 0;
	}
	return profit ;
	
}

int main()
{
	int nums[10] = { 1,0, 6,5 , 5, 0 };
	//int nums[10] = {2,1};// { -2, 11, -4, 13, -5, -2 }
	int numSize = 6;
	printf("%d \n", maxProfit2(nums, numSize));
	return 0;
}