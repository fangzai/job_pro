/*
time   :  2015-5-15
author :  ht
comment:  逆转指定位置的链表
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
	int len = 2;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array[10] = { 1, 2, 3, 4,5,6,7,8 };
	int i;
	if(len<=0)
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

struct ListNode* reverseList(struct ListNode* current, struct ListNode**first) {
	//逆序链表  z这是原址重排的算法
	struct ListNode*p1 = NULL, *p2 = NULL;
	if (current->next->next == NULL)
	{
		p1 = current->next;
		current->next = NULL;
		p1->next = NULL;
		first[0] = p1;
		return p1;
	}
	else
	{
		p1 = reverseList(current->next, first);
		p1->next = current->next;
		current->next = NULL;
		p1 = p1->next;
		p1->next = NULL;
		return p1;
	}
	//return first;
}
struct ListNode* reverseHead(struct ListNode* head)
{
	ListNode *tail = NULL, *first = NULL;
	//Print(head);
	tail = reverseList(head, &first);
	tail->next = head;
	//Print(first);
	return first;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {

	struct ListNode *current, *head1 = NULL, *tail = NULL, *tail1 = NULL, *head2=NULL, *first = NULL;
	current = head;
	int i;
	i = 0;
	while (current->next!=NULL)   
	{
		if ((i + 1) == (m - 1))
		{
			tail = current;  //计算第一条链表的tail
		}
		if ((i + 1) == n)
		{
			tail1 = current; //第二条链表的tail
			break;
		}
		i++;
		current = current->next;
	}
	if (m == n)
	{
		return head; //m和n相等的情况不用逆转
	}
	if (m != 1)  
	{
		//首先第一条链表不是空
		head1 = tail->next;
		tail->next = NULL;//第一条链表断开

		if (tail1 != NULL)  //第三条链表不是空
		{
			head2 = tail1->next;
			tail1->next = NULL; //第二条链表断开
		}
		
		if (head1->next != NULL)
		{
			//首先第二条链表不是空
			tail1 = reverseList(head1, &first);
			tail1->next = head1;
		}
		else
		{
			first = head1;
		}
		
		tail->next = first;  //第一条和第二条链表拼接
		head1->next = head2; //第二条和第三条链表拼接

		return head;
	}
	else
	{
		//首先第一条链表是空
		head1 = head;
		if (tail1 != NULL)  //tail1已经是链表末端
		{
			//第三条链表不是空
			head2 = tail1->next;
			tail1->next = NULL; //第二条链表断开
		}

		tail1 = reverseList(head1, &first);

		tail1->next = head1;   //还剩最后一个head1没有接到第二条链表上
		head1->next = head2;  //第二条和第三条链表拼接
		return first;
	}

}

int main()
{
	ListNode *head = NULL,*tail=NULL,*first=NULL;
	head = createNodeList(head);
	Print(head);
	head = reverseBetween(head, 1, 2);
	Print(head);
	//first = reverseHead(head);
	//Print(first);
	//head = reverseList(head);
	//Print(head);
	//head = removeElements(head, 1);
	//Print(head);
	return 0;
}