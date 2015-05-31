/*
time   :  2015-5-10
author :  ht
comment:  交叉链表找出连接点
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
ListNode* createNodeList(ListNode *head, ListNode **link,int label)  // i表示返回链表的标号
{
	head = (ListNode*)malloc(sizeof(ListNode));
	int len1 = 5;
	int array1[5] = { 1, 3, 2, 5, 7};
	int array2[5] = { 1,3,4,5,6 };
	int len2 = 5;
	int i;
	ListNode * p1 = NULL;  // p1 保存创建的新节点的地址
	ListNode * p2 = NULL;  // p2 保存链表的最后一个节点的地址
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p2 = p1;
	if (len1 <= 0)
	{
		head = NULL;   //特殊情况  产生空链表
		return head;
	}

	for (i = 0; i < len1; i++)
	{
		p1->val = array1[i];

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

	link[0] = head;

	if (label == 2)
	{
		//array2链接链表上去
		ListNode* head1 = (ListNode*)malloc(sizeof(ListNode));
		p1 = (ListNode*)malloc(sizeof(ListNode));
		p2 = p1;
		ListNode * current = NULL;
		current = head;
		for (i = 0; i < len2; i++)
		{
			p1->val = array2[i];

			if (i == 0)
			{
				head1 = p1;
				p2->next = NULL;  //此时的p2就是p1，首次赋值的时候将p2指向空
				current = current->next;

			}
			else
			{
				p2->next = p1;   //指向上次下面刚刚开辟的新节点
				current = current->next;
			}

			p2 = p1;    //把p1的地址给p2保留，然后p1产生新的节点

			p1 = (ListNode*)malloc(sizeof(ListNode));  // 开辟新的地址
		}
		p2->next = current;

		free(p1);
		p1 = NULL;
		return head1;

	}

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
		temp = location(node->next, addr, num,len); 
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
	struct ListNode * current = NULL,* head=NULL;;
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
	
	head = location(current,addr1,&num,len);
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

int main()
{
	ListNode *link1 = NULL, *link2 = NULL, *head = NULL;

	int array1[5] = { 1, 5, 7, 8, 9 };
	int num1 = 5;
	int *array2 = NULL;
	int num2 = 0;
	//link1 = createNodeList(link1,1);
	//Print(link1);

	link2 = createNodeList(link2,&link1, 2);
	Print(link1);
	Print(link2);
	
	head = getIntersectionNode(link1,link2);
	Print(head);
	return 0;
}