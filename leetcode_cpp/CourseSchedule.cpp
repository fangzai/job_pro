/*
time   :  2015-5-24
author :  ht
comment:  检查一个图里面是否有环
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
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<Node>nodes(numCourses);  //有多少门课程就有多少个节点
		int len = 0;
		len = prerequisites.size();
		int i;
		for (i = 0; i < numCourses; i++)
			nodes[i].in = 0;
		pair<int,int> current;
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
				return false;
		}
		return true;
	}
};

int main()
{
	pair<int, int> p1,p2;
	p1 = make_pair<int,int>(0,1);
	p2 = make_pair<int, int>(1, 0);
	vector<pair<int, int>> pre = {p1,p2};
	int nums = 2;
	Solution mine;
	bool result;
	result = mine.canFinish(nums,pre);
	if (result)
	{
		cout << "Can finsh!" << endl;
	}
	else
	{
		cout << "Can't finish!" << endl;
	}
	return 0;
}