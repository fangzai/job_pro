/*
time   :  2015-5-17
author :  ht
comment:  nlogn实现链表排序，并且空间复杂度为常数
//用的归并排序
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

struct ListNode* findMid(struct ListNode*head)
{
	struct ListNode*current = NULL, *fast = NULL,*tail=NULL;
	if (NULL == head || NULL == head->next)
		return head;
	current = head;
	fast = head;
	while (fast != NULL&&fast->next != NULL)
	{
		tail = current;
		current = current->next;
		fast = fast->next->next;//走两步
	}

	return tail;  //有人喜欢返回 current,貌似不应该，应该是current的上一个
}

struct ListNode* merge_list(struct ListNode*l1, struct ListNode*l2)
{
	//两个排序后的链表融合
	struct ListNode *head = NULL, *current1 = NULL, *current2 = NULL, *current = NULL;
	current1 = l1;
	current2 = l2;

	int value1, value2;
	int count = 0;
	if (l1 == NULL)
	{
		head = l2;
		return head;
	}
	if (l2 == NULL)
	{
		head = l1;
		return head;
	}
	while (current1 != NULL&&current2 != NULL)
	{
		value1 = current1->val;
		value2 = current2->val;

		if (value1 < value2)
		{
			if (count == 0)
			{
				head = current1;
				current = current1;
			}
			else
			{
				current->next = current1;
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
	if (current1 != NULL)
	{
		current->next = current1;
	}
	else if (current2 != NULL)
	{
		current->next = current2;
	}
	else
	{
		current->next = NULL;
	}

	return head;
}

struct ListNode* traverse(struct ListNode* head)
{
	if (NULL == head || NULL == head->next)
		return head;
	struct ListNode*mid = NULL,* head1 = NULL;

	mid = findMid(head);
	head1 = mid->next;
	mid->next = NULL;  //将一个链表拆成两个链表
	
	head = traverse(head);
	head1 = traverse(head1);
	head = merge_list(head,head1);
	return head;
}

struct ListNode* sortList(struct ListNode* head) {
	struct ListNode *current = NULL, *tail = NULL, *first = NULL;
	current = head;

	head = traverse(head);
	return head;
}

int main()
{
	ListNode *head = NULL, *tail = NULL, *first = NULL;

	//int  nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int  nums[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int len = 9;
	head = createNodeList(head, nums, len);
	Print(head);

	head = sortList(head);
	Print(head);
	return 0;
}