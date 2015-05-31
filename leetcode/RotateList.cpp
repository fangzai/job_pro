/*
time   :  2015-5-17
author :  ht
comment:  右移数据k位置
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
struct ListNode* createNodeList(struct ListNode *head, int *array, int len)
{
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//int len = 2;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	if (len <= 0)
		return NULL;
	int i;
	struct ListNode * p1 = NULL;  // p1 保存创建的新节点的地址
	struct ListNode * p2 = NULL;  // p2 保存链表的最后一个节点的地址
	p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
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

		p1 = (struct ListNode*)malloc(sizeof(struct ListNode));  // 开辟新的地址
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

struct ListNode* rotateRight(struct ListNode* head, int k) {
	if (head == NULL|| head->next ==NULL)
		return head;  //链表是空的或者只有一个元素
	struct ListNode*current = NULL, *p = NULL, *tail = NULL;
	current = head;
	int len = 0;
	while (current != NULL)
	{
		len++;
		if (current->next == NULL)
			tail = current;
		current = current->next;
	}
	int locate = k%len;
	if (locate == 0)
		return head;  //特殊情况 相当于没有移动
	locate = len - locate;
	current = head;
	int i = 0;
	while (i < locate-1)
	{
		i++;
		current = current->next;
	}
	p = current->next;
	current->next = NULL;
	
	tail->next = head;
	head = p;

	return head;
}

int main()
{
	ListNode *head = NULL, *tail = NULL, *first = NULL;

	int  nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int len = 1;
	head = createNodeList(head, nums, len);
	Print(head);
	int k = 1;
	head = rotateRight(head,k);
	Print(head);
	return 0;
}