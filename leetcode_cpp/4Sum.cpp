/*
time   :  2015-5-21
author :  ht
comment:  3sum以及3sumclosest的升级版
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;



class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4)
			return  res;
		sort(nums.begin(), nums.end());  //先用快排排序

		int len = nums.size();
		int i, j;
		for (i = 0; i < len - 3; i++)
		{
			//因为只可能遍历到倒数第二个
			if (i>0 && nums[i] == nums[i - 1])
				continue;  //避免出现重复的结果
			for (j = i + 1; j < len - 2; j++)
			{
				if (j>(i+1) && nums[j] == nums[j - 1])
					continue;  //避免出现重复的结果
				int temp = nums[i] + nums[j];
				findTwoSum(nums, j + 1, len - 1, target,nums[i],nums[j]);
			}
			
		}
		return res;
	}
	void findTwoSum(vector<int>nums, int begin, int end, int target,int a,int b)
	{
		int left = begin;
		int right = end;
		while (left < right)
		{
			if ((a+b+nums[left] + nums[right] - target) == 0)
			{
				vector<int> temp;
				temp.push_back(a);
				temp.push_back(b);
				temp.push_back(nums[left]);
				temp.push_back(nums[right]);
				res.push_back(temp);

				//下面就是要过滤掉重复的nums[left]和nums[right]
				while ((left < right) && (nums[left] == nums[left + 1]))
					left++;
				while ((left < right) && (nums[right] == nums[right - 1]))
					right--;

				left++;  //不要退出，因为后面可能还有
				right--;
			}
			else
			{
				if ((a+b+nums[left] + nums[right]) > target)
				{
					right--;
				}
				else
				{
					left++;
				}
			}
		}
	}
};

int main()
{
	int target = 0;
	Solution mine;
	//cout << result[0] << " " << result[1] << endl;
	vector<int>nums1 = { 1,0,-1,0,-2,2 };
	vector<vector<int>> res = mine.fourSum(nums1,target);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}