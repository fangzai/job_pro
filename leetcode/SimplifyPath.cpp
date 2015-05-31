/*
time   :  2015-5-23
author :  ht
comment:  简化指定的路径
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	stack<string> myStack;
	string simplifyPath(string path) {
		string str;
		if (path.length() <= 0)
			return str;
		traverse(path);
		//从栈中把数据弹出来
		if (myStack.empty())
		{
			//如果栈为空的话，那么就把当前目录放到str里面去
			str.append("/");
		}
		string temp;
		while (!myStack.empty())
		{
			temp = myStack.top();
			myStack.pop();
			str.insert(0,temp);
		}
		//下面的重复判定其实没有必要
		int len = str.length();
		if (len>= 2&&str[0]==str[1])
		{
			str = str.substr(1,len-1);
		}

		return str;
		
	}
	void traverse(string path)
	{
		int len = path.size();
		int ps = 0,pe = ps;
		string str;

		int range;
		while (ps < len)
		{
			while (((pe+1)<len) && (path[pe+1] != '/'))
			{
				pe++;
			}
			//切割字符串
			
			range = pe - ps + 1;
			str = path.substr(ps, range);
			if (str == "/")
			{
				//什么也不错，因为这个不需要压栈
			}
			else if (str == "/.")
			{
				//什么也不错，因为这个不需要压栈
			}
			else if (str == "/..")
			{
				if (!myStack.empty())
				{
					myStack.pop();
				}
			}
			else
			{
				myStack.push(str);
			}
			//ps重置到pe
			pe++;
			ps = pe;
			
		}

	}
};

int main()
{
	//string path = "/a/./b/../../c/";
	//string path = "//a/././/b/../../c/";
	string path = "/..";
	Solution mine;
	string result;
	result = mine.simplifyPath(path);
	cout << result << endl;
	return 0;
}