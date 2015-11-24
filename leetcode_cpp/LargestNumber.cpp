/*
time   :  2015-5-22
author :  ht
comment:  数组内数字排序组成最大数字
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
	int num;
	string str;
};

bool cmp(Node a,Node b)
{
	//两个串拼接起来比较，这个时候就没有谁长谁短的问题了
	string str1 = a.str+b.str;
	string str2 = b.str+a.str;
	int len1 = str1.size();
	int len2 = str2.size();
	int i;
	
	int num1, num2;
	for (i = 0; i < len1&&i < len2; i++)
	{
		num1 = str1[i] - '0';
		num2 = str2[i] - '0';
		if (num1 == num2)
		{
			continue;
		}
		return num1 > num2;
	}
	return num1 > num2;
}
class Solution {
public:
	vector<Node> array;
	string largestNumber(vector<int>& nums) {
		string str;
		
		preProcess(nums);
		sort(array.begin(), array.end(),cmp);
		int i, len = nums.size();
		int index = 0;
		while (index<len&&array[index].num == 0)
		{
			index++;
		}
		//考虑都是0的特殊情况
		if (len!=0&&index == len)
		{
			str = "0";
			return str;
		}
		for (i = index; i <len; i++)
		{
			str.append(array[i].str);
			//cout << array[i].str << endl;
		}
		return str;
	}
	void preProcess(vector<int>nums)
	{
		int len = nums.size();
		Node temp;
		for (int i = 0; i < len; i++)
		{
			temp.num = nums[i];
			temp.str = num2str(nums[i]);
			array.push_back(temp);
		}
	}
	string num2str(int num)
	{
		//这里的num是大于0的，所以不用考虑负号
		string str;
		int tmp;
		while (num >= 10)
		{
			tmp = num % 10;
			str.push_back(tmp+'0');
			num /= 10;
		}
		str.push_back(num+'0');
		reverse(str.begin(),str.end());
		return str;
	}
};

int main()
{
	int num = 298;
	Solution mine;
	string res;

	//vector<int>nums = { 3, 30, 34, 5, 9 };
	//vector<int>nums = { 121, 12 };
	vector<int>nums = { 12, 12 };
	res = mine.largestNumber(nums);
	//res = mine.num2str(num);
	cout << res << endl;
	return 0;
}