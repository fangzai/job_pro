/*
time   :  2015-5-25
author :  ht
comment:  最多的交易次数是2，求最大的利润
*/
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

/*
 * 现在看来，我当时第一次做这个题的貌似还想复杂了
 * 第一种根本用不着那个求最大数组和

 * 这道题最朴素的思想就是在i这一点分界，左边交易最大和右边交易最大加起来
 * 然后最后扫一遍就可以了
 * 不过复杂度貌似会很高
 * 如果用动态规划的话，两边都维护一个数组就可以了
 */
class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int len = prices.size();
		if (len <= 0)
			return 0;
		vector<int>dpLeft(len,0);
		vector<int>dpRight(len,0);

		int i, j;
		int minPrice = prices[0];
		dpLeft[0] = 0;
		for (i = 1; i < len; i++)
		{
			minPrice = myMin(minPrice,prices[i]);
			dpLeft[i] = myMax(dpLeft[i-1],prices[i]-minPrice);
		}

		dpRight[len - 1] = 0;
		int maxPrice = prices[len-1];  //倒着推的时候就应该是最大price 减去当前prices了
		for (i = len-2; i >=0; i--)
		{
			maxPrice = myMax(maxPrice, prices[i]);
			dpRight[i] = myMax(dpRight[i+1], maxPrice-prices[i]);
		}

		int profit = 0;
		for (i = 0; i<len; i++)
		{
			int tmp = dpLeft[i] + dpRight[i];
			if (tmp > profit)
				profit = tmp;
		}

		return profit;
	}
	int myMin(int a,int b)
	{
		return a > b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{
	//vector<int>prices = { -2, 11, -4, 13, -5, -2 };
	vector<int>prices = { 1,2,4 };
	Solution mine;
	int result;
	result = mine.maxProfit(prices);
	cout << result << endl;
	return 0;
}