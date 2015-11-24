/*
time   :  2015-5-24
author :  ht
comment:  找到集合里面数字和为target的子数组
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
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		int len = candidates.size();
		if (len <= 0)
			return result;
		
		sort(candidates.begin(), candidates.end());
		preProcess(candidates); //去除重复元素
		vector<int> index;
		traverse(candidates,target,0,0,index,1000,0);
		return result;
	}
	void traverse(vector<int> candidates, int target,int sum,int depth,vector<int>index,int maxDepth,int n)
	{
		//n表示的是当前遍历的起点
		//对于 2 3 6 7 
		//如果当前遍历的是3 那么下次也是从3开始  为了防止重复  不能跑到2上面去
		//深度遍历的算法好像太慢了
		if (sum > target)
		{
			return;//不用搜索了，因为已经太大了
		}
		if (sum == target)
		{
			vector<int>res;
			res = index;
			result.push_back(index);
			return;
		}
		int i, len = candidates.size();
		for (i = n; i < len; i++)
		{
			vector<int> temp = index;
			temp.push_back(candidates[i]);
			traverse(candidates, target, sum+candidates[i], depth + 1, temp, maxDepth,i);
		}
	}
	void preProcess(vector<int>& candidates)
	{
		vector<int>::iterator ps = candidates.begin(),pe = ps;
		while (ps < candidates.end())
		{
			while ((pe + 1) < candidates.end() && *(pe + 1) == *(ps))
			{
				candidates.erase(pe+1);
			}

			pe++;
			ps = pe;
		}
	}
};

int main()
{
	vector<int> candidate = { 2, 3, 6, 7 };
	Solution mine;
	int target = 7;
	vector<vector<int>> result;
	result = mine.combinationSum(candidate,target);
	int i, j;
	for (i = 0; i < result.size(); i++)
	{
		for (j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}