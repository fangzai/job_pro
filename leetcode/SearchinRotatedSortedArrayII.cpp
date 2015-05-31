/*
time   :  2015-5-24
author :  ht
comment:  ex33的升级版，加了一个元素可以重复的条件
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
 *  再加了重复元素之后，都落在最后一个区间也就是left++那个区间
 *  但是平局起来还是比线性查找要好
 */
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int numsSize = nums.size();
		int left, right, mid;
		left = 0;
		right = numsSize - 1;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (target == nums[mid])
				return true;
			if (nums[left]<nums[mid])
			{
				// 说明落在第一个上升区间
				if (nums[left] <= target&&target < nums[mid])
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
			else
			{
				left = left + 1;  //只需要把我的上一个程序上left值直接改为
				//left++ 就可以了
			}
		}

		return false;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 1, 1, 1 };
	Solution mine;
	int target = 3;
	int result;
	result = mine.search(nums,target);
	cout <<  result << endl;
	return 0;
}