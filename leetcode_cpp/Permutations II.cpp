/*
time   :  2015-5-15
author :  ht
comment:  数字生成全排列，并输出(与46相比，可能有重复数字)

		  算法来自 ex60
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
int** traverse(int*list, int n, int**result, int* returnSize)
{
	//这是非递归的产生全排列的算法，并且支持里面有些元素相等
	int tail = n - 1;
	int i, j = tail;
	int len = 1, index1, index2, reverseLen = 0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	i = 1;
	memcpy(result[0],list,n*sizeof(int));
	returnSize[0]++;
	//for (i = 0; i < n; i++)
	//{
	//	printf("%d ", list[i]);
	//}
	//printf("\n");
	for (i = 1; i < len; i++)
	{
		j = tail;
		reverseLen = 0;
		while ((j >= 0) && (j - 1 >= 0) && (list[j - 1] >= list[j]))
		{
			j--;   
			reverseLen++;
		}
		//从左往右 找到第一个比右边小的数，下标  index1
		reverseLen++;
		index1 = j - 1;
		if (index1 <= -1)
		{
			break;  //退出条件
		}
		j = tail;
		while ((list[j] <= list[index1]) && (j >= 0))
		{
			j--;
		}
		index2 = j;  
		//再从左往右，找到比index1位置大的数字 下标 index2
		if (index2 <= -1)
		{
			break;
		}
		swap(&list[index1], &list[index2]);
		reverse(list + index1 + 1, reverseLen);
		memcpy(result[i], list, n*sizeof(int));
		//for (i = 0; i < n; i++)
		//{
		//	printf("%d ", list[i]);
		//}
		//printf("\n");
		returnSize[0]++;
	}
	return result;
}
int** permuteUnique(int* nums, int numsSize	, int* returnSize)  {
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
	int len = 1, i = 0,j;
	returnSize[0] = 0;
	for (i = 1; i <= numsSize; i++)
	{
		len = len*i;
	}
	
	int**result = (int**)malloc(len*sizeof(int*));
	for (i = 0; i < len; i++)
	{
		result[i] = (int*)malloc(numsSize*sizeof(int));
	}

	//对于nums应该先排序
	for(i = 0; i < numsSize;i++)
	{
		int temp = nums[i];
		for (j = i; j < numsSize; j++)
		{
			if (nums[i]>nums[j])
			{
				swap(&nums[i],&nums[j]);
			}
		}
	}
	
	result = traverse(nums, numsSize,result, returnSize);
	return result;

}
int main()
{
	int list[8] = { 2,2,1,1 };
	int numsSize = 4;
	int returnSize = 0;
	int** result = permuteUnique(list, numsSize, &returnSize);

	int i, j;
	for (j = 0; j < returnSize; j++)
	{
		printf("%d  ===================================== ", j);
		for (i = 0; i < numsSize; i++)
		{
			printf("%d ", result[j][i]);
		}
		printf("\n");
	}
	return 0;
}