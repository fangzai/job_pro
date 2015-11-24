/*
time   :  2015-5-16
author :  ht
comment:  旋转后的数组，利用二分搜索某个target

*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;


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
	return right + 1; //返回的结果left > right，但是nums[left]肯定比target大

}
// http://www.cnblogs.com/lichen782/p/leetcode_Search_in_Rotated_Sorted_Array.html
int search(int* nums, int numsSize, int target){
	int left, right,mid;
	left = 0;
	right = numsSize - 1;
	//这一题的二分搜索下标界线判定太难了，需要仔细考虑
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (target == nums[mid])
			return mid;
		if (nums[left]<nums[mid])
		{
			// 说明落在第一个上升区间
			if (nums[left]<=target&&target < nums[mid])
			{
				//在left 和mid-1的区间搜索
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		else if (nums[left]>nums[mid])
		{
			//说明落在第二个上升区间
			if (nums[mid]<target&&target <= nums[right])
			{
				//在left 和mid-1的区间搜索
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		else  //单独考虑 left和mid重合的情况
		{
			left = mid + 1;
		}
	}

	return -1;

}

int main()
{
	int nums[10] = { 4,5,6 ,7 ,0 ,1 ,2,3 };
	int numSize = 8;

	int target = 1;
	for (int i = 0; i < numSize; i++)
	{
		target = nums[i];
		printf("%d  ==== %d\n",target ,search(nums, numSize, target));
	}

	return 0;
}