#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int removeDuplicates(int* nums, int numsSize) {
	int i;
	int pointer = 0;  //当前指向的位置
	//int step = 0;
	if (numsSize <= 0)   //防止出现数组为空的情况下还进行下面的操作
	{
		return 0;
	}
	int current;
	for (i = 1; i < numsSize; i++)
	{
		//current = nums[i];

		
		while ((nums[i] == nums[pointer]) && (i<numsSize))
		{
			i++;
		}
		if (i < numsSize)  //防止已经遍历到最后了还在进行pointer的操作
		{
			pointer++;  //指向下一个未重复的数据
			nums[pointer] = nums[i];
		}

	}
	for (i = 0; i <= pointer; i++)
	{
		printf("%d  ", nums[i]);
	}
	printf("\n");
	return pointer+1;
}

int main()
{
	int nums[10] = {1,1,1,2,2,3,3,4,4,9};
	int numSize = 2;
	printf("%d \n", removeDuplicates(nums,numSize));
	return 0;
}