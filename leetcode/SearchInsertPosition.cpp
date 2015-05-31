/*
time   :  2015-5-16
author :  ht
comment:  找到某个元素的插入的位置,利用二分搜索

*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int searchInsert1(int* nums, int numsSize, int target) {
	//这是普通的方法，应该还有比较好的二分搜索方法
	if (numsSize <= 0)
		return 0;

	int i = 0, j;
	while (i < numsSize&&target>nums[i])
	{
		i++;
	}
	return i;

}
int searchInsert(int* nums, int numsSize, int target) {
	//二分搜索方法
	if (numsSize <= 0)
		return 0;
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
	return right+1; //返回的结果left > right，但是nums[left]肯定比target大

}

int main()
{
	int nums[10] = {1,3,5,6};
	int numSize = 4;

	int target = 5;
	//printf("%d\n", searchInsert(nums, numSize, target));
	target = 2;
	printf("%d\n", searchInsert(nums, numSize, target));

	target = 7;
	printf("%d\n", searchInsert(nums, numSize, target));

	target = 0;
	printf("%d\n", searchInsert(nums, numSize, target));

	return 0;
}