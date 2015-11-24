/*
time   :  2015-5-27
author :  ht
comment:  给定S串和子串T，求T在S排列的次数
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	int result = 0;
	int numDistinct(string s, string t) {
		//traverse(s,0,t,0);
		int len1 = s.length();
		int len2 = t.length();
		if (len1 == 0 || len2 == 0)
			return 0;
		if (len1 < len2)
			return 0;
		return traverse1(s,t);
	}
	int traverse1(string s, string t)
	{
		//动态规划算法
		//开一个数组dp[i][j]表示  s串的前i个，和t串的前j个匹配的数量
		//关于转移方程
		//如果s[i]==t[j]那么dp[i][j]有两种选择方法，一种是s[i]和s[j]匹配，选择方法是dp[i-1][j-1]
		//                      另外一种是 s[i]和s[j]不匹配，选择方法是dp[i-1]dp[j] 也就是不要s[i]
		//如果s[i]!=t[j] 那么只有一种方案，dp[i-1][j]的数量
		// dp[0][0] =1, dp[i][0] =1  //任何一个字符串变成空串 只有一种方法
		int len1 = s.length();
		int len2 = t.length();
		vector<int>tmp(len2+1,0);
		vector<vector<int>>dp(len1+1,tmp);
		int i, j;
		dp[0][0] = 1;
		//任何一个字符串变成空串 只有一种方法
		for (i = 1; i <= len1; i++)
			dp[i][0] = 1;

		for (i = 1; i <= len1; i++)
		{
			for (j = 1; j <= len2; j++)
			{
				if (s[i-1] == t[j-1])//if (s[i] == t[j] 不对 因为矩阵扩展了一个位
				{
					dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];
					//dp[i-1][j-1]用s[i]==t[j]
					//dp[i-1][j] 不用s[i]==t[j]
				}
				else
				{
					//dp[i-1][j] 不用s[i]==t[j]
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[len1][len2];

	}
	void traverse(string s,int index1, string t,int index2)
	{
		//唉，不出所料低超时了
		int len1 = s.length();
		int len2 = t.length();
		if ((index2 + 1) == len2)
		{
			result++;return;
		}
		if ((index1 + 1) == len1)
			return;
		//上面是退出条件
		int j = index2;
		for (int i = index1; i < len1; i++)
		{
			if (s[i] == t[j])
			{
				traverse(s, i + 1, t, j + 1);
			}
		}
	}
};

int main()
{
	string str1, str2;
	str1 = "b";
	str2 = "a";
	Solution mine;
	int result;
	result = mine.numDistinct(str1,str2);
	cout << result << endl;
	return 0;
}