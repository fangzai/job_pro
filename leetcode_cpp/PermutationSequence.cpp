/*
time   :  2015-5-13
author :  ht
comment: 1-n的数字生成全排列，并输出
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//void swap(int&a, int&b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
void swap(char*a, char*b)
{
	char temp = a[0];
	a[0] = b[0];
	b[0] = temp;
}
void Perm(int *list, int k, int m)
{
	int i = 0;
	if (k == m)
	{	
		//退出条件	
		printf("=====================================");
		for (i = 0; i <= k; i++)
		{
			printf("%d ", list[i]);
		}
		printf("\n");

	}
	else
	{
		for (i = k; i <= m; i++)
		{
			swap(&list[k], &list[i]);
			Perm(list, k + 1, m);
			swap(&list[k], &list[i]);
		}
	}
}
void traverse(char*list,int current,int m, int k, char*result, int*index)
{
	//这是普通的递归算法，生成的并不是字典序列
	//所以这个解题是不对的
	int i = 0;
	if (current == m)
	{
		index[0]++;
		printf("%d ====",index[0]);
		for (i = 0; i <= m; i++)
		{
			printf("%c ", list[i]);
		}
		printf("\n");
		if (index[0] == k)
		{
			memcpy(result, list, (m + 1)*sizeof(char)); 
			//原来又是这里错了
			result[m+1] = '\0';
		}
		//if (index[0] == k)
			//return;
	}
	else
	{
		for (i = current; i <= m; i++)
		{
			if (index[0] <= k)
			{
				swap(list[current], list[i]);
				traverse(list, current + 1, m, k, result, index);
				swap(list[current], list[i]);
			}
		}
	}
}
char* getPermutation(int n, int k) {
	int len = 1, i = 0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	if (k > len)
	{
		return NULL;
	}
	char*list = (char*)malloc((n+1)*sizeof(char));
	char*result = (char*)malloc((n + 1)*sizeof(char));
	
	for (i = 0; i < n; i++)
	{
		list[i] = i + '0'+1;
	}
	list[i] = '\0';
	int index = 0;
	int current = 0;
	int m = n - 1;
	traverse(list, current, m, k, result, &index);
	result[n] = '\0';
	free(list);
	return result;
}
void reverse(char*array, int len)
{
	char*str = (char*)malloc(len*sizeof(char));
	int i = 0,j = len-1;
	memcpy(str, array, len);
	while (i < len)
	{
		array[i] = str[j];
		j--;
		i++;
	}
}
char* traverse1(char*list,int n,int k)
{
	int tail = n - 1;
	int i,j = tail;
	int len = 1,index1,index2,reverseLen=0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	i = 1;
	//printf("%d  =====%s \n",i, list);
	if (k == 1)
		return list;
	for (i = 2; i <= len; i++)
	{
		j = tail;
		reverseLen = 0;
		while ((j >= 0) && (j - 1 >= 0) && (list[j - 1] >= list[j]))
		{
			j--;
			reverseLen++;
		}
		reverseLen++;
		index1 = j-1;
		j = tail;
		while ((list[j] <= list[index1]))
		{
			j--;
		}
		index2 = j;
		swap(&list[index1],&list[index2]);
		reverse(list+index1+1,reverseLen);

		//printf("%d  =====%s \n", i, list);
		if (i == k)
		{
			//return list;
			break;
		}
	}
	return list;
}
char* getPermutation1(int n, int k) {
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
	int len = 1, i = 0;
	for (i = 1; i <= n; i++)
	{
		len = len*i;
	}
	if (k > len)
	{
		return NULL;
	}
	char*list = (char*)malloc((n + 1)*sizeof(char));

	for (i = 0; i < n; i++)
	{
		list[i] = i + '0' + 1;
	}
	list[i] = '\0';
	int m = n - 1;
	char* result = traverse1(list, n, k);
	//result[n] = '\0';
	return result;

}
char* getPermutation2(int n, int k) {
	//用lehmer码来计算
	//http://blog.csdn.net/chen895281773/article/details/12357703
	//http://www.cnblogs.com/friends-wf/p/3676848.html
	int *factor = (int*)malloc((n+1)*sizeof(int));
	int len = 1,j, i = 0;
	factor[0] = 1;
	for (i = 1; i <= n; i++)
	{
		factor[i] = factor[i - 1] * i;
	}
	bool* visited = (bool *)malloc(10 * sizeof(bool));
	for (i = 0; i < 10; i++)
		visited[i] = false;

	k--; //因为下标是从0开始的
	int code;
	char*list = (char*)malloc((n + 1)*sizeof(char));
	int current = 0;
	int resultIndex = 0;
	for (i = n-1; i >=0; i--)
	{
		code = k / factor[i];
		k = k%factor[i];
		// code 是当前维护的 1-9集合里面的下标
		current = 0;
		for (j = 0; j < 9; j++)
		{
			if (!visited[j])
			{
				current++;
			}
			if (current == (code+1))
			{
				visited[j] = true;
				break;
			}
		}
		list[resultIndex++] = j+'1';
	}
	list[n] = '\0';
	return list;
}
int main()
{
	int list[3] = {1,2,3};
	char* result=getPermutation2(4,6);
	//Perm(list, 0, 2);
	printf("%s \n", result);
	system("pause");
	return 0;
}