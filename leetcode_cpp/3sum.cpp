/*
time   :  2015-5-21
author :  ht
comment:  各种sum的问题
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	int num;
	int pos;
};
bool cmp(Node a,Node b)
{
	return a.num < b.num;
}

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return  res;
		sort(nums.begin(), nums.end());  //先用快排排序

		int len = nums.size();
		for (int i = 0; i < len - 2; i++)
		{
			//因为只可能遍历到倒数第二个
			if (i>0 && nums[i] == nums[i - 1])
				continue;  //避免出现重复的结果
			findTwoSum(nums, i + 1, len - 1, nums[i]);
		}
		return res;
	}
	void findTwoSum(vector<int>nums,int begin,int end,int target)
	{
		int left = begin;
		int right = end;
		while (left < right)
		{
			if ((nums[left] + nums[right] + target) == 0)
			{
				vector<int> temp;
				temp.push_back(target);
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
				if ((nums[left] + nums[right]) > -target)
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
	vector<int> twoSum(vector<int>& nums, int target) {
		//2 sum
		vector<int> result;  //存放最后的结果
		vector<Node> array;
		int i, j;
		Node temp;
		for (i = 0; i < nums.size(); i++)
		{
			temp.num = nums[i];
			temp.pos = i;
			array.push_back(temp);
		}
		sort(array.begin(), array.end(), cmp); //调用内部的排序算法 nlogn
		int sum = 0;
		for (i = 0, j = array.size() - 1; i != j;)
		{
			//左右指针搜索
			int sum = array[i].num + array[j].num;
			if (target == sum)
			{
				if (array[i].pos > array[j].pos)
				{
					result.push_back(array[j].pos + 1);
					result.push_back(array[i].pos + 1);
				}
				else
				{
					result.push_back(array[i].pos + 1);
					result.push_back(array[j].pos + 1);
				}
				break;
			}
			else
			{
				if (sum < target)
				{
					//后面的前面的指针后移
					i++;
				}
				else
				{
					//后面的指针前移
					j--;
				}
			}
			
		}
		return result;
	}
};

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	Solution mine;
	vector<int> result = mine.twoSum(nums, target);
	//cout << result[0] << " " << result[1] << endl;
	vector<int>nums1 = { -1,0,1,2,-1,-4};
	vector<vector<int>> res = mine.threeSum(nums1);
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