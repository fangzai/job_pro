/*
time   :  2015-5-26
author :  ht
comment:  从旋转过的sorted数据里面找到最小值,数组里面可能有重复值
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int findMin(int* nums, int numsSize) {
	//这个是线性时间复杂度，这里需要搜索一遍
	if (numsSize <= 0)
		return 0;
	if (numsSize == 1)
		return nums[0];
	int i;
	int max = 0;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i - 1] > nums[i])
		{
			max = nums[i];
			break;
		}
	}
	if (i == numsSize)
	{
		max = nums[0];  //如果到了最后都没有找到的话，就是第一个最小
	}
	return max;
}
int binarySearch(int* nums, int numsSize)
{
	//考虑一个复杂度为logn的算法  二分搜索
	//对于二分搜索的话，如果nums是sorted过的话没有什么问题
	//但是这里一个小问题就是它旋转了的
	int target = 10;
	int i;
	int left, mid, right;
	left = 0;
	right = numsSize - 1;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] > target)
		{
			//
			right = mid - 1;  //也剔除mid了
		}
		else if (nums[mid]<target)
		{
			left = mid + 1;  //已经剔除mid了
		}
		else
		{
			return mid;
		}
	}
	return -2;
}
int findMin1(int* nums, int numsSize)
{
	if (numsSize <= 0)
		return 0;
	int i, j;
	int min = nums[0];
	int low = 0, high = numsSize - 1, mid;
	//这里选择的是闭区间
	while (low<high)
	{
		if (nums[low] < nums[high])
			return nums[low];
		mid = low + (high - low) / 2;
		if (nums[mid]>nums[high])
		{
			low = mid + 1;  //搜索 最小值不可能是mid下标的，
		}
		else if (nums[mid]<nums[high])
		{
			high = mid;
		}
		else
		{
			low++; //如果nums[mid]和nums[high]一样的话
			//就不能做二分了，但是肯定最小值不是在low这边，只能在high那边
		}
	}
	return nums[low]; //退出的时候肯定nums[low]<=mid[high]
}

int main()
{
	//int nums[10] = { 4, 5, 6, 7, 0, 3, 3, 3 };
	int nums[10] = { 3,3,1,3};
	int numSize = 4;
	printf("%d \n", findMin1(nums, numSize));
	//printf("%d \n", binarySearch(nums, numSize)+1);
	return 0;
}