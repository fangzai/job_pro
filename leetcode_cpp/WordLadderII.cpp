/*
time   :  2015-5-28
author :  ht
comment:  单词变换的问题  呵呵！！ 我能把最后的路径最后的一个点都找出来，可以全部不行额~~~
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;


class Solution {
public:
	//这方法超时了 你大爷的
	vector<vector<string>> result;
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		int len1 = start.size();
		int len2 = end.size();
		if (len1 != len2) return result;
		if (len1 == 0 || len2 == 0) return result;
		traverse1( start,end, dict);
		return result;
	}
	int traverse1(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		//宽度优先搜索 每次将beginWord里的一个字符变成非自己的的a-z的一个，查看字典里面有没有
		queue < string> que;

		//记录每个单词的前驱
		map<string, vector<string>> trace;
		map<string,int> last;
		bool mark = false;
		que.push(beginWord);
		int currentSteps = 1;  //初始化为1
		int currentNum = 1;   //开始的时候只有一个
		wordDict.erase(beginWord);  //把第一个单词去掉 如果有的话
		queue < string> delQue;
		while (!que.empty())
		{
			string current = que.front();
			que.pop();
			currentNum--;
			delQue.push(current);
			for (int i = 0; i < current.size(); i++)
			{
				string tmp = current;

				for (char j = 'a'; j <= 'z'; j++)
				{
					tmp[i] = j; //否则的话看看dict里面有没有
					if (tmp == current) 
						continue;//自身不用变换
					
					if (tmp == endWord)
					{
						mark = true;
						last.insert(pair<string, int>(current,0));
					}
					if (wordDict.find(tmp) != wordDict.end())
					{
						que.push(tmp);
						vector<string>mean;
						if (trace.find(tmp) == trace.end())
						{
							mean.push_back(current);
							trace.insert(pair<string, vector<string>>(tmp, mean));
						}
						else
						{
							mean = trace[tmp];
							vector<string>::iterator it = find(mean.begin(),mean.end(),current);
							if (it == mean.end())
							{	
								//没有找到
								mean.push_back(current);
								trace.erase(tmp);
								trace.insert(pair<string, vector<string>>(tmp, mean));
							}

						}
					}
				}
			}
			if (mark&&currentNum==0)
				break;
			if (currentNum == 0)
			{
				while (!delQue.empty())
				{
					wordDict.erase(delQue.front());  //把这一层出现过的都删掉
					delQue.pop();
				}
				currentNum = que.size();  //如果这一层遍历完了，下一层的个数刚好是队列的大小
				currentSteps++;
			}
		}
		vector<string>res;
		map<string, int>::iterator it;
		for (it = last.begin(); it != last.end(); it++)
		{
			res.push_back((*it).first);
		}
		getRes(res, trace, endWord, beginWord, currentSteps);
		return 0;//如果走到这儿的话，说明没有路径
	}
	void getRes(vector<string>last, map<string, vector<string>> trace, string endWord, string beginWord,int depth)
	{
		
		for (int i= 0; i < last.size(); i++)
		{
			vector<string>res;
			res.push_back(endWord);
			traverse(last[i], trace, beginWord, res,depth,0);
		}
		for (int i = 0; i < result.size(); i++)
		{
			reverse(result[i].begin(),result[i].end());
		}
	}
	void traverse(string current, map<string, vector<string>> trace, string beginWord, vector<string> res,int depth,int index)
	{
		if (index >= depth)
			return;
		if (current == beginWord)
		{
			res.push_back(current);
			result.push_back(res);
		}
		else
		{
			vector<string>tmp = trace[current];
			for (int i = 0; i < trace[current].size(); i++)
			{
				vector<string>me = res;
				me.push_back(current);
				traverse(tmp[i], trace, beginWord, me,depth,index+1);
			}
		}
	}
};

class Solution0 {
public:
	/*
	 * 这份代码的思路应该说和我上面的思路几乎一模一样，就是在前缀用的数据结构和我的不同
	 * http://www.tuicool.com/articles/eaQNNr
	 */
	vector<string> temp_path;
	vector<vector<string>> result_path;

	void GeneratePath(unordered_map<string, unordered_set<string>> &path, const string &start, const string &end)
	{
		//重建路径的过程，用dfs
		temp_path.push_back(start);
		if (start == end)
		{
			vector<string> ret = temp_path;
			reverse(ret.begin(), ret.end());
			result_path.push_back(ret);
			return;
		}

		for (auto it = path[start].begin(); it != path[start].end(); ++it)
		{
			GeneratePath(path, *it, end);
			temp_path.pop_back();
		}
	}
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
	{
		temp_path.clear();
		result_path.clear();

		unordered_set<string> current_step; //当前层需要遍历的节点
		unordered_set<string> next_step;    //下一层需要遍历的节点

		unordered_map<string, unordered_set<string>> path;  
		//最好是用set这种数据结构，我的里面开始的时候就出现了好多重复的元素

		unordered_set<string> unvisited = dict; //未访问过的元素set

		if (unvisited.count(start) > 0)
			unvisited.erase(start); //先把start给删掉

		current_step.insert(start);  //当前层只需要遍历start

		while (current_step.count(end) == 0 && unvisited.size() > 0)
		{
			//如果当前层没有end节点，或者说字典中还有元素没有被访问
			for (auto pcur = current_step.begin(); pcur != current_step.end(); ++pcur)
			{
				//前缀
				string word = *pcur;

				for (int i = 0; i < start.length(); ++i)
				{
					for (int j = 0; j < 26; j++)
					{
						string tmp = word;
						if (tmp[i] == 'a' + j)
							continue;
						tmp[i] = 'a' + j;
						if (unvisited.count(tmp) > 0)
						{
							//如果在未访问的集合里面找到tmp，把tmp放到下一层中
							//并且 tmp的前缀放入word这个单词
							next_step.insert(tmp);
							path[tmp].insert(word);
						}
					}
				}
			}

			if (next_step.empty()) break;  //如果下一层没有要访问的了，直接break退出了
			for (auto it = next_step.begin(); it != next_step.end(); ++it)
			{
				unvisited.erase(*it); //在unvisited集合中删除下一层需要访问的元素
				//因为在到了下一层的时候，肯定不会生成和本层一样单词的孩子，否则就不是最短路径了
				//这一点很重要，否则重建路径的时候就陷入死循环了
			}

			current_step = next_step; //current_step置为下一层要访问的，下一层的清空
			next_step.clear();
		}

		if (current_step.count(end) > 0)
			GeneratePath(path, end, start);

		return result_path;
	}
};

class Solution1 {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		pathes.clear();
		dict.insert(start);
		dict.insert(end);
		vector<string> prev;
		unordered_map<string, vector<string> > traces;
		for (unordered_set<string>::const_iterator citr = dict.begin();citr != dict.end(); citr++)
		{
			traces[*citr] = prev;
		}

		vector<unordered_set<string> > layers(2);
		int cur = 0;
		int pre = 1;
		layers[cur].insert(start);
		while (true) 
		{
			cur = !cur;
			pre = !pre;
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();citr != layers[pre].end(); citr++)
				dict.erase(*citr);
			
			layers[cur].clear();
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();citr != layers[pre].end(); citr++)
			{
				for (int n = 0; n<(*citr).size(); n++)
				{
					string word = *citr;
					int stop = word[n] - 'a';
					for (int i = (stop + 1) % 26; i != stop; i = (i + 1) % 26) 
					{
						word[n] = 'a' + i;
						if (dict.find(word) != dict.end())
						{
							traces[word].push_back(*citr);
							layers[cur].insert(word);
						}
					}
				}
			}
			if (layers[cur].size() == 0)
				return pathes;
			if (layers[cur].count(end))
				break;
		}
		vector<string> path;
		buildPath(traces, path, end);

		return pathes;
	}

private:
	void buildPath(unordered_map<string, vector<string> > &traces,vector<string> &path, const string &word)
	{
		if (traces[word].size() == 0) 
		{
			path.push_back(word);
			vector<string> curPath = path;
			reverse(curPath.begin(), curPath.end());
			pathes.push_back(curPath);
			path.pop_back();
			return;
		}

		const vector<string> &prevs = traces[word];
		path.push_back(word);
		for (vector<string>::const_iterator citr = prevs.begin();citr != prevs.end(); citr++) 
		{
			buildPath(traces, path, *citr);
		}
		path.pop_back();
	}

	vector<vector<string> > pathes;
};


int main()
{
	string start = "qa";
	string end = "sq";
	unordered_set<string>dict = { "si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye" };
	Solution mine;
	vector<vector<string>> result;
	result = mine.findLadders(start, end, dict);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j]<<"->";
		}
		cout << endl;
	}
	
	return 0;
}