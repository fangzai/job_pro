/*
time   :  2015-5-23
author :  ht
comment:  搜索满足解码条件的方法数量
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	vector<bool>sign;  //用于标记该点是否可以切割
	int result;

	int numDecodings(string s) {
		/*
		 * 用动态规划的方式（ps我递归的方式也是这个意思为什么会超时呢！！）
		 * ways[i]表示以当前字符结尾的解码的方式
		 * 如何例子  122
		 * ways[0] =1
		 * ways[1] = ways[0]+ways[-1] ,其实这个地方的way[-1]表示的就是当前字符和前一个字符组合得到次数
		 * ways[2] = ways[1]+ways[0]
		 * s[i-1]s[i]必须要要在10~~26之间，写一个check函数就可以了
		 * 如果条件满足的话就有
		 *  ways[i] = ways[i-1]+ways[i-2]  //当然需要考虑当前位置恰好是0的情况
		 * 比如对于101
		 * 分割方式只有1种就是10 和1
		 */
		int len = s.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return check(s[0]);
		
		vector<int>ways(len,0);
		ways[0] = check(s[0]);
		ways[1] = (check(s[0]) & check(s[1])) + check(s[0], s[1]);
		int i = 0;
		for (i = 2; i < len; i++)
		{
			if (check(s[i]))
				ways[i] += ways[i - 1];//只解密一个字符
			if (check(s[i-1], s[i]))  //if (check(s[i], s[i - 1]))  开始的时候高低位搞错了
				ways[i] += ways[i - 2];
		}
		return ways[len - 1];
	}

	int check(char one)
	{
		return one == '0' ? 0 : 1;
	}
	int check(char one, char two)
	{
		return ((one == '1') || ((one == '2') && (two <= '6'))) ? 1 : 0;
	}
	int numDecodings1(string s) {
		//用深度递归的方式会超时
		if (s.length() == 0)
			return 0;
		int start = 0;
		result = 0; 
		vector<bool>tmp(s.size(),false);
		sign = tmp;
		traverse(s,start);

		return result;
	}
	void traverse(string s,int index)
	{
		//表示当前分割的一个起点
		int len = s.size();
		if (index == len)
		{
			//到了字符串的最末端位置了//也就是退出条件
			result++;
		}
		else
		{
			int i;
			string str;
			int num,range;
			for (i = index; i < len; i++)
			{
				range = i - index + 1;
				if (range >= 3)
					return;

				str = s.substr(index,range);
				if (str[0] == '0')
					return;
				if (range >= 2)
				{
					num = str[0] - '0';
					if (num >= 3)
						return;
				}
				num = str2int(str);
				if (num >= 1 && num <= 26)
				{
					sign[i] = true;
					traverse(s,i+1);
					sign[i] = false;
				}
			}
		}
	}
	int str2int(string s)
	{
		int len = s.size();
		int res = 0;
		for (int i = 0; i < len; i++)
		{
			res *= 10;
			res += s[i] - '0';
		}
		return res;
	}
};

int main()
{
	string code = "101";
	Solution mine;
	int result;
	result = mine.numDecodings(code);
	cout << result << endl;

	result = mine.numDecodings1(code);
	cout << result << endl;
	return 0;
}