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

int travser1(int* prices, int pricesSize) {
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
int maxSubArray(int* nums, int numsSize) {
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
	if (numsSize <= 0)
		return 0;

	int i, j;
	int ps, pe;
	int ts, te;
	int sum = 0;
	int max = INT_MIN;

	for (i = 0; i < numsSize; i++)
	{
		if (sum <= 0)
		{
			//重置sum
			//重置临时记录下标的ts和te
			sum = nums[i];
			ts = i;
			te = i;
		}
		else
		{
			sum += nums[i];
			te = i;
		}
		if (sum > max)
		{
			max = sum;
			ps = ts;
			pe = te;
		}
	}
	return max;
}
// 第二种方法是是递归的 将数组划分成两半，然后出现三种情况
// 1 子组在右边  
// 2 子组在左边
// 3 子组跨越了  写程序的时候这部分单独写，剩余的部分递归
// 复杂度是 nlogn 但是我估计我写不出来，递归要求都特别高
int* crossSubArray(int*nums, int low, int mid, int high)
{
	int leftSum = INT_MIN,rightSum = INT_MIN;
	int leftStart = 0, rightEnd = 0;
	int sum = 0;
	int i, j;
	for (i = mid; i >= 0; i--)
	{
		sum += nums[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			leftStart = i;
		}
	}
	sum = 0;
	for (j = mid + 1; j <= high; j++)
	{
		sum += nums[j];
		if (sum > rightSum)
		{
			rightSum = sum;
			rightEnd = j;
		}
	}
	int label[3] = { 0 };
	label[0] = leftStart;
	label[1] = rightEnd;
	label[2] = leftSum + rightSum;
	return label;
}
int* findMaxSubArray(int*nums,int low,int high)
{
	if (high == low)
	{
		int label[3] = {0};
		label[0] = low;
		label[1] = high;
		label[2] = nums[low];
		return label;//递归到了最深的地方了
	}
	else
	{
		int mid = (low + high) / 2;
		int *leftResult = NULL,*crossResult=NULL,*rightResult=NULL;
		leftResult = findMaxSubArray(nums, low, mid);
		rightResult = findMaxSubArray(nums, mid+1, high);
		crossResult = crossSubArray(nums, low, mid, high);
		if (leftResult[2] >= rightResult[2] && leftResult[2] >= crossResult[2])
		{
			return leftResult;
		}
		else
		{
			if (rightResult[2] >= leftResult[2] && rightResult[2] >= crossResult[2])
			{
				return rightResult;
			}
			else
			{
				return crossResult;
			}
		}

	}
}
int maxSubArray1(int* nums, int numsSize)
{
	if (numsSize <= 0)
		return 0;
	int *result = findMaxSubArray(nums, 0, numsSize - 1);
	return result[2];
}
int main()
{
	int nums[10] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	//int nums[10] = { -2, 11, -4, 13, -5, -2 };
	int numSize = 3;
	printf("%d \n", maxSubArray1(nums, numSize));
	return 0;
}