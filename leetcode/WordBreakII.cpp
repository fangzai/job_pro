/*
time   :  2015-5-29
author :  ht
comment:  word break的升级版，需要将所有的分割情况输出出来
*/
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	vector<string> result;
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		/*
		* 网上推荐的都是用的dp规划的算法，不过仔细想想也是
		* 先看第一个字符有没有被匹配，然后查看0-1字符是否匹配，然后一直到到s的最后
		* 滚动计算结果
		*/
		unordered_set<string>::iterator it;
		string str;
		int i, index = 0;
		int nsize = s.size();
		vector < bool>dp(nsize, false);
		vector<vector<bool>> mark(nsize, dp); //mark[i][j]表示 i->j下标的字符串能否分割
		for (i = 0; i < nsize; i++)
		{
			dp[i] = false;  //初始化一下

			dp[i] = (wordDict.find(s.substr(0, i + 1)) == wordDict.end()) ? false : true;
			if (dp[i])
				mark[0][i] = true;
			//相当于把前面遍历过的在查一遍，看能偶从j+1->i分割
			for (int j = 0; j < i; j++)
			{
				//从j处分割
				if (dp[j])
				{
					//匹配j+1下标开始，总共i-j个字符
					bool part = (wordDict.find(s.substr(j + 1, i - j)) == wordDict.end()) ? false : true;
					if (part)
					{
						dp[i] = part;
						mark[j + 1][i] = true;
						//break;
					}
				}
			}
		}
		if (!dp[nsize - 1])
			return result; //你大爷的 测试集合居然给部分分割的，害的我这里没有判定后面进入死循环了
		traverse(mark, s);
		return result;
	}
	void traverse(vector<vector<bool>>mark, string str)
	{
		int i = 0, j = 0;
		int index = 0;
		string res;
		recursive(mark, str, 0, res); //递归进行深度优先遍历得到结果

	}
	void recursive(vector<vector<bool>>mark, string str, int start, string res)
	{
		int i;
		int len = mark.size();
		if (len == start)
		{
			if (res[res.size() - 1] == ' ')
				res.erase(res.end() - 1);
			result.push_back(res);
			return;
		}
		for (i = start; i < len; i++)
		{
			if (mark[start][i])
			{
				string tmp = res;
				tmp.append(str.substr(start, i - start + 1));
				tmp.append(" ");
				recursive(mark, str, i + 1, tmp);
			}
		}
	}
};

int main()
{
	Solution mine;
	string str = "aaaaaaa";
	unordered_set<string> wordDict = { "aaaa", "aa", "a" };
	vector<string> result;
	result = mine.wordBreak(str,wordDict);
	for (int i= 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}