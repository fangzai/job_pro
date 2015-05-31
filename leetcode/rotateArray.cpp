#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
//首先想到的方法就是直接移动
void rotate(int* nums, int numsSize, int k) {
	k=k%numsSize;
	int step,i,temp;
	int *newNum=(int*)malloc((numsSize-1)*sizeof(int));
	for(step = 0; step<k;step++)
	{
		int moveIndex =  numsSize-k+step;
		temp = nums[numsSize-1];
		memcpy(newNum,nums,(numsSize-1)*sizeof(int));  
		memcpy(nums+1,newNum,(numsSize-1)*sizeof(int));
		//memcpy(nums+1,nums,(numsSize-1)*sizeof(int));
		//for(i=moveIndex;i>0;i--)
		//{
			//nums[i] = nums[i-1];
		//}
		
		nums[0] = temp;
	}
	/*
	k = k%numsSize;
	int *newNum=(int*)malloc(numsSize*sizeof(int));   //这个应该说是最快的
	memcpy(newNum+k,nums,(numsSize-k)*sizeof(int));
    memcpy(newNum,nums+numsSize-k,k*sizeof(int));
	memcpy(nums,newNum,numsSize*sizeof(int));
	*/
	free(newNum);
}

int main()
{
	int nums[7]={1,2,3,4,5,6,7};
	int numSize = 7;
	int k = 2;
	rotate(nums,numSize,k);
	int i =0;
	for(i=0;i<numSize;i++)
	{
		printf("%d  ",nums[i]);
	}
	printf("\n");
	return 0;
}