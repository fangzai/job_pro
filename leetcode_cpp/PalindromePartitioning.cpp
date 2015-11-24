/*
time   :  2015-5-22
author :  ht
comment:  求将字符串分解成为回文串子集
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
	vector<vector<bool>> matrix;
	vector<bool>sign;
	vector<vector<string>>result;
	vector<vector<string>> partition(string s) {
		
		matrixPalindrome(s);//首先将matrix算出来

		int i = 0;
		for (i = 0; i < s.size(); i++)
		{
			sign.push_back(false);
		}

		traverse(s,0);  //从第一个字符开始
		return result;
	}
	void traverse(string s,int start)
	{
		if (start == s.size())
		{
			int i;
			//已经到最后面了  开始分割 字符
			string str;
			vector<string>temp;
			for (i = 0; i < s.size(); i++)
			{
				str += s[i];
				if (sign[i])
				{
					temp.push_back(str);
					str = "";//重置，记录下一次集合
				}
			}
			result.push_back(temp);
		}
		else
		{
			//否则的话继续递归
			int index = 0;
			for (index = start; index < s.size(); index++)
			{
				// start ->index  start之后的回文都找出来
				if (matrix[start][index] == true)
				{
					sign[index] = 1;
					traverse(s, index + 1);
					sign[index] = 0;//出来之后要重置  否则会影响下一次迭代
				}
				else
				{
					//do nothing跳过，sign标记
				}
			}
		}

	}
	vector<vector<bool>> matrixPalindrome(string s) {

		int	 n = s.length();
		vector<vector<bool>> dp;
		//为基准情况赋值
		int i, j;
		for (i = 0; i < n; i++)
		{
			vector<bool> temp;
			for (j = 0; j < n; j++)
			{
				temp.push_back(false);
			}
			dp.push_back(temp);
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
	string str= "aab";
	vector<vector<string>> result;
	result = mine.partition(str);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}