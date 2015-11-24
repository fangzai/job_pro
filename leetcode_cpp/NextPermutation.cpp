/*
time   :  2015-5-16
author :  ht
comment:  给定一个序列，生成下一个排列

算法来自 ex47
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

void swap(int*a, int*b)
{
	int temp = a[0];
	a[0] = b[0];
	b[0] = temp;
}

void reverse(int* array, int len)
{
	int *str = (int*)malloc(len*sizeof(int));
	int i = 0, j = len - 1;
	memcpy(str, array, len*sizeof(int));
	while (i < len)
	{
		array[i] = str[j];
		j--;
		i++;
	}
}
//采用对给定的字符集中的字符规定了一个先后关系，在此基础上按照顺序依次产生每个排列。
/*对给定的字符集中的字符规定了一个先后关系，在此基础上按照顺序依次产生每个排列。
*[例]字符集{1,2,3},较小的数字较先,这样按字典序生成的全排列是:123,132,213,231,312,321。
*生成给定全排列的下一个排列 所谓一个的下一个就是这一个与下一个之间没有字典顺序中相邻的
*字符串。这就要求这一个与下一个有尽可能长的共同前缀，也即变化限制在尽可能短的后缀上。
*
* 设P是[1,n]的一个全排列。
* P=P1P2…Pn=P1P2…Pj-1PjPj+1…Pk-1PkPk+1…Pn , j=max{i|Pi<Pi+1}, k=max{i|Pi>Pj} ,
对换Pj，Pk，将Pj+1…Pk-1PjPk+1…Pn翻转， P’= P1P2…Pj-1PkPn…Pk+1PjPk-1…Pj+1即P的下一个
例子:839647521的下一个排列.
从最右开始,找到第一个比右边小的数字4(因为4<7，而7>5>2>1),再从最右开始,找到4右边比4大的
数字5(因为4>2>1而4<5),交换4、5,此时5右边为7421,倒置为1247,即得下一个排列:839651247.
该方法支持数据重复，且在C++ STL中被采用。
*/
void nextPermutation(int* nums, int numsSize) {
	//这是非递归的产生全排列的算法，并且支持里面有些元素相等
	int n = numsSize;
	int tail = n - 1;
	int i, j = tail;
	int len = 1, index1, index2, reverseLen = 0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	i = 1;
	j = tail;
	reverseLen = 0;
	while ((j >= 0) && (j - 1 >= 0) && (nums[j - 1] >= nums[j]))
	{
		j--;
		reverseLen++;
	}
	//从左往右 找到第一个比右边小的数，下标  index1
	reverseLen++;
	index1 = j - 1;
	if (index1 <= -1)
	{
		//j=0的位置是最大元素
		//break;  //退出条件
	}
	else
	{
		//j = 0 位置不是最大元素，那么这个地方的肯定可以找到index2的
		j = tail;
		while ((nums[j] <= nums[index1]) && (j >= 0))
		{
			j--;
		}
		index2 = j;
		//再从左往右，找到比index1位置大的数字 下标 index2
		if (index2 <= -1)
		{
			//break;
		}
		swap(&nums[index1], &nums[index2]);
	}

	reverse(nums + index1 + 1, reverseLen);
}
int main()
{
	int list[8] = { 3, 2, 1, 1 };
	int numsSize = 0;
	int returnSize = 0;
	nextPermutation(list, numsSize);
	int i;

	for (i = 0; i < numsSize; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}