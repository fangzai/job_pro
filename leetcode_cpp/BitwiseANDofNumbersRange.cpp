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

/*
 * 解这道题目需要先观察一下m->n这些数字的构造
 * 我们可以看到如果2^n的话，只有第n+1位才是1，
 * 如果m->n之间有一个刚好是2对数的话，全部求and之后肯定是0
 * 比如 4 100 和 8 1000,他们的对数值差1不在一个范围内
 * 这样的话，我们就需要做一个循环 对m,n一直求对数，看看他们的k1和k2是否是相等的，如果相等的话
 * 继续往后push 保存2^k1，这个后面要加起来的
 * 否则一旦遇到m或者n变成0了的话，不用算了，肯定都是0了
 * 这里我自己写了一个对数函数和一个指数函数，其实是没有必要的
 * 要是自己写的话可能速度更快，落到c程序的区域里面去了。
 */
class Solution {
public:
	vector<int>array;
	int rangeBitwiseAnd(int m, int n) {
		int k1,k2;
		if (m == 0 || n == 0)
			return 0;
		k1 = myLog(m);
		k2 = myLog(n);
		
		int low = m,high = n;
		// 当k1 == k2的时候才有结果
		while (k2 == k1)
		{
			array.push_back(k1);
			int tmp = myExp(k1);
			low -= tmp;
			high -= tmp;

			//任意一个数为0的话就直接退出了，不用算了
			if (low == 0 || high == 0)
				break;

			k1 = myLog(low);
			k2 = myLog(high);
		}
		int len = array.size();
		if (len <= 0)
		{
			return 0;
		}
		else
		{
			int sum = 0;
			for (int i = 0; i < len; i++)
			{
				sum += myExp(array[i]);
			}
			return sum;
		}
	}
	int myLog(int n)
	{
		int i = 0;
		while (n >= 2)
		{
			n = n / 2;
			i++;
		}
		return i;
	}
	int myExp(int n)
	{
		int i = 0;
		int num = 1;
		for (i = 0; i < n; i++)
		{
			num *= 2;
		}
		
		return num;
	}
};

int main()
{
	//int m = 5,n =8;
	int m = 4, n = 8;
	Solution mine;
	int result;
	//result = mine.myLog(8);
	result = mine.rangeBitwiseAnd(m,n);
	cout << result << endl;
	return 0;
}