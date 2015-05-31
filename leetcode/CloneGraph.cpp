/*
time   :  2015-5-24
author :  ht
comment:  将无向图复制一遍
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;


// Definition for undirected graph.
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		//第一种思路，先把图扫一遍，建立一个map,映射label和邻居之间的关系
		if (node==NULL)
			return NULL;

		map<int, UndirectedGraphNode*> mapNode;
		map<int, bool> visited;
		queue<UndirectedGraphNode*> Q;

		Q.push(node); //将第一个node压入队列，然后一次遍历所有的节点，BFS遍历
		//这里如果用深度优先的话，貌似会很坑爹
		UndirectedGraphNode *current;
		while (!Q.empty())
		{
			current = Q.front(); //取出队列中的第一个节点
			Q.pop();//丢掉
			//接着再map中查找 current,如果能找到的就不进队列了
			if (mapNode.find(current->label) == mapNode.end())
			{
				//没有找到，就把这个放到map里面去
				UndirectedGraphNode * newNode = new UndirectedGraphNode(current->label);
				mapNode.insert(pair<int, UndirectedGraphNode*>(current->label,newNode));
				visited.insert(pair<int,bool>(current->label,false));
				//for循环把邻居压到队列里面
				for (int i = 0; i < current->neighbors.size(); i++)
				{
					Q.push(current->neighbors[i]);
				}
			}

		}
		//这个时候Q已经是空的了
		Q.push(node); //将第一个node压入队列，然后再一次遍历所有的节点
		visited[node->label] = true;  //如果已经push过了就不能继续push了
		while (!Q.empty())
		{
			current = Q.front();
			Q.pop();
			UndirectedGraphNode * newNode = mapNode[current->label];
			if (!current->neighbors.empty())
			{
				int len = current->neighbors.size();
				for (int i = 0; i < len; i++)
				{
					int label = current->neighbors[i]->label;
					newNode->neighbors.push_back(mapNode[label]);
					if (!visited[label])
					{
						//如果已经push过了就不能继续push了
						Q.push(current->neighbors[i]);
						visited[current->neighbors[i]->label] = true;
					}
						
				}
			}
		}
		return mapNode[node->label];
	}
	UndirectedGraphNode *cloneGraph1(UndirectedGraphNode *node)
	{
		//第二种思路就是递归，这种方式递归完成一次遍历
		map<int, UndirectedGraphNode*> visited;
		return clone(node, visited);
	}
	UndirectedGraphNode *clone(UndirectedGraphNode *node, map<int, UndirectedGraphNode*> &table)
	{
		if (node == NULL) return NULL;
		if (table.find(node->label) != table.end()) 
			return table[node->label]; //已经遍历过了

		//下面正常遍历
		UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);
		table.insert(pair<int,UndirectedGraphNode*>(node->label,newNode));  //访问过当前的了就pass掉
		int len = node->neighbors.size();
		for (int i = 0; i < len; i++)
		{
			UndirectedGraphNode * neighbors = clone(node->neighbors[i],table);
			//把neighbors放到newNode的邻居上面去
			newNode->neighbors.push_back(neighbors);
			//table.insert(pair<int, UndirectedGraphNode*>(node->neighbors[i]->label, neighbors));
		}
		return  newNode;
	}

	UndirectedGraphNode *createGraph()
	{
		// 构造一个三节点的图
		UndirectedGraphNode*node1=NULL, *node2=NULL, *node3=NULL;
		node1 = new UndirectedGraphNode(1);
		node2 = new UndirectedGraphNode(2);
		node3 = new UndirectedGraphNode(3);
		node1->neighbors.push_back(node2);
		node1->neighbors.push_back(node3);

		node2->neighbors.push_back(node1);
		node2->neighbors.push_back(node3);

		node3->neighbors.push_back(node1);
		node3->neighbors.push_back(node2);
		node3->neighbors.push_back(node3);
		return node1;
	}
};

int main()
{
	Solution mine;
	UndirectedGraphNode *Graph,*newGraph;
	Graph = mine.createGraph();
	newGraph = mine.cloneGraph1(Graph);
	return 0;
}
