/*
time   :  2015-5-21
author :  ht
comment:  求大回文字符的长度
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		//http://blog.csdn.net/hopeztm/article/details/7932245
		int len = s.size();
		if (len <= 1)
			return s;

		string T = preProcess(s);
		//cout << T << endl;

		len = T.size();
		int C = 0, R = 0; //就是那几个恶心的值
		vector<int>	P(len,0);


		int i_mirror = 0;
		int i, j;
		for (i = 0; i < len; i++)
			cout << P[i] << " ";
		for (i = 1; i < len - 1; i++)
		{
			i_mirror = 2 * C - i;//计算i'这个东西
			
			if (R > i)
			{
				P[i] = myMin(R-i,P[i_mirror]);
			}
			else
			{
				P[i] = 0;
			}
			//扩充在i位置后面的P[i]

			while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			{
				P[i] =P[i] +1;  //因为是对称的
				//cout << P[i] << endl;
			}
			if (i + P[i] > R)  //超过了R，就需要更新C和R
			{
				C = i;
				R = i + P[i];
			}
		}
		int maxLen = 0;
		int centerIndex = 0;
		for (i = 0; i < len; i++)
		{
			if (P[i]>maxLen)
			{
				maxLen = P[i];
				centerIndex = i;
			}
		}
		string  result = s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
		return result;
	}
	int myMin(int a,int b)
	{
		return a > b ? b : a;
	}
	string preProcess(string s)
	{
		int n = s.length();
		if (n == 0) return "";
		string ret="^";  //这样就不用进行边界检查了
		for (int i = 0; i < n; i++)
		{
			ret.append("#" + s.substr(i, 1));
		}

		ret.append("#$"); //这样就不用进行边界检查了
		return ret;
	}
	string LCS(string s1, string s2)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		vector<int>mark(len2 + 1, 0);
		int i, j;
		//for (i = 0; i < mark.size(); i++)
		//	cout << mark[i] << " ";
		//cout << endl;

		int max = 0;
		int pe = 0;
		for (i = 0; i < len1; i++)
		{
			for (j = len2; j > 0; j--)
			{
				if (s1[i] == s2[j - 1])
				{
					mark[j] = mark[j - 1] + 1;
				}
				else
				{
					mark[j] = 0;
				}
				if (mark[j] > max)
				{
					max = mark[j];
					pe = i;
				}
			}
		}
		string result;
		i = 0;
		j = pe - max + 1;
		result = s1.substr(j,max);
		return result;
	}
	string longestPalindrome1(string s)
	{
		string s1 = s;
		reverse(s.begin(), s.end());
		string test = LCS(s1,s);
		return test;
	}
};

int main()
{
	string str = "a";
	//string str = "h";
	Solution mine;
	//string result = mine.longestPalindrome(str);
	//cout << result << endl;

	string str2 = str;

	string test = mine.longestPalindrome1(str);
	cout << test << endl;
	return 0;
}