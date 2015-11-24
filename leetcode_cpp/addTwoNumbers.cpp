/*
time   :  2015-5-11
author :  ht
comment:  两个数，每个数的digit以链表形式逆向存储，求出他们的和，结果逆向存储
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};
ListNode* createNodeList(ListNode *head,int*array,int len)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	//int len = 4;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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
struct ListNode* traverse(struct ListNode*current, int *longLink, int len, int *index, int *mark, struct ListNode* head)
{
	if (current != NULL)
	{
		struct ListNode *p = NULL;
		traverse(current->next, longLink, len, index,mark,head);
		//current = current->next;
		
		int num1 = mark[0];
		int num2 = current->val;
		if (index[0] <= len)
		{
			num1 += longLink[len - index[0]];
		}
		
		num1 += num2;
		
		current->val = num1 % 10;
		mark[0] = num1 / 10;
		index[0]++;
		if (current == head&&(mark[0] >= 1))
		{
			struct ListNode* p = NULL;
			p = (struct ListNode*)malloc(sizeof(struct ListNode));
			p->val = mark[0];
			p->next = head;
			head = p;
			return head;
		}
		else
		{
			return current;
		}
			
	}
	else
	{
		index[0] = 1;
		mark[0] = 0;
		return NULL;
	}
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	//这是正向存digit时候的程序
	struct ListNode *current, *shortLink = NULL, *longLink = NULL, *head = NULL;
	current = l1;
	int len1 = 0, len2 = 0;
	while (current != NULL)
	{
		len1++;
		current = current->next;
	}
	current = l2;
	while (current != NULL)
	{
		len2++;
		current = current->next;
	}
	int len = 0;
	if (len1 >= len2)
	{
		len = len2;
		//head = l1;
		longLink = l1;
		shortLink = l2;
	}
	else
	{
		len = len1;
		longLink = l2;
		shortLink = l1;
	}
	int *content = (int*)malloc(len*sizeof(int));
	int index = 0;
	current = shortLink;
	while (current != NULL)
	{
		content[index] = current->val;
		index++;
		current = current->next;
	}
	int mark = 0;
	index = 0;
	head = longLink;
	head = traverse(longLink, content,len, &index,&mark,head);
	return head;
}

struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2) {
	//逆向的时候存数据  这样就很简单了，连递归都不需要了
	//比正向的时候简单多了
	struct ListNode *current, *shortLink = NULL, *longLink = NULL, *head = NULL;
	current = l1;
	int len1 = 0, len2 = 0;
	while (current != NULL)
	{
		len1++;
		current = current->next;
	}
	current = l2;
	while (current != NULL)
	{
		len2++;
		current = current->next;
	}
	int len = 0;
	if (len1 >= len2)
	{
		len = len2;
		longLink = l1;
		shortLink = l2;
	}
	else
	{
		len = len1;
		longLink = l2;
		shortLink = l1;
	}

	int mark = 0;
	int num1;
	current = longLink;
	head = shortLink;
	while (current != NULL)
	{
		mark += current->val;
		if (head != NULL)
		{
			mark += head->val;
			head = head->next;
		}
		current->val = mark % 10;
		mark = mark / 10;
		if (current->next == NULL)
		{
			shortLink = current;
		}
		current = current->next;
	}
	if (mark >= 1)
	{
		current = (struct ListNode *)malloc(sizeof(struct ListNode));
		current->val = mark;
		current->next = NULL;
		shortLink->next = current;
	}
	return longLink;
}

int main()
{
	ListNode *head = NULL,*link1=NULL,*link2 =NULL;
	int nums1[4] = { 5, 9, 4, 9 };
	//int nums1[4];
	int size1 = 0;
	int nums2[2] = { 5, 1 };
	//int nums2[2];
	int size2 =0;
	link1 = createNodeList(link1,nums1,size1);
	Print(link1);
	link2 = createNodeList(link2, nums2, size2);
	Print(link2);
	head = addTwoNumbers1(link1, link2);
	Print(head);
	//head = removeElements(head, 0);
	//Print(head);
	return 0;
}