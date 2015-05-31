/*
time   :  2015-5-11
author :  ht
comment:  判定链表是否有环
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
ListNode* createNodeList(ListNode *head, int*array, int len)
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
bool hasCycle(struct ListNode *head) {
	if (head == NULL)
		return false;
	struct ListNode *current = NULL, *current2 = NULL;

	current = head;   //这个每次走一步
	current2 = head;  //这个走两步
	//如果他们最终能够相遇的话，说明肯定是有环的
	int n = 0;
	while (true)
	{

		if (current == current2&&n>0)
		{
			printf("Circled！");
			return true;
		}
		if (current == NULL || current2 == NULL || current2->next == NULL)
			break;
		//if (n > 100)
		//{
		//	printf("There is bug!");
		//	break;
		//}

		n++;
		current = current->next;
		current2 = current2->next->next;
	}
	return false;
}

int main()
{
	ListNode *head = NULL,*current=NULL,*p=NULL, *link1 = NULL, *link2 = NULL;
	int nums1[4] = { 5, 9, 4, 9 };
	//int nums1[4];
	int size1 = 4;
	int nums2[2] = { 5, 1 };
	//int nums2[2];
	int size2 = 2;
	link1 = createNodeList(link1, nums1, size1);
	Print(link1);
	link2 = createNodeList(link2, nums2, size2);
	Print(link2);
	current = link1->next;
	while (current!=NULL)
	{
		if (current->next == NULL)
		{
			p = current;
		}

		current = current->next;
	}
	p->next = link1;
	hasCycle(link1);
	//head = addTwoNumbers1(link1, link2);
	//Print(head);
	//head = removeElements(head, 0);
	//Print(head);
	return 0;
}