/*
time   :  2015-5-17
author :  ht
comment:  对于一个链表，指定中心轴开始划分
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

struct ListNode* insertionSortList(struct ListNode* head, struct ListNode*current) {
	struct ListNode *p = NULL, *p1 = NULL, *p2 = NULL;
	//插入排序函数  没有用
	p = head;
	while (p->next != NULL&&p->next->val <= current->val)
	{
		p = p->next;
	}
	p1 = p->next;
	p2 = current;

	p->next = p2;
	p2->next = p1;

	return head;
}

struct ListNode* partition(struct ListNode* head, int x) {
	if (head == NULL)
		return NULL;
	struct ListNode*current = NULL, *tail = NULL, *head1 = NULL, *p = NULL,*p1=NULL,*p2=NULL;
	
	p = (struct ListNode*)malloc(sizeof(struct ListNode*));
	p->val = INT_MAX;
	p->next = head;
	head = p;   //给了一个虚拟的头

	
	p1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	p1->val = INT_MIN;
	p1->next =NULL;
	head1 = p1;   //给了一个虚拟的头

	current = head;
	
	tail = head1;
	while (current!=NULL&&current->next!=NULL)
	{
		if (current->next->val < x)
		{
			//需要插入到第一条链表之中
			p1 = current->next;
			p2 = p1->next;    //把要挪到前面的点都拆出来
			current->next = p2;
			p1->next = NULL;  //把p1点拆出来

			tail->next = p1;
			tail = tail->next;  
			//因为要保持他们的原始顺序不变，这个地方就不必用插入排序了
		}
		else
		{
			current = current->next;
		}
	}

	p1 = head1;
	head1 = head1->next;
	//free(p1);
	//p1 = NULL;

	p = head;
	head = head->next;
	//free(p);
	//p = NULL;//内存回收
	if (head1 == NULL)
	{
		return head;
	}
	tail->next = head;

	return head1;
	
}

int main()
{
	ListNode *head = NULL, *tail = NULL, *first = NULL;

	int  nums[10] = { 2,1,3};
	int len = 2;
	head = createNodeList(head, nums, len);
	Print(head);
	int pivot = 4;
	head = partition(head,pivot);
	Print(head);
	return 0;
}