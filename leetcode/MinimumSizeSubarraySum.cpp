/*
time   :  2015-5-22
author :  ht
comment:  数组中 求某个最小子组和大于特定的数
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		
		//sort(nums.begin(), nums.end());  //先进行排序
		int ps, pe;
		int i, j;
		ps = 0; pe = 0;
		int sum = 0;
		int len = nums.size();
		int result = len + 1;
		while (pe < len)
		{
			sum += nums[pe]; //加上右边的值
			while (sum >= s)
			{
				if ((pe - ps+1) == 1)
					return 1;

				//当前的长度是pe-ps +1
				result = myMin(result, pe - ps + 1);
				sum -= nums[ps];
				ps++;//起始值下标加1
			}
			pe++; //这个时候sum<s了
		}
		if (result == (len+1))
		{
			return 0;  //压根儿没有找到
		}
		else
		{
			return result;
		}
	}
	int myMin(int a, int b)
	{
		return a>b ? b : a;
	}
	int minSubArrayLen1(int s, vector<int>& nums)
	{
		if (nums.size() <= 0)
			return 0;
		// 这个算法的复杂度是nlogn需要用到二分搜索
		int len = nums.size();
		vector<int>sums(len+1,0);  //构造一个len + 1的求和数组  其中sum[i]表示 0->i-1的和
		int i;
		for (i = 1; i < len+1; i++)
			sums[i] = (sums[i-1] + nums[i-1]);
		int right, result=len+1;
		for (i = 0; i < len+1; i++)
		{
			right = binarySearch(i+1,len,sums[i]+s,sums);
			// start下标应该从 i的下一个开开始
			//而key值刚好是sums[i]也就是从0到i-1，加上s开始
			//举个例子  nums ={1,4,4}
			//sums = {0,1,5,9}  当i =1的时候应该从sum的2下标开始搜索
			//而且key的话，应该是  1 + s = 5 也就是sum[1]+s
			if (right == (len + 1))
				break;
			result = myMin(result,right-i);
		}
		return result == (len + 1) ? 0:result;
	}
	int binarySearch(int left,int right,int key,vector<int> nums)
	{
		//二分搜索是可以查找到其原本可以插入的位置
		int mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (nums[mid] >= key)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
};

int main()
{
	//vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	vector<int> nums = { 1,4,4 };
	int s = 4;
	Solution mine;
	int result;
	result = mine.minSubArrayLen1(s, nums);
	cout << result << endl;

	//vector<int>nums1 = {1,4,5,8,9,10};
	//int target = 5;
	//result = mine.binarySearch(0,5,target,nums1);
	//cout << result << endl;
	return 0;
}
