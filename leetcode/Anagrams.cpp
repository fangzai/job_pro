/*
time   :  2015-5-23
author :  ht
comment:  求一个string数组内，回文的子串
		  回文子串在这里的定义就是，两个字符串内字符出现的都是一样的，就是顺序可以不同
		  比如ate  和eta 还有tae 等等
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



struct Node{
	string str;
	string order;
};
bool cmp(Node a,Node b)
{
	return a.order > b.order;
}

/*
 * 回文子串在这里的定义就是，两个字符串内字符出现的都是一样的，就是顺序可以不同
 * 比如ate  和eta 还有tae 等等
 * 有了这个性质就比较好做了，直接把每个字符串排序，然后相等的就是我们要找的，
 * 把这些重复出现的拿出来就行了
 */
class Solution {
public:
	vector<Node>array;
	vector<string>result;
	vector<string> anagrams(vector<string>& strs) {
		int len = strs.size();
		int i;
		string ordered;
		Node tmp;
		for (i = 0; i < len; i++)
		{
			tmp.str = strs[i];
			ordered = strs[i];
			sort(ordered.begin(), ordered.end());
			tmp.order = ordered;
			array.push_back(tmp);
		}
		sort(array.begin(),array.end(),cmp);
		traverse();
		return result;
	}
	void traverse()
	{
		int len = array.size();
		int ps = 0,pe = 0;
		int count = 0;
		while (ps < len)
		{
			count = 0;
			while (((pe+1)<len )&& (array[ps].order == array[pe + 1].order))
			{
				if (count == 0)
				{
					result.push_back(array[ps].str);
				}
				result.push_back(array[pe+1].str);
				pe++;
				count++;
			}
			ps = pe + 1;
			pe = ps;
		}
	}
};

int main()
{
	vector<string> str = { "tea", "and", "ate", "eat", "den" };
	Solution mine;
	vector<string>result;

	result = mine.anagrams(str);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}