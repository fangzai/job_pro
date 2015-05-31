/*
time   :  2015-5-24
author :  ht
comment:  ex207的升级版本，按顺序遍历有向图
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct Node{
	int in;  //第一个维度表示她的入度
	vector<int>request;  //第二维度存需要“我”的节点
};

class Solution {
public:
	vector<int> result;
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<Node>nodes(numCourses);  //有多少门课程就有多少个节点
		int len = 0;
		len = prerequisites.size();
		int i;
		for (i = 0; i < numCourses; i++)
			nodes[i].in = 0;
		pair<int, int> current;
		for (i = 0; i < len; i++)
		{
			//prerequisites的维数其实是二维的
			current = prerequisites[i];
			nodes[current.second].request.push_back(current.first);
			//nodes[i]的req属性里面存的是需要i的节点，不要搞反了
			nodes[current.first].in++;//入度 +1
		}
		queue<int> myQ;
		for (i = 0; i < numCourses; i++)
		{
			if (nodes[i].in == 0)
			{
				myQ.push(i);
			}
		}
		int index;
		while (!myQ.empty())
		{
			index = myQ.front();
			result.push_back(index);
			myQ.pop();
			len = nodes[index].request.size();  //需要index节点的课程都存在这里的request里面
			for (i = 0; i < len; i++)
			{
				//这里挨个把需要index节点课程的入度都 -1
				nodes[nodes[index].request[i]].in--;
				if (nodes[nodes[index].request[i]].in == 0)
					myQ.push(nodes[index].request[i]);
			}
		}
		for (i = 0; i < numCourses; i++)
		{
			//最后检查时候还有入度大于0的课程
			if (nodes[i].in > 0)
			{
				result.clear();
				return result;
			}
				
		}
		return result;
	}
};

int main()
{
	pair<int, int> p1, p2,p3,p4;
	p1 = make_pair<int, int>(1, 0);
	p2 = make_pair<int, int>(2, 0);
	p3 = make_pair<int, int>(3, 1);
	p4 = make_pair<int, int>(3, 2);
	vector<pair<int, int>> pre = { p1, p2 ,p3,p4};
	int nums = 4;
	Solution mine;
	vector<int> result;
	result = mine.findOrder(nums, pre);
	if (result.size() > 0)
	{
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << endl;
	}
	return 0;
}