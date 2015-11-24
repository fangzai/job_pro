/*
time   :  2015-5-22
author :  ht
comment:  求将字符串分解成为回文串子集,并且求最小裁剪
		  ex131的升级版
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

int myMin(int a, int b)
{
	return a > b ? b : a;
}
class Solution {
public:
	vector<vector<bool>> matrix;
	vector<vector<string>>result;
	int minCut(string s) {
		
		matrixPalindrome(s);//首先将matrix算出来
		vector<int>cut(s.size()+1,0); //全部初始化为0
		//cut[i]表示，从i到string的末尾需要切割的刀数

		int i, j;
		int len = s.size();
		for (i = len - 1; i >= 0; i--)
		{
			cut[i] = len - i;  //开始的时候假设都是每一个字母都分割
			//外循环从后往前更新
			for (j = i; j < len; j++)
			{
				if (matrix[i][j])
				{
					//i->j是可以切割的，那么 cut[i] 就等于原来的和 cut[j+1]+1的较小值
					cut[i] = myMin(cut[j + 1] + 1,cut[i]);
					//内循环从前往后更新
				}
			}
		}
		//最后一个字符不需要切割，所以减去1

		return cut[0]-1;
	}
	vector<vector<bool>> matrixPalindrome(string s) {

		int	 n = s.length();
		vector<vector<bool>> dp;
		//为基准情况赋值
		int i, j;
		vector<bool> temp(n,false);
		for (i = 0; i < n; i++)
		{
			dp.push_back(temp);
			//最好不要做两个大循环容易超时
		}

		int startPos = 0;
		int max = 1;
		for (i = 0; i < n; ++i)
		{
			dp[i][i] = true;
			if (i + 1 < n)
			{
				if (s[i] == s[i + 1])
				{
					dp[i][i + 1] = true;
					startPos = i;
					max = 2;
				}
				else dp[i][i + 1] = false;
			}
		}

		//动规求解,前面已求len = 1, len = 2的情况
		int len;
		for (len = 3; len <= n; ++len)
		{
			for (i = 0; i < n - len + 1; ++i)
			{
				j = i + len - 1;

				if (dp[i + 1][j - 1] && s[i] == s[j])
				{
					dp[i][j] = true;
					int curLen = j - i + 1;
					if (curLen > max)
					{
						startPos = i;
						max = curLen;
					}
				}
				else dp[i][j] = false;

			}
		}
		matrix = dp;

		return dp;
	}
};

int main()
{
	Solution mine;
	string str = "aacb";
	int result;
	result = mine.minCut(str);

	cout << result <<endl;
	return 0;
}