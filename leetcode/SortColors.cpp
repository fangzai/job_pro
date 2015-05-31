/*
time   :  2015-5-18
author :  ht
comment:  给三种颜色分类排序，貌似用的是计数排序
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

void sortColors(int* nums, int numsSize) {
	//相当于遍历了两遍，其实和题目的要求不太一样，题目要求，只遍历一遍
	//而且需要常数空间分配
	int num1, num2, num3, i;
	num1 = num2 = num3 = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == 0) num1++;
		if (nums[i] == 1) num2++;
		if (nums[i] == 2) num3++;
	}
	int k = 0;
	while (num1--) nums[k++] = 0;
	while (num2--) nums[k++] = 1;
	while (num3--) nums[k++] = 2;
}

//http://www.cnblogs.com/felixfang/p/3680047.html
void sortColors1(int* nums, int numsSize)
{
	int i = -1, j = -1, k = -1;

	//我擦 这个方法吊炸天
	//i  j  k分别用来指向 0 1 2最后排列的位置
	for (int p = 0; p < numsSize; p++)
	{
		if (nums[p] == 0)
		{
			//如果是0的话，因可能已经出现了1和2了
			//所以1 2的计数pointer都要往后挪一个位置
			//必须先挪2 再挪1
			//最后把0 方在i+1指向的位置
			nums[++k] = 2;
			nums[++j] = 1;
			nums[++i] = 0;
		}
		else if (nums[p] == 1)
		{
			//如果是1的话，0就不管了，反正又不动
			//直接挪后面一个2就可以了
			nums[++k] = 2;
			nums[++j] = 1;

		}
		else if (nums[p] == 2)
		{
			//如果是2的话就没有什么说的了直接附加到k+1的位置上
			nums[++k] = 2;
		}
	}
}

int main()
{
	return 0;
}