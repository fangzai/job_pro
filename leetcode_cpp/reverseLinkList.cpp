/*
time   :  2015-5-9
author :  ht
comment:  逆转链表
*/
#include<iostream>
#include<cmath>
#include<cstring>

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
	int len = 1;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array[4] = { 1, 1, 0, 0 };
	int i;
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

struct ListNode* reverseList(struct ListNode* head) {
	//逆序链表
	ListNode *current;
	ListNode *p = NULL;
	ListNode *first = NULL;
	int len = sizeof(ListNode);
	if (head == NULL)
	{
		printf("The link list is empty!");
		return head;
	}

	current = head;

	while (current != NULL)
	{
		//逆序操作
		if(current==head)  //此时分配第一个空间
		{
			p = (ListNode*)malloc(len);
			p->val = current->val;
			p->next = NULL;
			first = p;
		}
		else
		{
			p = (ListNode*)malloc(len);
			p->val = current->val;
			p->next = first;
			first = p;
		}
		current = current->next;
	}
	return first;
}
int main()
{
	ListNode *head = NULL;
	head = createNodeList(head);
	Print(head);
	head = reverseList(head);
	Print(head);
	//head = removeElements(head, 1);
	//Print(head);
	return 0;
}