/*
time   :  2015-5-24
author :  ht
comment:  找出所有出现过两次以上的10长度字符串
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
	vector<string>result;
	map<string, int> myMap;
	map<unsigned int, int> textMap;
	vector<string> findRepeatedDnaSequences(string s) {
		traverse1(s);
		return result;
	}
	void traverse(string s)
	{
		//这个方法太暴力，超时了
		//貌似是因为内存不够的原因
		//网上就有牛逼闪闪的变换方法
		//那个map的key里面不存string，直接存一个数字，这样就很节省了
		int count = 10;
		int len;
		len = s.length();
		int i,index;
		string temp;
		for (i = 0; i < len - count; i++)
		{
			temp = s.substr(i,count);
			index = s.rfind(temp);
			if (index > i)
			{
				//说明有重复
				if (!myMap.count(temp))
				{
					myMap.insert(pair<string,int>(temp,i));
					result.push_back(temp);
				}
			}
		}

	}
	unsigned int ten2Num(string str)
	{
		//A C G T  0 1 2 3
		int i = 0;
		int count = 10;
		unsigned int num = 0;
		unsigned int a;
		for (i = 0; i < count; i++)
		{
			switch (str[i])
			{
			case 'A': a = 0;
				break;
			case 'C': a = 1;
				break;
			case 'G': a = 2;
				break;
			case 'T': a = 3;
				break;
			default:
				break;
			}
			num *= 10;
			num += a;
		}

		return num;
	}
	void traverse1(string s)
	{
		//关键是如何把10个字符串压缩成一个整数呢？？？
		//同样的思想，我把key变成unsigned int来存，可是时间上还是太慢了~~
		//难道真的得用位操作才行？？？？
		int count = 10;
		int len;
		len = s.length();
		int i, index, exist;
		string temp;
		unsigned int mark = 0;
		for (i = 0; i < len - count+1; i++)
		{
			temp = s.substr(i, count);
			mark = ten2Num(temp);
			//没有这个东西
			if (!textMap.count(mark))
			{
				textMap.insert(pair<unsigned int, int>(mark, i));
				textMap[mark]=1;
			}
			else
			{
				if(textMap[mark]==1)
					result.push_back(temp);
				textMap[mark]++;
				
			}
		}
	}
	unsigned int line(char s)
	{
		unsigned int a = 0;
		switch (s)
		{
		case 'A': a = 0;
			break;
		case 'C': a = 1;
			break;
		case 'G': a = 2;
			break;
		case 'T': a = 3;
			break;
		default:
			break;
		}
	}
	void traverse2(string s)
	{
		//关键是如何把10个字符串压缩成一个整数呢？？？
		int count = 10;
		int len;
		len = s.length();
		int i, index, exist;
		string temp;
		unsigned int mark = 0, preMark = 0;;
		for (i = 0; i < len - count + 1; i++)
		{
			temp = s.substr(i, count);
			//index = s.rfind(temp);
			if (i == 0)
			{
				mark = ten2Num(temp);
			}
			else
			{
				unsigned int a = 0, b = 0;;
				a = line(s[i-1]);
				b = line(s[i+9]);
				mark = 10 * (preMark - a*pow(10, 9)) + b;
			}
			
			//没有这个东西
			if (!textMap.count(mark))
			{
				textMap.insert(pair<unsigned int, int>(mark, i));
				textMap[mark] = 1;
			}
			else
			{
				if (textMap[mark] == 1)
					result.push_back(temp);
				textMap[mark]++;

			}
			preMark = mark;
		}
	}
};

int main()
{
	string DNApiece = "AAAAAAAAAAAA";
	vector<string>result;
	Solution mine;
	result = mine.findRepeatedDnaSequences(DNApiece);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}