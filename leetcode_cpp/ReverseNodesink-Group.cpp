/*
time   :  2015-5-27
author :  ht
comment:  每k个元素逆转一次
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode {
	int val;
	struct ListNode *next;
};
ListNode* createNodeList(ListNode *head)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	int len = 3;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i;
	if (len <= 0)
		return NULL;
	ListNode * p1 = NULL;  // p1 保存创建的新节点的地址
	ListNode * p2 = NULL;  // p2 保存链表的最后一个节点的地址
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p2 = p1;

	for (i = 0; i < len; i++)
	{
		p1->val = array[i];

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

		p1 = (ListNode*)malloc(sizeof(ListNode));  // 开辟新的地址
	}
	p2->next = NULL;   // p2一直是末端节点


	free(p1);
	p1 = NULL;
	return head;
}
void Print(ListNode* head)
{
	ListNode *current;
	printf("Begin to output the node of this linklist\n");
	current = head;
	int i = 0;
	if (current != NULL)
	{
		do
		{
			printf("%d ", current->val);
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

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	//其实用栈和队列来实现链表的逆转操作什么的特么简单
	//我前面是傻了，全部都是自己写递归什么的，恶心死了
	if (head == NULL||k<=1)
		return head;
	stack<struct ListNode*>myStack;
	struct ListNode* current=NULL,*tail=NULL,*start=NULL,*first=NULL;
	bool mark = false;
	current = head;
	while (current != NULL)
	{
		mark = false;
		start = current;
		for (int i = 0; i < k; i++)
		{
			//先遍历一下，看看后面的够不够
			if (current == NULL)
			{
				mark = true;
				current = start;
				break;
			}
			current = current->next;
		}
		if (mark) break;
		current = start;
		for (int i = 0; i < k; i++)
		{
			myStack.push(current);
			current = current->next;
		}
		for (int i = 0; i < k; i++)
		{
			if (tail == NULL)
			{
				tail = myStack.top();
				head = tail;
				tail->next = NULL;
				myStack.pop();
			}
			else
			{
				tail->next = myStack.top();
				myStack.pop();
				tail = tail->next;
				tail->next = NULL;
			}
		}
	}
	if (tail == NULL)
	{
		return head;
	}
	else
	{
		while (current != NULL)
		{
			tail->next = current;
			tail = tail->next;
			current = current->next;
			tail->next = NULL;
		}
		tail->next = NULL;
		return head;
	}
}
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		if (head == NULL || k <= 1)
			return head;
		stack<ListNode*>myStack;
		ListNode* current = NULL, *tail = NULL, *start = NULL, *first = NULL;
		bool mark = false;
		current = head;
		while (current != NULL)
		{
			mark = false;
			start = current;
			for (int i = 0; i < k; i++)
			{
				if (current == NULL)
				{
					mark = true;
					current = start;
					break;
				}
				current = current->next;
			}
			if (mark) break;
			current = start;
			for (int i = 0; i < k; i++)
			{
				myStack.push(current);
				current = current->next;
			}
			for (int i = 0; i < k; i++)
			{
				if (tail == NULL)
				{
					tail = myStack.top();
					head = tail;
					myStack.pop();
				}
				else
				{
					tail->next = myStack.top();
					myStack.pop();
					tail = tail->next;
				}
			}
		}
		if (tail == NULL)
		{
			return head;
		}
		else
		{
			while (current != NULL)
			{
				tail->next = current;
				tail = tail->next;
				current = current->next;
			}
			tail->next = NULL;
			return head;
		}
	}
};

int main()
{
	ListNode *head = NULL, *tail = NULL, *first = NULL;
	head = createNodeList(head);
	Print(head);
	int k = 4;
	first = reverseKGroup(head,k);
	Print(first);
	return 0;
}