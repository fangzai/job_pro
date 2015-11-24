/*
time   :  2015-5-30
author :  ht
comment:  查看数组内是否有重复的元素
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int i = 0;
		map<int, int>myMap;
		for (i = 0; i < nums.size(); i++)
		{
			myMap[nums[i]]++;
			if (myMap[nums[i]] >= 2)
				return true;
		}
		return false;
	}
};

int main()
{
	vector<int> nums = {1,1,2};
	Solution mine;
	bool result;
	result = mine.containsDuplicate(nums);
	if (result)
		cout << "Duplicate!" << endl;
	return 0;
}