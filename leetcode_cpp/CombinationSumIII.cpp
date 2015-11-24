/*
time   :  2015-5-24
author :  ht
comment:  ex40的升级版本，也就是说深度递归的次数必须是有限制的，等于特定的k
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> result;
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k <= 0)
			return result;
		//这里的递归深度必须是k
		int nums = 9;
		vector<int> candidates;
		int i, j;
		for (i = 1; i <= nums; i++)
		{
			candidates.push_back(i);
		}
		int sum = 0;
		int depth = 0;
		vector<int>tmp;
		traverse(candidates,n,sum,0,tmp,k,0);
		return result;
	}
	void traverse(vector<int> candidates, int target, int sum, int depth, vector<int>index, int maxDepth, int n)
	{
		if (depth == maxDepth)
		{
			//退出条件
			if (sum == target)
			{
				result.push_back(index);
			}
			return;
		}
		else
		{
			int len = candidates.size();
			int i;
			for (i = n; i < len; i++)
			{
				vector<int> temp = index;
				temp.push_back(candidates[i]);
				traverse(candidates, target, sum + candidates[i], depth + 1, temp, maxDepth, i + 1);
			}
		}
	}
};

int main()
{
	Solution mine;
	int k = 3;
	int n = 9;
	vector<vector<int>> result;
	result = mine.combinationSum3(k, n);
	int i, j;
	for (i = 0; i < result.size(); i++)
	{
		for (j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}