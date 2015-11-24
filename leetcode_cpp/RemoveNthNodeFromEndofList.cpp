/*
time   :  2015-5-9
author :  ht
comment:  从链表中删除倒数第N个节点
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
ListNode* createNodeList(ListNode *head, int *array, int len)
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
	if (len <= 0)
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
int locate(struct ListNode *current, int n, struct ListNode* head)
{
	int num = 0; // 用于记录遍历的次序（倒数）
	if (current->next == NULL)
	{
		num = 1;
		return num;
	}
	else
	{
		struct ListNode *p = NULL;
		p = current;
		current = current->next;
		num = 1 + locate(current, n,head);
		if ((num - 1) == n)  
		{
			// 这里根本无法递归到头结点
			// 需要在递归结束后删除
			p->next = current->next;
			free(current);	
			current = NULL;  
		}

		return num;
	}
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	
	struct ListNode *current = NULL;
	current = head;
	int num = locate(current, n, head); 
	// 删除头节点需要在这里删除
	if (num == n)
	{
		head = head->next;
		free(current);
		current = NULL;
	}
		
	return head;
}


int main()
{
	ListNode *link1 = NULL, *link2 = NULL, *head = NULL;

	int array1[5] = { 1, 5, 7, 8, 9 };
	int num1 = 5;
	//int *array2 = NULL;
	//int num2 = 0;
	link1 = createNodeList(link1, array1, num1);
	Print(link1);

	head = removeNthFromEnd(link1, 5);
	Print(head);
	return 0;
}