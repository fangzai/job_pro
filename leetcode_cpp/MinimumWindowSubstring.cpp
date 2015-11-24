/*
time   :  2015-5-26
author :  ht
comment:  母串S，待匹配的子串T，求解S中的最小窗口能够包含T的所有字符
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

/*
 * 窗口滑动的问题，和ex209  极为相似
 * 可以理解为一旦得到了当前匹配的字符串，左边的指针右移
 * 接着判断是否还能找到，如果能找到继续start指针滑动
 * 如果不能找到end指针后移
 * 
 * 在ex209中也是窗口滑动，window之间不断求和，一旦大于给定值，start开始收缩
 */
class Solution {
public:
	int range = 128;
	string minWindow(string s, string t) {

		vector<int>pattern(range,0);  //这个用来存放t里面出现的频率
		vector<int>text(range, 0);

		int i;
		for (i = 0; i < t.size(); i++)
			pattern[t[i]]++;
		int start = 0, end = 0;
		int minStart = 0, minEnd = 0;
		int minLength = s.length();
		
		bool mark = false;  //表示是否有搜索到这样的窗口

		text[s[end]]++;  //第一个元素加进去
		while (end < s.size())
		{
			if (compare(text, pattern))
			{
				//找到一个窗口了
				int currentLen = end - start + 1;
				if (minLength >= currentLen)
				{
					mark = true;
					minLength = currentLen;
					minEnd = end;
					minStart = start;
				}
				if (start < end)
				{
					//在保证start指针是在end指针之前，可以收缩
					//否则就要end往右扩展
					start++;
					text[s[start - 1]]--; //收缩  左边的窗口后移
				}
				else
				{
					end++;  //严格来说并不会走到这一步
					if (end<s.size())
						text[s[end]]++;  //右边的窗口后移
				}

			}
			else
			{
				end++;   //右边的窗口后移
				if (end<s.size())
					text[s[end]]++;
			}
		}
		string res;
		if (mark)
		{
			res= s.substr(minStart,minEnd-minStart+1);
			return res;
		}
		else
		{
			return res;//没有找到返回空
		}
	}
	bool compare(vector<int>text,vector<int>pattern)
	{
		//大小都是设置的128
		int i;
		for (i = 0; i < range; i++)
		{
			if (text[i] < pattern[i])
				return false;
		}
		return true;
	}
};

int main()
{
	string S = "ADOBECODEBANC";
	string T = "ABC";
	Solution mine;
	string result;
	result = mine.minWindow(S,T);
	cout << result << endl;
	return 0;
}