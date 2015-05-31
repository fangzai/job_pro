/*
time   :  2015-5-28
author :  ht
comment:  单词变换的问题
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		int len1 = beginWord.size();
		int len2 = endWord.size();
		if (len1 != len2) return 0;
		if (len1 == 0 || len2 == 0) return 0;
		int result = traverse1(beginWord,endWord,wordDict);
		return result;
	}
	int traverse1(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		//宽度优先搜索 每次将beginWord里的一个字符变成非自己的的a-z的一个，查看字典里面有没有
		queue < string> que;
		que.push(beginWord);
		int currentSteps = 1;  //初始化为1
		int currentNum = 1;   //开始的时候只有一个
		wordDict.erase(beginWord);  //把第一个单词去掉 如果有的话
		while (!que.empty())
		{
			string current = que.front();
			que.pop();
			currentNum--;
			for (int i = 0; i < current.size(); i++)
			{
				string tmp = current;
				for (char j = 'a'; j <= 'z'; j++)
				{
					tmp[i] = j; //否则的话看看dict里面有没有
					if (tmp == current)
						continue;//自身不用变换
					if (tmp == endWord) return currentSteps + 1;
					if (wordDict.find(tmp) != wordDict.end())
						que.push(tmp);
					//加入队列搜索，并且从字典中删除
					wordDict.erase(tmp);  //这样就可以判断是否访问过了的
				}
			}
			if (currentNum == 0)
			{
				currentNum = que.size(); 
				//如果这一层遍历完了，下一层的个数刚好是队列的大小
				currentSteps++;
			}
		}
		return 0;//如果走到这儿的话，说明没有路径
	}
	int traverse(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		//第一种思路，扫描所有字典，如果能一次变换且以前没有扫描过就加入字典
		//相当于深度优先搜索
		unordered_set<string>visited;
		visited.insert(beginWord);  //开始的单词加进去
		queue<string> que;

		int currentSteps = 1;     //记录变换了多少步,初始值为1是因为把当前的start也算进去了
		int currentLevelNum = 1;  //当前层有几个元素，第一层只有beginWord一个元素
		int nextLevelNum = 0;       //用于记录下一层的元素
		
		que.push(beginWord);

		while (!que.empty())
		{
			string current = que.front(); //取出当前的string
			que.pop(); 

			unordered_set<string>::iterator it;
			//遍历字典
			currentLevelNum--;//pop后当前层的元素减少一个
			for (it = wordDict.begin(); it != wordDict.end(); it++)
			{
				string tmp = *it;
				if ((stringDiff(current, tmp) == 1) && (visited.find(tmp) == visited.end()))
				{
					//如果当前current->tmp只有一个距离，且tmp没有被访问过
					que.push(tmp);
					visited.insert(tmp);
					nextLevelNum++;  //下一层的元素增加一个
				}
			}
			if (stringDiff(current, endWord) == 1)	return currentSteps + 1;

			if (currentLevelNum == 0)
			{
				//当前层遍历完了，开始下一层
				currentSteps++; //层数加 1
				currentLevelNum = nextLevelNum;
				nextLevelNum = 0;  //下一层清零
			}

		}

	}
	int  stringDiff(string a,string b)
	{
		int len1 = a.size();
		int len2 = b.size();
		int count = 0;
		for (int i = 0; i < len1; i++)
		{
			if (a[i] != b[i])count++;
		}
		return count;
	}
};

int main()
{
	string start = "hit";
	string end = "cog";
	unordered_set<string>dict = { "hot", "dot", "dog", "lot", "log" };
	Solution mine;
	int result;
	result = mine.ladderLength(start,end,dict);
	cout << result << endl;
	return 0;
}