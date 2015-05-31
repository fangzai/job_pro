/*
time   :  2015-5-26
author :  ht
comment:  求histogram图里面的最大连续面积
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
 * 好吧！我表示线性算法我是想不出来，只能用暴力搜索的方法
 */
class Solution {
public:
	int largestRectangleArea(vector<int>& height) {

		return traverse(height);
	}
	int traverse(vector<int>& height)
	{
		//使用栈 线性算法
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
					width = i - myStack.top()-1;
				}
				maxArea = myMax(maxArea,height[index]*width);
			}
		}
		return maxArea;

	}
	int myMax(int a,int b)
	{
		return a > b ? a : b;
	}
	int traverse1(vector<int>& height)
	{
		//暴力搜索的方法
		//超时
		int len = height.size();
		int i, j;
		int largestAera = 0;
		int area = 0;
		for (i = 0; i < len; i++)
		{
			area = 0;
			int low = height[i];
			for (j = i; j < len; j++)
			{
				if (height[j] < low) low = height[j];

				area = (j - i + 1)*low;
				if (area>largestAera) largestAera = area;
			}
		}
		return largestAera;
	}
};

int main()
{
	vector<int>height = { 2, 1, 5, 6, 2, 3 };
	Solution mine;
	int result;
	result = mine.largestRectangleArea(height);
	cout << result << endl;
	return 0;
}