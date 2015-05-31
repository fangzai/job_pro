/*
time   :  2015-5-15
author :  ht
comment:  删除链表中出现重复的元素
          这个题的难度比ex81高一些，因为需要重复的都删掉
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
	int len = 1;
	int array[10] = { 0, 0, 2, 2, 3, 3, 4, 4, 5, 5 };
	//int array[4] = { 1, 1, 0, 0 };
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

bool traverse(struct ListNode*head,int val)
{
	//判定当前节点是否有重复
	//如果有重复，就把后面的重复节点删除
	//然后返回true，退出后再删当前节点
	struct ListNode * current, *p = NULL;
	current = head;
	
	int deleteVal = val;
	bool del = false;
	while (current->next != NULL&&current->next->val == val)
	{
		del = true;
		p = current->next;

		current->next = p->next;
		free(p);
		p = NULL;
		
	}
	return del;
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode * current, *p = NULL;
	if (head == NULL)
		return NULL;

	// 在head前面添加一个INT_MIN的值,这样就可以避免一直删head的问题
	p = (struct ListNode*)malloc(sizeof(struct ListNode));
	p->val = INT_MIN;
	p->next = head;
	head = p;

	current = head;
	int val = current->val;
	bool mark;

	while (current->next!=NULL&&current->next->next != NULL)
	{
		val = current->next->val;
		// 查找下一节点的值
		//搜索 current->next之后的节点是否和current->next节点值一样
		mark = traverse(current->next, val);
		//如果一样的话就要删除current->next节点
		if (mark)  //删除current->next节点
		{
			p = current->next;
			current->next = p->next;
			free(p);
			p = NULL;
		}
		else
		{
			//current->next是单节点，直接过去
			current = current->next;
		}

	}
	
	p = head;
	head = head->next;
	free(p);
	p = NULL;
	return head;
}

int main()
{
	ListNode *head = NULL;
	head = createNodeList(head);
	Print(head);
	head = deleteDuplicates(head);
	Print(head);
	//head = removeElements(head, 1);
	//Print(head);
	return 0;
}