/*
time   :  2015-5-12
author :  ht
comment:  完成链表的交叉倒序
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
struct ListNode* traverse(struct ListNode* current, struct ListNode *head, int frontIndex, int*tailIndex,struct ListNode **pointer)
{
	// pointer[0]的功能是指向当前节点需要改变的位置（前面）
	// 避免每次重复迭代找这个未知
	// current是后面要改变的位置
	struct ListNode*p1=NULL, *p2 = NULL,*temp=	NULL;
	if (current->next->next == NULL)
	{
		//index[0] = 0;
		pointer[0] = head->next;
		p1 = current->next;
		p2 = head->next;
		head->next = p1;
		p1->next = p2;
		current->next = NULL;
		tailIndex[0] = 0;
		
		return current;
	}
	else
	{
		int location = 0;
		frontIndex++;
		temp = traverse(current->next, head, frontIndex, tailIndex, pointer);
		tailIndex[0]++;
		
		int i=0;
		if (frontIndex > tailIndex[0])
		{	
			//因为限定了frontIndex的，所以current不会跑到p1的前面去
			//注意这个地方的判定条件
			p1 = current->next;
			p2 = pointer[0]->next;
			if (p1 != p2)
			{
				//递归退出的条件
				pointer[0]->next = p1;
				p1->next = p2;
				pointer[0] = p2;
				//每次递归结束的时候pointer就是指向下一个要交换的地方
				//该表链表指向
				current->next = NULL;
			}
			return current;
		}
		else
		{
			return head;
		}

	}
}
void reorderList(struct ListNode* head) {
	int frontIndex = 0,tailIndex,len=0;
	struct ListNode*current=NULL,*pointer=NULL;

	current = head;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	if (head == NULL)
	{
		head = NULL;
	}
	else
	{
		
		if (head->next == NULL||head->next->next==NULL)
		{
			//head = NULL;
			int n = 0;
		}
		else
		{
			head = traverse(head, head, frontIndex, &tailIndex,&pointer);
		}
	}
	
}

//用环状链表做一个
struct ListNode* traverse1(struct ListNode* current, struct ListNode *head)
{
	 // pointer的下一个指向的是要添加的位置，pointer本身在这次递归中被干掉
	struct ListNode* virtualHead = NULL, *p1 = NULL, *p2 = NULL,*temp=NULL;
	
	if (current->next->next == NULL)
	{
		//删除链表的最后一个
		current->next->next = head;
		virtualHead = head;
		p1 = current->next;
		p2 = virtualHead->next;

		virtualHead->next = p1;
		p1->next = p2;

		virtualHead = virtualHead->next->next;
		//current->next = virtualHead;
		current->next = NULL;
		return virtualHead;
	}
	else
	{
		virtualHead = traverse1(current->next, head);
		if (virtualHead == head)
			return head;//递归结束
		p1 = current->next;
		p2 = virtualHead->next;
		if (p1 != p2&&p1->next!=virtualHead)
		{
			//这里是两种退出情况，一种是p1 和 p2重叠了
			//还有一种是上一次递归中，virtualHead后面就是current
			//而到了这里之后就是 current在 vhead后面间隔一个位置
			virtualHead->next = p1;
			p1->next = p2;
			virtualHead = virtualHead->next->next;
			//current->next = virtualHead;
			current->next = NULL;
			return virtualHead;
		}
		else
		{
			return head;
		}
		
	}
	
	return false;
}
void reorderList1(struct ListNode* head) {

	if (head == NULL)
	{
		head = NULL;
	}
	else
	{

		if (head->next == NULL || head->next->next == NULL)
		{
			//head = NULL;
			int n = 0;
		}
		else
		{
			head = traverse1(head, head);
		}
	}

	//head 链表递归 head2正常遍历

}
int main()
{
	ListNode *head = NULL, *current = NULL, *p = NULL, *link1 = NULL, *link2 = NULL;
	int nums1[5] = { 1, 2, 3, 4 ,5};
	//int nums1[4];
	int size1 = 4;
	int nums2[2] = { 5, 1 };
	//int nums2[2];
	int size2 = 2;
	link1 = createNodeList(link1, nums1, size1);
	Print(link1);
	link2 = createNodeList(link2, nums2, size2);
	Print(link2);
	//current = link1->next;
	reorderList1(link1);
	Print(link1);
	//head = addTwoNumbers1(link1, link2);
	//Print(head);
	//head = removeElements(head, 0);
	//Print(head);
	return 0;
}