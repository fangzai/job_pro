#include<iostream>
using namespace std;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int i=0,j=0;
	int *mySum = (int *)malloc(2*sizeof(int));
	int temp;
	for(i=0;i<numsSize;i++)
	{
		for(j=i+1;j<numsSize;j++)
		{
			temp = nums[i] + nums[j];
			if(temp == target)
			{
				mySum[0] = i;
				mySum[1] = j;
				return mySum;
			}
		}
	}
    
}
int main()
{
	int *nums;
	int input[4] = {2,7,11,15};
	int target =9;
	int numsSize = 4;
	nums = new int[numsSize];
	for(int i =0;i<numsSize;i++)
	{
		nums[i] = input[i];
		cout<<nums[i]<<endl;
	}

	int * index = twoSum(nums, numsSize, target);
	cout<<index[0]<<endl<<index[1]<<endl;
	free(nums);
	free(index);
	return 1;
}