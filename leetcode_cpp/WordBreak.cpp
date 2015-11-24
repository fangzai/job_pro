/*
time   :  2015-5-20
author :  ht
comment:  实现word break
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		/*
		 * 网上推荐的都是用的dp规划的算法，不过仔细想想也是
		 * 先看第一个字符有没有被匹配，然后查看0-1字符是否匹配，然后一直到到s的最后
		 * 滚动计算结果
		 */
		unordered_set<string>::iterator it;
		string str;
		int i,index = 0;
		int nsize = s.size();
		bool *dp = new bool[nsize];
		
		for (i = 0; i < nsize; i++)
		{
			dp[i] = false;  //初始化一下
			
			dp[i] =(wordDict.find(s.substr(0, i + 1))==wordDict.end())?false:true;
			if (!dp[i])
			{
				//没匹配上，再分割0->i的字符，看看是否能够匹配上
				for (int j = 0; j < i; j++)
				{
					//从j处分割
					if (dp[j])
					{
						//匹配j+1下标开始，总共i-j个字符
						dp[i] = (wordDict.find(s.substr(j+1, i - j)) == wordDict.end()) ? false : true;
						if (dp[i])
						{
							break;
						}
					}
				}
			}
			else
			{
				//do nothing 因为这个已经匹配上了
			}
		}
		bool result = dp[nsize - 1];
		delete[] dp;
		return result;

	}
	bool wordBreak1(string s, unordered_set<string>& wordDict) {

		unordered_set<string>::iterator it;
		string temp,str,pre_str;
		int index = 0;
		str = s;
		//这个方法比较暴力，从s的第一个字符开始匹配，先找s[0]在wordDict的匹配
		//然后擦除，如果最终没有匹配的话，重置str，这个方法其实是丢弃了以前匹配的有用信息
		do
		{
			pre_str = str;
			for (it = wordDict.begin(); it != wordDict.end(); it++)
			{
				temp = *it;
				if (temp[0] == str[0])
				{
					index = str.find(*it);
					while (index >= 0)
					{
						str.erase(index,temp.size());
						if (str.empty())
						{
							return true;
						}
						index = s.find(temp);
					}
				}
			}
			if (pre_str == str)
				break;
		} while (!str.empty());
		return false;

	}
	bool find(string str1,string str2)
	{
		int index = str1.find(str2);
		cout << index << endl;
		return true;
	}
};

int main()
{
	//unordered_set<string>Dict = { "leet", "code" };
    unordered_set<string>Dict = { "gs", "s","dog"};
	string str = "dogs";
	string str1 = "teet";
	Solution me ;
	//me.find(str,str1);
	if (me.wordBreak(str, Dict))
	{
		cout << "Is empty now!"<<endl;
	}
	else
	{
		cout << "Not empty now!" << endl;
	}
	return 0;
}