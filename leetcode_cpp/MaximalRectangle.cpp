/*
time   :  2015-5-26
author :  ht
comment:  求解最大能够包围1字符的矩形
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int result = traverse(matrix);
		return result;
	}
	int maximalRectangle2(vector<vector<char>>& matrix)
	{
		//第第二种思路开一个矩阵dp[i][j]，表示在第j列，i标号前面连续的1的个数
		//其实和上面那个n^3的思路几乎是一样的
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int i, j;
		vector<int>tmp(n, 0);
		vector<vector<int>>dp(m, tmp);
		for (j = 0; j < n; j++)
			dp[0][j] = (matrix[0][j] == '1') ? 1 : 0; //计算第一列
		for (i = 1; i < m; i++)
			for (j = 0; j < n; j++)
				dp[i][j] = (matrix[i][j] == '1') ? dp[i-1][j] + 1 : 0;  //后面的公式递推

		int maxRec = 0,tmpRec;
		for (i = 0; i < m; i++)
		{
			//遍历m行
			tmpRec = largestRec(dp[i]);
			maxRec = myMax(maxRec,tmpRec);
		}

		return maxRec;

	}
	int largestRec(vector<int>& height)
	{
		//ex84中histogram求最大面积的函数
		height.push_back(0);//在height后面添加一个0元素，作为边界判定
		stack<int> myStack;
		int i = 0;
		int maxArea = 0;
		int len = height.size();
		while (i < len)
		{
			if (myStack.empty() || (height[myStack.top()] <= height[i]))
			{
				//如果第一次入栈，或者后面弹栈后的top小于等于i指向元素
				//那么就不必再弹栈了
				myStack.push(i);
				i++;
			}
			else
			{
				//开始把较大元素弹出来
				int index = myStack.top();
				myStack.pop(); //取出栈顶
				//计算面积
				int width = 0;
				if (myStack.empty())
				{
					width = i;
				}
				else
				{
					width = i - myStack.top() - 1;
				}
				maxArea = myMax(maxArea, height[index] * width);
			}
		}
		return maxArea;

	}
	int maximalRectangle1(vector<vector<char>>& matrix)
	{
		//第一种思路开一个矩阵dp[i][j]，表示在第i行，j标号前面连续的1的个数
		// 计算以i,j为右下角的矩阵
		//貌似超时了
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int i, j;
		vector<int>tmp(n,0);
		vector<vector<int>>dp(m,tmp);
		for (i = 0; i < m; i++)
			dp[i][0] = (matrix[i][0] == '1') ? 1 : 0; //计算第一列
		for (i = 0; i < m; i++)
			for (j = 1; j < n; j++)
				dp[i][j] = (matrix[i][j] == '1') ? dp[i][j - 1] + 1:0;  //后面的公式递推
		
		int result = 0;
		int k = 0;
		for (i = 0; i < m; i++)
		{
			for (j = 1; j < n; j++)
			{
				k = i;
				int width = INT_MAX;
				while (k>=0)
				{
					//从第i行向上计算
					if (dp[k][j] == 0) break;
					width = myMin(width,dp[k][j]);
					result = myMax(result,width*(i-k+1));
				}
			}
		}
		return result;
		
	}
	int myMin(int a,int b)
	{
		return a>b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a>b ? a : b;
	}
	int traverse(vector<vector<char>> matrix)
	{
		//我擦，题目理解错了，是要求一个包含全是1的最大矩阵
		//而我这里求的是包含所有的1的最小矩阵的面积
		int m = matrix.size();
		int n = matrix[0].size();
		string tmp(n, '0');
		int i, j;
		int startY = 0,startX=0;
		int endY = 0, endX = 0;
		int count1 = 0;
		bool mark = false;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
				{
					startY = i;
					mark = true;
					break;
				}
			}
			if (mark)
				break;
		}
		if (!mark)
			startY = m;

		mark = false;
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < m; i++)
			{
				if (matrix[i][j] == '1')
				{
					startX = j;
					mark = true;
					break;
				}
			}
			if (mark)
				break;
		}
		if (!mark)
			startX = n;

		mark = false;
		for (i = m-1; i >=0; i--)
		{
			for (j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
				{
					endY = i;
					mark = true;
					break;
				}
			}
			if (mark)
				break;
		}
		if (!mark)
			endY = 0;

		mark = false;
		for (j = n-1; j >= 0; j--)
		{
			for (i = 0; i < m; i++)
			{
				if (matrix[i][j] == '1')
				{
					endX = j;
					mark = true;
					break;
				}
			}
			if (mark)
				break;
		}
		if (!mark)
			endX = 0;

		if (endY >= startY)
		{
			int width = endY - startY+1;
			int height = endX - startX+1;
			return width*height;
		}
		else
		{
			return 0;
		}
	}
};

int main()
{
	vector<string>str = { "000000",
		                  "000100",
						  "000100",
						 };
	vector<vector<char>> matrix(str.size());
	int len = str.size();
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < str[i].length(); j++)
		{
			matrix[i].push_back(str[i][j]);
		}
	}
	Solution mine;
	int result;
	result = mine.maximalRectangle(matrix);
	cout << result << endl;
	return 0;
}