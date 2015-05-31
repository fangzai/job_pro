/*
time   :  2015-5-17
author :  ht
comment:  实现k的已经排序链表的融合
//我这里得到的复杂度是nklogk，没有达到用堆建立得到的最好结果nlogk
//这个题mark一下以后再分析
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

struct ListNode* merge(struct ListNode** lists, int start,int end) {
	int mid = (start + end) / 2;
	struct ListNode *head = NULL;

	if (mid == start)
	{ 
		//两种特殊情况，一种是start和end重合
		//另一种start+1 == end，这种则是会导致start==mid==end
		if (end == start)
		{
			return lists[start];
		}
		else
		{
			head = merge_list(lists[start], lists[end]);
		}
	}
	else
	{
		struct ListNode *head1 = NULL, *head2 = NULL;
		head1 = merge(lists, start, mid);  // 二分法 归并
		head2 = merge(lists, mid+1, end);
		head = merge_list(head1,head2);
	}

	return head;

}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	
	if (listsSize <= 0)
		return NULL;
	int start = 0,end = listsSize-1;
	struct ListNode *head = NULL;
	head = merge(lists, start, end);
	return head;
}

int main()
{
	ListNode *head1 = NULL, *head2 = NULL, *head3 = NULL, *head4 = NULL;

	//int  nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int  nums1[10] = { 1,4,9 };
	int len1 = 3;
	head1 = createNodeList(head1, nums1, len1);
	Print(head1);

	int  nums2[10] = { 0, 7, 8,8 };
	int len2 = 4;
	head2 = createNodeList(head2, nums2, len2);
	Print(head2);


	int  nums3[10] = { 2, 3, 3, 10,13 };
	int len3 = 5;
	head3 = createNodeList(head3, nums3, len3);
	Print(head3);

	int k = 1;
	struct ListNode** lists = (struct ListNode**)malloc(k*sizeof(struct ListNode*));
	lists[0] = head1;
	lists[1] = head2;
	lists[2] = head3;

	head1 = mergeKLists(lists, k);

	Print(head1);
	return 0;
}