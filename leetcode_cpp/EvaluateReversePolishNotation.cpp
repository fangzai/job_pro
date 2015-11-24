/*
time   :  2015-5-19
author :  ht
comment:  关于符号表达式重建为二叉树后计算结果
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


int str2num(char*str)
{
	int len = strlen(str);
	int num = 0,temp;
	bool flag = false;
	int i;
	i = 0;
	if (str[i] == '-')
	{
		flag = true;
		i = 1;
	}
	while (i < len)
	{
		num *= 10;
		temp = str[i] - '0';
		num += temp;
		i++;
	}
	if (flag)
	{
		return -1 * num;
	}
	else
	{
		return num;
	}

}
bool symbol2(char s)
{
	if (s == '+' || s == '-' || s == '/' || s == '*')
		return true;
	return false;
}
struct TreeNode* reConstruct(struct TreeNode* current, char**tokens, int numSize, int *index)
{
	int temp = 0;
	if (index[0] == 0)
	{
		//退出条件
		int value = str2num(tokens[index[0]]);  //第一个元素不可能是符号 
		
		current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		current->val = value;
		current->left = NULL;
		current->right = NULL;
		
		return current;
	}
	else
	{
		int value;
		
		struct TreeNode*left = NULL, *right = NULL, *root = NULL;
		if (symbol2(tokens[index[0]][0]) && tokens[index[0]][1]=='\0')
		{
			//这句话原本是 if (symbol2(tokens[index[0]]）原本是直接用字符串来匹配的
			//函数symbol2函数也是这么写的，不过oj不让过，虽然vs上面是对的
			switch (tokens[index[0]][0])
			{
				//将root节点一层层地转化为 0 1 2 3表示，后面要进行中序遍历
			case '+':
				value = 0;
				break;
			case '-':
				value = 1;
				break;
			case '*':
				value = 2;
				break;
			case '/':
				value = 3;
				break;
			default:
				return NULL;
			}
			index[0]--;
			right = reConstruct(right, tokens, numSize, index);
			if ((index - 1) == 0)
			{
				left = NULL;  //后面只有一个数字了
			}
			else
			{
				//index[0]--;  //后面已经减过一次了，这里不必再减一次
				left = reConstruct(left, tokens, numSize, index);
			}
			
			current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
			current->val = value;
			current->left = left;
			current->right = right;
			root = current;
			return root;
		}
		else
		{
			value = str2num(tokens[index[0]]);
			index[0]--;
			current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
			current->val = value;
			current->left = NULL;
			current->right = NULL;
			root = current;
			//一旦遇到数字，肯定是叶节点
			return root;
		}
	}
}
int Depth(struct TreeNode*current,int depth)
{
	if ((current->left == NULL) && (current->right == NULL))
	{
		return depth;
	}
	else
	{
		int left = 0, right = 0;
		if (current->left != NULL)
		{
			left = Depth(current->left, depth+1);
		}

		if (current->right != NULL)
		{
			right = Depth(current->right, depth + 1);
		}

		return left>right ? left : right;  //其实返回值没有多大用
	}
}
int traverse(struct TreeNode*current)
{
	if (current->left == NULL&&current->right == NULL)
	{
		return current->val;
	}
	else
	{
		int leftValue = 0, rightValue = 0;
		if (current->left != NULL)
		{
			//leftValue = 0;
			leftValue = traverse(current->left);
		}
		if (current->right != NULL)
		{
			rightValue = traverse(current->right);
		}
		int temp = current->val;
		switch (temp)
		{
		case 0:
			current->val = leftValue + rightValue;
			break;
		case 1:
			current->val = leftValue - rightValue;
			break;
		case 2:
			current->val = leftValue * rightValue;
			break;
		case 3:
			current->val = leftValue / rightValue;
			break;
		default:
			break;
		}
		return current->val;
	}
}
int evalRPN(char** tokens, int tokensSize) {
	int i = tokensSize-1;
	int index = tokensSize - 1;
	struct TreeNode*left = NULL, *right = NULL,*root=NULL;
	int value = 0;
	int leftValue = 0, rightValue = 0;

	root = reConstruct(root, tokens, tokensSize, &index);
	//通过后序列重建了这棵树，接着深度优先遍历

	int result = traverse(root);

	return result;
}

int main()
{

	TreeNode* root = NULL, *p = NULL;
	
	//char*str[5] = {"2", "1", "+", "3", "*"};
	//char*str[5] = { "4", "13", "5", "/", "+" };
	char*str[3] = { "-1", "3", "/"};
	int nums = 3;
	int result = evalRPN(str, nums);
	printf("%d \n",result);
	return 0;
}