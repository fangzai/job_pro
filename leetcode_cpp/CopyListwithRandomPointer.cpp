/*
time   :  2015-5-27
author :  ht
comment:  深度复制随机指针
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
#include<map>
using namespace std;
// Definition for singly-linked list with a random pointer.
/*
 *struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};
*/

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
};
struct RandomListNode* createNodeList(struct RandomListNode*head)
{
	head = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
	int len = 5;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int i;
	if (len <= 0)
		return NULL;
	struct RandomListNode * p1 = NULL;  // p1 保存创建的新节点的地址
	struct RandomListNode * p2 = NULL;  // p2 保存链表的最后一个节点的地址
	p1 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
	p1->random = NULL;
	p2 = p1;

	for (i = 0; i < len; i++)
	{
		p1->label = array[i];

		if (i == 0)
		{
			head = p1;
			p2->next = NULL;  //此时的p2就是p1，首次赋值的时候将p2指向空

		}
		else
		{
			p2->next = p1;   //指向上次下面刚刚开辟的新节点
		}

		p2 = p1;    //把p1的地址给p2保留，然后p1产生新的节点

		p1 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));  // 开辟新的地址
		p1->random = NULL;
	}
	p2->next = NULL;   // p2一直是末端节点


	free(p1);
	p1 = NULL;
	return head;
}
void Print(struct RandomListNode* head)
{
	struct RandomListNode *current;
	printf("Begin to output the node of this linklist\n");
	current = head;
	int i = 0;
	if (current != NULL)
	{
		do
		{
			printf("%d ", current->label);
			i++;
			current = current->next;
			if (current)
				printf(" -> ");
		} while (current != NULL);
		printf("\n");
	}
	else
	{
		printf("The link list is empty!");
	}
}

class Solution {
public:
	
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode * newHead = traverse(head);
		return newHead;
	}
	RandomListNode * traverse(RandomListNode *head)
	{
		map<RandomListNode *, RandomListNode *>map1,map2,map3;
		//map1 映射 旧链表随机指针之间的关系
		//map2 映射 新旧链表节点之间的关系
		//map3 映射 新链表随机指针之间的关系

		RandomListNode *current = NULL, *newHead = NULL,*p=NULL,*randomPointer=NULL;
		current = head;
		while (current != NULL)
		{
			p = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
			p->next = NULL;
			p->random = NULL;
			p->label = current->label;
			if (current->random != NULL)
			{
				map1.insert(pair<RandomListNode *, RandomListNode *>(current, current->random));
			}
			map2.insert(pair<RandomListNode *, RandomListNode *>(current,p));  //所有的节点都map上
			if (current == head)
			{
				pre = p;
				newHead = p;
			}
			else
			{
				pre->next = p;
				pre = pre->next;
			}
			current = current->next;
		}

		current = head;
		p = newHead;
		while (current != NULL)
		{
			if (map1.find(current) != map1.end())
			{
				randomPointer = map1[current];  //通过map1找到  current的random节点
				map3.insert(pair<RandomListNode *, RandomListNode *>(map2[current], map2[randomPointer]));
				map2[current]->random = map2[randomPointer]; //通过map2找到 对应current那个节点的 random节点
			}
			current = current->next;
			//p = p->next;
		}
		return newHead;
	}
};
int main()
{
	struct RandomListNode *head = NULL, *current = NULL,*result=NULL, *link[10];
	head = createNodeList(head);
	Print(head);
	int i = 0;
	current = head;
	while (current != NULL)
	{
		link[i] = current;
		current = current->next;
		i++;
	}
	link[0]->random = link[3];
	link[2]->random = link[3];
	Solution mine;
	result = mine.copyRandomList(head);
	return 0;
}