/*
time   :  2015-5-14
author :  ht
comment:  将已经排过序列的链表构造为平衡二叉搜索树
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

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
ListNode* createNodeList(ListNode *head, int *array, int len)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	//int len = 4;
	//int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//int array[4] = { 1, 1, 0, 0 };
	int i;
	ListNode * p1 = NULL;  // p1 保存创建的新节点的地址
	ListNode * p2 = NULL;  // p2 保存链表的最后一个节点的地址
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p2 = p1;
	if (len <= 0)
	{
		head = NULL;   //特殊情况  产生空链表
		return head;
	}

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

struct ListNode* locate(struct ListNode* head,int n)
{
	// n表示位置
	struct ListNode* current = NULL;
	current = head;
	int i = 0;
	while (i < n)
	{
		current = current->next;
		i++;
	}
	return current;
}


struct TreeNode* Node(struct TreeNode* current, struct ListNode *head, int len)
{
	// len表示链表的长度
	current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	int midIndex = len / 2;
	//获取断开节点的上一个ListNode

	if (len <= 2)
	{
		//考虑两种特殊情况，一种是只剩一个元素了
		//还有一个是只剩连个元素了
		if (len == 1)
		{
			current->val = head->val;
			current->left = NULL;
			current->right = NULL;
			free(head);   
			head = NULL;
			//不知道为什么  在leetcode上必须去掉这些指针销毁才能通过
			//好奇怪的bug  但是vs上是没有任何问题的
		}
		else
		{
			current->val = head->next->val;
			struct ListNode *p = head->next;
			head->next = NULL;

			current->left = Node(current->left, head, 1);
			//只剩下一个了
			current->right = NULL;
			free(p);
			p = NULL;
		}

	}
	else
	{
		struct ListNode *p = NULL, *p1 = NULL, *head2 = NULL;  
		p = locate(head,midIndex-1);  //记录要清除节点的上一个节点
		p1 = p->next;  //记录这个临时节点
		head2 = p1->next;

		current->val = p1->val;
		p->next = NULL;

		free(p1);
		int len1 = midIndex;
		current->left = Node(current->left, head, midIndex);
		//left这边的是从array中 0开始到midIndex-1
		int len2 = len - midIndex - 1;
		current->right = Node(current->right, head2, len2);
	}

	return current;

}

struct TreeNode* sortedListToBST(struct ListNode* head) {
	struct TreeNode* root = NULL;
	struct ListNode* current = NULL;
	if (head == NULL)
		return NULL;
	int len = 0;
	current = head;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	root = Node(root,head,len);
	return root;
}
int main()
{
	//int value[6] = { 1,-1,2,3,-1,2};
	int value[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	//int value[15] = { 1, 2, 4, -1, -1, 5, -1, -1, 2, 5, -1, -1, 2, -1, -1 };
	TreeNode* root = NULL, *p = NULL;
	int index = 0;
	int nums = 2;
	for (int i = 0; i < nums; i++)
		value[i] -= 1;
	ListNode* head = NULL;

	head = createNodeList(head,value,nums);
	//head = locate(head, 3);
	//printf("%d \n",head->val);
	Print(head);

	root = sortedListToBST(head);
	//root = Node(root, value, nums);
	//root = sortedArrayToBST(value, nums);
	return 0;
}