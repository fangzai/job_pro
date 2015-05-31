/*
time   :  2015-5-23
author :  ht
comment:  两个用string表示的数字相乘，输出结果到string里面
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*  先把string相加的写出来
 *  再把string和char相乘的写出来
 */
class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.length();
		int len2 = num2.length();
		if (len1 == 0 || len2 == 0)
			return 0;
		//遍历第二个字符串
		int i;
		string sum = "",a,b;
		for (i = 0; i < len2; i++)
		{
			a = singleMulti(num1,num2[i]);
			sum.push_back('0');
			sum = plus(sum,a);
		}
		sum = removeZeros(sum);
		return sum;
	}
	string singleMulti(string num,char s)
	{
		int len = num.size();
		string res;
		int a, b,number =0,current =0;
		int i;
		for (i = len-1; i >=0; i--)
		{
			a = num[i]-'0';
			b = s - '0';
			current = a*b+number;
			number = current / 10;
			current = current % 10;
			res.push_back(current + '0');
		}
		if (number>0)
			res.push_back(number + '0');
		reverse(res.begin(), res.end());
		res = removeZeros(res);
		return res;
	}
	string removeZeros(string res)
	{
		int len = res.length();

		int i = 0;
		while ((len>1) && res[i] == '0')
		{
			//len = res.length();
			res = res.substr(1, len - 1);
			len = res.length();
		}
		return res;
	}
	string plus(string num1,string num2)
	{
		//这里假设num1是较长的字符串
		int len1 = num1.size();
		int len2 = num2.size();
		string tmp;
		if (len1 <= len2)
		{
			tmp = num1;
			num1 = num2;
			num2 = tmp;
		}
		//这个时候num1已经是较长的字符串了
		len1 = num1.size();
		len2 = num2.size();
		int i, j;
		i = len1 - 1;
		j = len2 - 1;
		int a, b, number = 0, current = 0;;
		string res;
		while (i >= 0)
		{
			a = num1[i] - '0';
			i--;
			if (j >= 0)
			{
				b = num2[j] - '0';
				j--;
			}
			else
			{
				b = 0;
			}
			current = a + b + number;
			number = current / 10;
			current = current % 10;
			res.push_back(current + '0');
		}
		if (number > 0)
		{
			res.push_back(number+'0');
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution mine;
	string num1 = "19";
	string num2 = "10";
	string result;
	//result = mine.plus(num1,num2);
	//result = mine.singleMulti(num1, num2[0]);
	result = mine.multiply(num1,num2);
	cout << result << endl;
	return 0;
}