/*
time   :  2015-5-12
author :  ht
comment:  判定链表是否有环,返回环的位置
# 前面两个函数调用 intersect link list的结果
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

struct ListNode* location(struct ListNode*node, struct ListNode**addr, int*num, int len)
{
	if (node == NULL)
	{
		num[0] = 0;
		return NULL;
	}
	else
	{
		struct ListNode *temp = NULL;
		temp = location(node->next, addr, num, len);
		//返回下和节点的地址，用递归的意思是要从后往前比较

		int index = len - num[0];//计算栈的index
		if (temp == addr[index])
		{
			//分支1  
			// 如果next相同，返回当前node
			//且num要+1，就是链表后退
			num[0] += 1;
			return node;
		}
		else
		{
			//分支2  
			//否则返回next的指针  num不变了
			//最后程序从这里退出
			return temp;
		}
		//printf("%d ",num[0]);
		//num[0] --;

	}
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL)
		return NULL;
	//if (headA == headB)
	//return headA;
	struct ListNode * current = NULL, *head = NULL;;
	current = headA;
	int size = 30000;
	struct ListNode** addr1 = (struct ListNode**)malloc(size*sizeof(struct ListNode*));
	// addr1这里相当于一个栈，用于和另一个链表递归的时候比较
	//int *addr2 = (int*)malloc(size*sizeof(int));
	int len = 0;
	while (current != NULL)
	{
		addr1[len] = current;
		len++;
		current = current->next;
	}
	addr1[len] = NULL;
	current = headB;
	int num;  //用于记录倒序的index

	head = location(current, addr1, &num, len);
	//必须加上这几句  因为可能是  A链表包含B链表的情况
	//如[1,2] [2]  也就是说，这里head可能从递归函数分支1跳出来
	int index = len - num;
	if (head == addr1[index])
	{
		return head;
	}
	//num += 1;
	//printf("%d ", num);
	return head->next;
}

struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL)
		return false;
	struct ListNode *current = NULL, *current2 = NULL, *head2=NULL;

	current = head;   //这个每次走一步
	current2 = head;  //这个走两步
	//如果他们最终能够相遇的话，说明肯定是有环的
	bool mark = false;  //默认没有环
	int n = 0;
	while (true)
	{


		if (current == NULL || current2 == NULL || current2->next == NULL)
			break;
		
		if (current->next == current2->next->next&&n>0)
		{
			printf("Circled！");

			head2 = current2->next->next; 
			//剪断环  一定要用current2，
			//current2能够保证是在环里面，但是current不行
			current2->next->next = NULL;
			//return true;
			mark = true; //有环  
			//这个地方断开之后就有两个链表头了
			// head 和 head2
			break;

		}
		n++;
		current = current->next;
		current2 = current2->next->next;
		
	}

	//调用交差链表的判定函数
	if (mark)
	{
		head = getIntersectionNode(head,head2);
		return head;
	}

	return NULL;
}

int main()
{
	ListNode *head = NULL, *current = NULL, *p = NULL, *link1 = NULL, *link2 = NULL;
	int nums1[5] = { 1, 2, 3, 4,5 };
	//int nums1[4];
	int size1 = 5;
	int nums2[2] = { 5, 1 };
	//int nums2[2];
	int size2 = 2;
	link1 = createNodeList(link1, nums1, size1);
	Print(link1);
	link2 = createNodeList(link2, nums2, size2);
	Print(link2);
	current = link1->next;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			p = current;
		}

		current = current->next;
	}
	p->next = link1->next->next->next->next;
	head = detectCycle(link1);
	printf("%d \n", head->val);	
	//head = addTwoNumbers1(link1, link2);
	//Print(head);
	//head = removeElements(head, 0);
	//Print(head);
	return 0;
}