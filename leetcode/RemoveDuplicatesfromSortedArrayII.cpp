/*
time   :  2015-5-12
author :  ht
comment:  每个元素至多出现2次，去掉多余的
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int removeDuplicates(int* nums, int numsSize) {
	int i;
	int pointer = 0;
	//int step = 0;
	if (numsSize <= 0)
	{
		return 0;
	}
	int current;
	int count = 0;
	
	for (i = 0; i < numsSize; )
	{
		current = nums[pointer]; //pointer就是当前指针判断的地方
		count = 0;
		while ((current == nums[i]) && (i<numsSize))
		{
			//下标循环需要再调一下
			if (count <= 1)   //这里的1+1就是最大出现出现次数
			{
				nums[pointer] = nums[i];  //每次出现都后移
				pointer++;
			}
			i++;
			count++;
		}
		if (count == 0)
		{
			i++;//如果只出现了一次就直接过去了
		}
		nums[pointer] = nums[i];  //i 覆盖pointer
	}
	for (i = 0; i < pointer; i++)
	{
		printf("%d  ", nums[i]);
	}
	printf("\n");
	return pointer;
}

int main()
{
	int nums[] = { 1, 1, 1, 1,1,2,2 ,2,3,3};
	//int nums[] = { 1, 2, 2, 2, 3, 3 };
	int numSize = 1;
	printf("%d \n", removeDuplicates(nums, numSize));
	return 0;
}