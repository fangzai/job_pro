#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int removeElement(int* nums, int numsSize, int val) {
	int * myNum = (int *)malloc(numsSize*sizeof(int));
	int i;
	int len = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			myNum[len] = nums[i];
			len++;
		}
	}
	memcpy(nums, myNum, len*sizeof(int));  //把数据再拷贝回去
	for (i = 0; i < len; i++)
	{
		printf("%d  ", myNum[i]);
	}
	printf("\n");

	free(myNum);
	return len;
}

int main()
{
	int nums[7] = {0,1,0,3,0,0,3};
	int numSize = 7;
	int value = 0;
	printf("%d \n", removeElement(nums,numSize,value));
	return 0;
}