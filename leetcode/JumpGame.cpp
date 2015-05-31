/*
time   :  2015-5-18
author :  ht
comment:  跳棋游戏
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

bool traverse(int* nums, int numsSize, int index)
{
	//写了一个递归程序 超时了
	int maxStep = nums[index];
	if ((index + maxStep) >= (numsSize - 1))
	{
		return true;
	}
	else
	{
		bool mark = false;
		int nextIndex = index;

		for (int i = maxStep; i >= 1; i--)
		{
			//nextIndex= nums[index];
			//nextIndex += i;
			mark = traverse(nums, numsSize, nextIndex + i);
			if (mark)
				return true;
		}
		return false;
	}
}

bool canJump1(int* nums, int numsSize) {

	int nextIndex = 0;
	int i = 0, j;
	bool mark = traverse(nums, numsSize, 0);

	return mark;
}
bool canJump(int* nums, int numsSize)
{
	/*
	 * 用贪心策略，刚开始step = A[0]，到下一步step--,
	 * 并且取step = max(step, A[1])，这样step一直是保持最大的能移动步数，局部最优也是全局最优。
	 */

	if (numsSize == 0)
		return false;
	int step = nums[0];

	for (int i = 1; i < numsSize; i++)
	{
		if (step > 0)
		{
			step--;
			step = step> nums[i]?step:nums[i];
		}
		else
			return false;
	}
	return true;
}
int main()
{
	int nums[10] = { 1, 0, 1, 1, 4 };
	//int nums[10] = {3,2,1,0,4};
	//int nums[10] = { 1,2,3 };
	int numSize = 1;
	if (canJump(nums, numSize))
	{
		printf("Ok, can finish the jump! \n");
	}
	else
	{
		printf("NO, can't finish the jump! \n");
	}
	return 0;
}