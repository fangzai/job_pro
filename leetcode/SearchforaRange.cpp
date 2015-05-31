/*
time   :  2015-5-22
author :  ht
comment:  有序数组中查找某个元素的range
		  要求nlogn的时间复杂度内完成
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> result;
	vector<int> searchRange(vector<int>& nums, int target) {
		binarySearch(target,nums);
		return result;
	}
	vector<int> binarySearch(int key, vector<int> nums)
	{
		//二分搜索是可以查找到其原本可以插入的位置
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		int leftRange, rightRange;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (nums[mid] == key)
			{
				leftRange = mid;
				while ((leftRange-1) >= 0 && nums[leftRange-1] == key)
					leftRange--;
				
				rightRange = mid;
				while ((rightRange+1) <= (nums.size() - 1) && nums[rightRange+1] == key)
					rightRange++;

				result.push_back(leftRange);
				result.push_back(rightRange);
				return result;
			}
			if (nums[mid] > key)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
};

int main()
{
	//vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	//vector<int> nums = { 8, 8, 8, 8, 8, 8 };
	vector<int> nums = { 1, 2, 3, 4, 5, 8 };
	int target = 8;
	Solution mine;
	
	vector<int>result;
	result = mine.searchRange(nums, target);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}