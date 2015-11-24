/*
time   :  2015-5-14
author :  ht
comment:  指数时间内查找到peak element
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int traverse(int*nums, int numSize)
{
	int midIndex = numSize / 2;
	if (numSize == 1)
	{
		return 0;
	}
	if (numSize==2)
	{
		if (nums[0] > nums[1])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if ((nums[midIndex] > nums[midIndex - 1]) && (nums[midIndex] > nums[midIndex + 1]))
	{
		return midIndex;
	}
	else
	{
		int index1 = traverse(nums,midIndex+1);
		if (index1 != -1&&index1!=midIndex)
			return index1;
		int index2 = traverse(nums+midIndex, numSize - midIndex);
		index2 += midIndex;  //这个地方需要注意一下，因为下标是从midIndex开始计算的
		//所以下一次的时候需要恢复一下
		if (index2 != -1 && index2 != midIndex)
			return index2;
	}
	return -1;
}

int findPeakElement(int* nums, int numsSize) {

	if (numsSize <= 0)
		return -1;
	if (numsSize == 1)
	{
		return 0;
	}
	return traverse(nums, numsSize);
}


int main()
{
	int nums[10] = { 1, 2, 3, 1,7 };
	int numSize = 3;
	printf("%d \n", findPeakElement(nums, numSize));
	return 0;
}