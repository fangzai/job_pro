/*
time   :  2015-5-30
author :  ht
comment:  求k次最大连续数组和
*/
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;


class Solution1 {
	//动态规划的方法
public:
	/*
	 *其实可以求至少k次交易的最大利润。
	 *我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易
	 *在最后一天卖出的最大利润，此为局部最优。
	 *
	 *然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优

	 *
	 * local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)

     * global[i][j] = max(local[i][j], global[i - 1][j])，

     * 其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，
	 * 和前一天的局部最优加上差值后相比，两者之中取较大值，而全局最优比较局部最优和前一天的全局最优。
	 */
	int maxProfit(int k, vector<int> &prices) 
	{
		if (prices.empty() || k == 0)
			return 0;

		if (k >= prices.size())  //次数很多的样子
			return solveMaxProfit(prices);

		vector<int> global(k + 1, 0);
		vector<int> local(k + 1, 0);

		for (int i = 1; i < prices.size(); i++) 
		{
			int diff = prices[i] - prices[i - 1];
			for (int j = k; j >= 1; j--)
			{
				local[j] = myMax(local[j] + diff, global[j - 1] + myMax(diff, 0));
				global[j] = myMax(global[j], local[j]);
			}
		}

		return global[k];
	}
	int myMin(int a, int b)
	{
		return a > b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}
private:
	int solveMaxProfit(vector<int> &prices)
	{
		//这个是解可以交易任意次的，也就是II那一道题的
		int res = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			int diff = prices[i] - prices[i - 1];
			if (diff > 0)
				res += diff;
		}
		return res;
	}
};

class Solution {
public:
	int result = INT_MIN;

	//我下面的算法比较暴力，递归，超时，毫无悬念地~~~
	int maxProfit(int k, vector<int>& prices) {
		if (k <= 0)
			return 0;
		int currentProfit = 0;
		int depth = 0;
		int start = 0;
		recursive(prices, k, start, depth, currentProfit);
		return result;
	}
	void recursive(vector<int> prices,int k,int start,int depth,int accumulation)
	{
		int len = prices.size();
		if (k == (depth+1))
		{
			//退出条件
			int currentProfit = profit(prices,start, len - 1);
			currentProfit += accumulation;
			result = myMax(currentProfit,result);
		}
		else
		{
			int i;
			int currentProfit;
			for (i = start; i < len-(k - depth); i++)
			{
				currentProfit = profit(prices, start, i);
				currentProfit += accumulation;
				recursive(prices, k, i + 1, depth + 1, currentProfit);
			}
		}
	}
	int profit(vector<int> prices,int start,int end)
	{
		int maxPrice, minPrice;
		maxPrice = prices[start];
		minPrice = prices[start];
		int currentProfit = 0;
		for (int i = start; i <= end; i++)
		{
			maxPrice = myMax(maxPrice, prices[i]);
			minPrice = myMin(minPrice, prices[i]);
		}
		currentProfit = maxPrice - minPrice;
		return currentProfit;
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
	return 0;
}