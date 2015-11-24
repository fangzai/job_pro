/*
time   :  2015-5-9
author :  ht
comment:  从链表中删除某个特定的元素
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
	int len = 4;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array[4] = { 1,1,0,0 };
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

struct ListNode* removeElements(struct ListNode* head, int val) {
	ListNode *current;
	ListNode *p = NULL;
	if (head == NULL)
	{
		printf("The link list is empty!");
		return head;
	}
	//定位要删除的节点
	current = head;
	int count = 0;



	while (current != NULL )  //while (current != NULL &&current ->next= NULL)
	{
		//p = current;

		while (current->val == val)
		{
			if (current == head)
			{
				head = current->next;  // head = head->next 也是可以的
				free(current);         //free掉
				current = head;
			}
			else
			{
				p->next = current->next;  //p是前节点， p->current -> next  
				//变成 p->next
				free(current);
				current = p->next;

			}
			count++;	
			if (current == NULL)  // 这里可能删除的是尾节点
				break;
			//current = current->next;
		}
		if (current != NULL)   // 如果current已经是空的话，就没有current->next了
		{
			p = current;
			current = current->next;
		}
	}
	/*
	current = head;
	if (current != NULL&&current->val ==val)
	{
	head = head->next;
	free(current);
	return head;

	}
	*/

	if (count>0)
	{
		current = NULL;
		printf("\n%d is found for %d times!\n", val,count);
	}
	else
	{
		printf("\n%ld not been found!\n", val);
	}
	return head;

}

int main()
{
	ListNode *head = NULL;
	head = createNodeList(head);
	Print(head);
	head = removeElements(head, 0);
	Print(head);
	//head = removeElements(head, 1);
	//Print(head);
	return 0;
}