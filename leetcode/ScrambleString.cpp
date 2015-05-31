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
	bool isScramble(string s1, string s2) {

		bool result;
		result = traverse(s1, s2);
		return result;
	}

	bool traverse(string s1, string s2)
	{
		//动态规划也是一样的 开一个数组 dp[k][i][j]
		//第二维 i表示s1的起点是i,第三维j表示 s2的起点
		//第二维度表示后面k个是scramble的
		int len = s1.size();
		vector<vector<bool>>tmp(len, vector<bool>(len,false));
		vector<vector<vector<bool>>> dp(len,tmp);
		int i, j, k;
		for (i = 0; i < len; i++)
			for (j = 0; j < len; j++)
				dp[0][i][j] = (s1[i]==s2[j]); //如果相等的话他们自动scramble了
		for (k = 2; k <= len; k++)
		{
			//循环后面的长度
			for (i = len - k; i >= 0; i--)
			{
				for (j = len - k; j >= 0; j--)
				{
					bool res = false; 
					for (int m = 1; m < k&&!res; m++)
					{
						//只要r有一次为true的，那么就是true直接退出了
						//下面也是将字符分成两部分，m就是前半部分的个数
						bool part1 = dp[m - 1][i][j] && dp[k - m - 1][i + m][j+m];
						// i,j后面 m-1匹配 并且i+m 后面k-m-1个  与 j+m后面k-m-1个匹配
						bool part2 = dp[m - 1][i][j + k - m] && dp[k - m - 1][i + m][j];
						// i,j+k-m后面 m-1匹配 并且i+m 后面k-m-1个  与 j后面k-m-1个匹配

						//这一部分和递归是一样的
						res = part1 || part2;
					}
					dp[k-1][i][j] = res; //这个地方的第一维度下标应该 -1
				}
			}
		}
		return dp[len - 1][0][0];

	}

	//递归的方法的思路就比较简单了
	//毫无悬念地超时了，时间复杂读貌似是3^n
	bool recursive(string s1, string s2)
	{
		/*
		 * 把s1从下标 i分开， 前半部分是  0~i  后半部分是i ~len-i
		 * 所以有两种情况 s11 0~i s21 0~i 并且 s12 s22 scramble
		 * 或者 s11 s22  并且 s12 s21 scramble
		 */
		if (s1.size() != s2.size()) return false;
		if (s1 == s2) return true;

		string tmp1 = s1;
		string tmp2 = s2;
		sort(tmp1.begin(),tmp1.end());  //对于scramble必须满足s1和s2排序后相等
		sort(tmp2.begin(), tmp2.end()); 

		if (tmp1 != tmp2)  //加了排序比较后居然就过了
			return false;
		for (int isep = 1; isep < s1.size(); ++isep) 
		{
			//seporate s1 as [0,isep - 1],[isep, s1.size() - 1]
			string seg11 = s1.substr(0, isep);
			string seg12 = s1.substr(isep);

			//see if forward order is ok
			string seg21 = s2.substr(0, isep);
			string seg22 = s2.substr(isep);
			if (isScramble(seg11, seg21) && isScramble(seg12, seg22)) 
				return true;
			
			//see if reverse order is ok
			seg21 = s2.substr(s2.size() - isep); //往后的长度为isep那部分
			seg22 = s2.substr(0, s2.size() - isep); //
			if (isScramble(seg11, seg21) && isScramble(seg12, seg22)) return true;
			
		}
		return false;
	}
};

int main()
{
	string s1 ="rgtae" ;
	string s2 = "great";
	Solution mine;
	bool result;
	result = mine.isScramble(s1,s2);
	if (result)
		cout << "Is scramble!" << endl;
	else
		cout << "Not scramble!"<<endl;
	return 0;
}