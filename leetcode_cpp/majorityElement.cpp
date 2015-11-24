#include<iostream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

int majorityElement(int* nums, int numsSize) {
	int i,j;
	int *count = (int*)malloc(numsSize*sizeof(int));
	for(i=0;i<numsSize;i++)
	{
		count[i] = 0;
	}
	int result = -1;
	int mycounter =0;
	srand( (unsigned)time( 0) ); 
	while(true)
	{
		mycounter=0;
		i = rand()%numsSize;
		for(j=0;j<numsSize;j++)
		{
			if(nums[i] == nums[j])
			{
				mycounter++;
			}
		}
		if(mycounter>numsSize/2)
		{
			result =nums[i];
			break;
		}
	}
	/*
	for(i=0;i<numsSize;i++)
	{
		for(j=0;j<numsSize;j++)
		{
			if(nums[i] == nums[j])
			{
				count[i]++;
			}
		}
		if(count[i]>numsSize/2)
		{
			result =count[i];
			break;
		}
	}*/
	return result;
    //return -1;
}
int majorityElement1(int* nums, int numsSize)
{
	//因为比别人多还有另外一种解释，就是你的票抵消了我的一部分票后，我还有剩。  
	//使用投票策略，因为要求多数票,很明显过半了的，肯定就是需要的
	int i,j;
	/*
	int *count = (int*)malloc(numsSize*sizeof(int));
	for(i=0;i<numsSize;i++)
	{
		count[i] = 0;
	}*/
	int counter =0;
	int result = -1;
	int currentCanditate;
	for(i=0;i<numsSize;i++)
	{
		if(counter==0)
		{
			currentCanditate = nums[i];
			counter++;
		}
		else
		{
			if(currentCanditate == nums[i])
			{
				counter++;
			}
			else
			{
				counter--;
			}
		}
	}
	//free(count);
	return currentCanditate;
}


int main()
{
	int nums[5]={2,3,2,3,2};
	printf("%d \n",majorityElement(nums, 5));
	return 0;
}
