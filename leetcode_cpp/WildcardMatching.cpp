/*
time   :  2015-5-26
author :  ht
comment:  字符串匹配的问题
          ?  可以匹配任意单个字符
          *  可以匹配任意序列的字符，包括空                
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int len1 = s.length();
		int len2 = p.length();
		if (len1 == 0 && len2 != 0)
			return false;
		if (len2 == 0 && len1 != 0)
			return false;
		if (len1 == len2&&len1 == 0)
			return true;

		bool result;
		string newP = removeRepeat(p);
		result = traverse(s,0,newP,0);
		return result;
	}
	string removeRepeat(string &str)
	{
		int ps = 0;
		int len = str.length();
		string res;
		int i = 0;
		while (i < len)
		{
			if (str[i] != '*')
			{
				res.push_back(str[i]);
				i++;
			}
			else
			{
				res.push_back(str[i]);
				while ((i+1)<len&&str[i + 1] == '*')
					i++;
				i++;
				
			}
		}
		return res;
	}
	bool traverse(string a,int index,string b,int bIndex)
	{
		//应该适用深度优先搜索匹配
		//爆栈，直接给超时了
		int len1 = a.length();
		int len2 = b.length();
		if (len1 == index)
		{
			if (len2 == bIndex)
			{
				return true;
			}
			return false;
		}
		if (len2 == bIndex)
		{
			if (len1 == index)
			{
				return true;
			}
			return false;
		}
			
		if (b[bIndex] == '?')
		{
			return traverse(a, index + 1, b, bIndex + 1);
		}
		else if (b[bIndex] == '*')
		{
			if (bIndex == (len2 - 1))
			{
				return true;
			}
			else
			{
				bool result = false;
				for (int i = index; i < len1; i++)
				{
					result = traverse(a, i, b, bIndex + 1);
					if (result)
						return true;
				}
				return result;
			}
		}
		else
		{
			bool result = false;
			if (a[index] == b[bIndex])
			{
				result = traverse(a,index+1,b,bIndex+1);
				return result;
			}
			else
			{
				return false;
			}
		}
	}
};

class Solution1 {
	/*
	 * 根据网上迭代版本改的
	 * http://www.acmerblog.com/leetcode-solution-wildcard-matching-6318.html
	 * http://blog.csdn.net/tingmei/article/details/8049926
	 */
public:
	bool isMatch(string s, string p)
	{
		int i, j;
		int len1 = s.length();
		int len2 = p.length();

		bool star = false;
		int tmpi=0, tmpj=0;
		for (i = 0, j = 0; i < len1; i++, j++)
		{
			switch (p[j])
			{
			case '?': break;  //？能够匹配任何字符
			case '*': 
				star = true;  //忽略 *号
				tmpi = i;
				tmpj = j;
				do
				{
					tmpj++;//跳过重复的 *号
				} while (p[tmpj]=='*');
				if (j == len2 )
					return true;  //如果后面没有字符了的话，直接全部匹配
				i = tmpi - 1; //记录上个时刻的位置，也就是，下一刻开始迭代的位置
				j = tmpj - 1; //这里减掉1是为了抵消后面一次循环的自增1
				break;
			default:
				if (s[i] != p[j])
				{
					if (!star)
						return false;  //前面如果没有*号的话直接就退出了
					tmpi++;
					i = tmpi - 1;   //这里减掉1是为了抵消上面一次循环的自增1
					j = tmpj - 1;
				}
				break;
			}
		}
		while (p[j] == '*')
			j++;
		if (j == len2)
			return true;  //如果后面灭有字符了的话，直接全部匹配
		else
		{
			return false;
		}
	}
};

// LeetCode, Wildcard Matching
// 迭代版，时间复杂度O(n*m)，空间复杂度O(1)
class Solution2 {
public:
	bool isMatch(const char *s, const char *p) {
		bool star = false;
		const char *str, *ptr;
		for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
			switch (*ptr) {
			case '?':
				break;
			case '*':
				star = true;
				s = str, p = ptr;
				while (*p == '*') p++;  //skip continuous '*'
				if (*p == '\0') return true;
				str = s - 1;
				ptr = p - 1;
				break;
			default:
				if (*str != *ptr) {
					// 如果前面没有'*'，则匹配不成功
					if (!star) return false;
					s++;
					str = s - 1;
					ptr = p - 1;
				}
			}
		}
		while (*ptr == '*') ptr++;
		return (*ptr == '\0');
	}
};


int main()
{
	string str1 = "abc";
	//string str2 = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
	string str2 = "a*c";
	Solution1 mine;
	bool result;
	result = mine.isMatch(str1,str2);
	if (result)
		cout << "Is matched!" << endl;
	else
		cout << "Not matched!" << endl;
	return 0;
}