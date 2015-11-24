/*
time   :  2015-5-21
author :  ht
comment:  各种sum的问题
		  这题是3sum问题的升级版，几乎和3sum问题一样，只是在查找twosum的
		  函数里面需要做一些变动
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

/*
 *这题是3sum问题的升级版，几乎和3sum问题一样，只是在查找twosum的
 * 函数里面需要做一些变动
 */
class Solution {
public:
	int min = INT_MAX;
	int res;
	bool flag;
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
			return  0;
		sort(nums.begin(), nums.end());  //先用快排排序

		int len = nums.size();
		for (int i = 0; i < len - 2; i++)
		{
			//因为只可能遍历到倒数第二个
			if (i>0 && nums[i] == nums[i - 1])
				continue;  //避免出现重复的结果
			findTwoSum(nums, i + 1, len - 1, nums[i],target);
		}
		return res;
		
	}
	void findTwoSum(vector<int>nums, int begin, int end, int current,int target)
	{
		int left = begin;
		int right = end;
		int temp,result;
		while (left < right)
		{
			temp = current + nums[left] + nums[right];
			result = temp;  //保存结果
			temp = temp - target;
			
			if (temp < 0)  //求绝对值
			{
				temp = -1 * temp;
				flag = false;
				left++;
			}
			else
			{
				right--;
				flag = true;
			}
			if (temp < min)
			{
				min = temp;
				res = result;
			}
		}
	}
};

int main()
{
	
	int target = 1;
	Solution mine;
	vector<int>nums1 = { -1,2,1,-4 };
	int res = mine.threeSumClosest(nums1,target);

	cout <<res<< endl;
	return 0;
}