/*
time   :  2015-5-22
author :  ht
comment:  ip地址字符的分割
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<string> result;
	vector<bool>sign;
	vector<string> restoreIpAddresses(string s) {
		int len = s.size();
		if (len <= 3)
			return result;
		int start = 0,count =3;
		for (int i = 0; i < len; i++)
		{
			sign.push_back(false);
		}
		traverse(s,start,count);
		return result;
	}
	void traverse(string s, int index,int count)
	{
		// index 表示下一次切割的起始点
		// count 表示还剩余多少次切割
		// 深度优先遍历
		int len = s.length();
		string temp;
		int num;
		if (count == 0)
		{
			//剩下的字符全部是最后一个的
			temp = s.substr(index,len-index+1);
			if (temp[0] == '0'&&temp.size() > 1)
				return;  //切割点之间的字符串不能是以0开头且长度大于1的串
			num = str2int(temp);
			string str;
			if (num >= 0 && num <= 255)
			{
				int start = 0;
				for (int i = 0; i < len; i++)
				{
					if (sign[i])
					{
						str.append(s.substr(start,i-start+1));
						str.append(".");
						start = i + 1;
					}
				}
				str.append(s.substr(start,len-start));
				result.push_back(str);
			}
			else
			{
				return;
			}
		}
		else
		{
			//len - count)是因为后面必须保留 count个切割点
			for (int i = index; i < len - count; i++)
			{
				temp = s.substr(index,i-index+1);
				if (temp[0] == '0'&&temp.size() > 1)
					continue;
				num = str2int(temp);
				if (num >= 0 && num <= 255)
				{
					sign[i] = true;
					traverse(s,i+1,count-1);
					sign[i] = false;  //用完了之后就sign符号就要重置一下，否则容易影响下一次遍历
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
	//string str = "11112";
	//string str = "25525511135";
	string str = "010010";
	Solution mine;
	vector<string>result;
	result = mine.restoreIpAddresses(str);
	int i = 0;
	for (i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}