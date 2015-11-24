/*
time   :  2015-5-28
author :  ht
comment:  最长连续整数的问题
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		map<int, int> myMap;
		int maxVal = 1; //最小就是1
		int len = nums.size();
		int i;
		for (i = 0; i < len; i++)
			myMap.insert(pair<int,int>(nums[i],1));  //开始的时候置为1
		int left, right;// 左右两个方向搜索
		int value;
		for (i = 0; i < len; i++)
		{
			value =  nums[i];
			left = value - 1;
			right = value + 1;
			while (myMap[left])
			{
				myMap[left] = 0;//清除掉
				left--;
			}
			while (myMap[right])
			{
				myMap[right] = 0;//清除掉
				right++;
			}
			maxVal = myMax(maxVal,right-left-1);
		}
		return maxVal;
	}
	int myMin(int a,int b)
	{
		return a > b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	vector<int>nums = {100,4,200,1,2,3};
	Solution mine;
	int result;
	result = mine.longestConsecutive(nums);
	cout << result << endl;
	return 0;
}