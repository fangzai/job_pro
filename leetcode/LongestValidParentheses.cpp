/*
time   :  2015-5-29
author :  ht
comment:  求一堆括号中最长的匹配
*/
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	/*
	 * 可以用暴力搜索的方法，不过这样很傻
	 * 思考了一下，一次遍历就可以完成，用栈实现，最后没有被弹出来的就是分割线
	 * 最后计算一下分割线的距离就可以了
	 * 据说此题还有人用动态规划，我那个去，这都行！！
	 */
	int longestValidParentheses1(string s) {
		//用栈来实现，遍历一次，每次把下标放进去，一旦匹配就把下标弹出来
		//没有被弹出来的就是分割不匹配的字符括号的
		int len = s.size();
		if (len < 2)
			return 0;
		int i;
		i = len - 1;
		stack<char>myStack;
		stack<int>indexStack;  //存储下标的括号
		int count = 0;
		int maxLen = INT_MIN;
		while (i >= 0)
		{
			indexStack.push(i);
			if (s[i] == ')')
			{
				myStack.push(')');
			}
			else
			{
				//如果是前括号的话
				if (!myStack.empty())
				{
					myStack.pop();
					indexStack.pop();
					indexStack.pop();//一旦匹配，就把两个都弹出来
				}
				
			}
			i--;
		}
		maxLen = 0;
		len = indexStack.size();
		//最后的下标还少保留了两个，一个是字符串末尾，一个是字符串开头
		if (indexStack.empty()) //如果indexStack为空的话，说明全部匹配
		{
			return s.length();
		}

		int current;
		int previous = indexStack.top();
		if (previous != 0)
			maxLen = myMax(maxLen,previous); 
		//如果开头不是分割线的话，说明需要计算从0到栈顶下标的距离


		for (i = 0; i < len; i++)
		{
			current = indexStack.top();
			indexStack.pop();
			maxLen = myMax(maxLen,current-previous-1);
			previous = current;
		}

		current = s.length();  //计算一下最后一个保存的index到 字符串末尾的距离
		maxLen = myMax(maxLen, current - previous - 1);


		return maxLen;
	}
	int myMax(int a,int b)
	{
		return a > b ? a : b;
	}
	int myMin(int a, int b)
	{
		return a > b ? b : a;
	}
	int longestValidParentheses(string s) {
		int len = s.size();
		if (len < 2)
			return 0;
		int i, j;
		bool mark;
		int maxLen = 0;
		int tmpLen = 0;
		for (i = 0; i < len; i++)
		{
			for (j = i + 1; j < len; j += 2)
			{
				string tmp = s.substr(i,j-i+1);
				tmpLen = tmp.size();
				mark = validParentheses(tmp);

				if (mark)
				{
					maxLen = maxLen>tmpLen ? maxLen : tmpLen;
				}

			}
		}
		return maxLen;
	}
	bool validParentheses(string s)
	{
		stack<char> myStack;
		int len = s.length();
		int i = len - 1;
		while (i >= 0)
		{
			if (s[i] == ')')
			{				
				i--;
				myStack.push(')');
			}
			else
			{
				if (myStack.empty())
					return false;
				else
				{
					myStack.pop();
					i--;
				}
					
			}
		}
		if (!myStack.empty())
			return false;
		else
			return true;
	}
};

int main()
{
	Solution mine;
	string s = "()(()(()";
	//bool mark = false;
	//mark = mine.validParentheses(s);
	//if (mark)
	//	cout << "Is valid parenttheses!" << endl;
	//else
	//	cout << "Not valid parenttheses!" << endl;

	int result;
	result = mine.longestValidParentheses1(s);
	cout << result << endl;
	return 0;
}