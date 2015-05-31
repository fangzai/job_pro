/*
time   :  2015-5-12
author :  ht
comment:  一组整数，里面只有一个数出现一次，其他所有数字出现的两次
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int singleNumber(int* nums, int numsSize) {
	/* 反正我想的就是暴力搜索，肯定会超过时间限制的
	 * 参照网上的思路用异或求解
	 * a^0 = a
	 * a^a = 0
	 * a^b = b^a
	 */

	int i = 0;
	int target = nums[0];
	for (i = 1; i < numsSize; i++)
	{
		target = target^(nums[i]);
	}
	return target;
}

int main()
{
	int nums[5] = { 1, 2, 3, 3, 2 };
	int numSize = 5;
	printf("%d \n", singleNumber(nums, numSize));
	return 0;
}