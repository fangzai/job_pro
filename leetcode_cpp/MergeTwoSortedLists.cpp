/*
time   :  2015-5-9
author :  ht
comment:  融合两个已经排序过的链表
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
ListNode* createNodeList(ListNode *head,int *array,int len)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	//int len = 4;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//int array[4] = { 1, 1, 0, 0 };
	int i;
	ListNode * p1 = NULL;  // p1 保存创建的新节点的地址
	ListNode * p2 = NULL;  // p2 保存链表的最后一个节点的地址
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p2 = p1;
	if (len<=0)
	{
		head = NULL;   //特殊情况  产生空链表
		return head;
	}
		
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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	ListNode *head = NULL, *current1 = NULL, *current2 = NULL, *current = NULL;
	current1 = l1;
	current2 = l2;

	int value1, value2;
	int count = 0;

	//以下是两种特殊情况，单独考虑
	if (l1 == NULL)
	{
		head = l2;
		return head;
		//current = current2;
	}
	if (l2 == NULL)
	{
		head = l1;
		return head;
		//current = current1;
	}

	//三个while循环  遍历
	while (current1 != NULL&&current2 != NULL)
	{
		value1 = current1->val;
		value2 = current2->val;

		if (value1 < value2)
		{
			if (count == 0)
			{
				head = current1;  //先确定头
				current = current1;
			}
			else
			{
				current->next = current1;  
				//如果不是头的话直接赋指针
				current = current->next;
			}
			
			current1 = current1->next;
			
			count++;
		}
		else
		{
			if (count == 0)
			{
				head = current2;
				current = current2;
			}
			else
			{
				current->next = current2;
				current = current->next;
			}
			current2 = current2->next;
			
			count++;
		}
		
	}
	//这两个循环是判定可能有个链表还有没有遍历完成的继续遍历
	while (current1 != NULL)
	{
		current->next = current1;

		current1 = current1->next;
		current = current->next;
		count++;
	}
	while (current2 != NULL)
	{
		current->next = current2;

		current2 = current2->next;
		current = current->next;
		count++;
	}
	current->next = NULL;  // 末端节点指针赋为0
	
	return head;
}


int main()
{
	ListNode *link1 = NULL, *link2 = NULL,*head = NULL;

	int array1[5] = {1,5,7,8,9};
	int num1 = 5;
	int *array2=NULL;
	int num2 = 0;
	link1 = createNodeList(link1,array1,num1);
	Print(link1);

	link2 = createNodeList(link2, array2, num2);
	Print(link2);

	head = mergeTwoLists(link1, link2);
	Print(head);
	return 0;
}