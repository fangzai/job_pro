/*
time   :  2015-5-15
author :  ht
comment:  从链表表头开始交换两个相邻的元素
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
struct ListNode* createNodeList(struct ListNode *head)
{
	head = (struct ListNode*)malloc(sizeof(struct  ListNode));
	int len = 0;
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int array[4] = { 1, 1, 0, 0 };
	if (len <= 0)
		return NULL;
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

struct ListNode* traverse(struct ListNode*head)
{
	if (head == NULL || head->next == NULL)
	{
		return NULL; //返回current的下一个节点
	}
	if (head->next->next == NULL)
	{
		return head->next;
	}
	struct ListNode*current = NULL, *p1 = NULL, *p2 = NULL,*p3 = NULL;
	current = head;
	
	p1 = current->next;  //交换p1 p2指针
	p2 = p1->next;
	p3 = p2->next;
	current->next = p2;
	p2->next = p1;
	p1->next = p3;
	return p2;
}
struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* current=NULL,*p=NULL;
	p = (struct ListNode*)malloc(sizeof(struct ListNode));

	p->val = -1;
	p->next = head;
	head = p;

	current = head;
	while (current != NULL)
	{
		p = traverse(current);
		current->next = p;
		if (p==NULL||p->next == NULL || p->next->next == NULL)
		{
			break;
		}
		current = current->next->next;
	}

	p = head;
	head = head->next;
	free(p);
	p = NULL;
	return head;
}



int main()
{
	ListNode *head = NULL;
	head = createNodeList(head);
	Print(head);
	head = swapPairs(head);
	Print(head);
	//head = deleteDuplicates(head);
	//Print(head);
	//head = removeElements(head, 1);
	//Print(head);
	return 0;
}