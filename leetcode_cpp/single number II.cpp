/*
time   :  2015-5-12
author :  ht
comment:  一组整数，除了其中某个数字，其他所有数字出现的3次,
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int singleNumber(int* nums, int numsSize) {
	/* 统计每个bit出现的次数如果某个地方出现的次数不是3的倍数，则这个未知为1
	* 还是位操作，出现三次的他们每个位置上的1加起来mod3肯定等于0
	* a^0 = a
	* a^a = 0
	* a^b = b^a
	*/
	int number[32] = { 0 };
	int i, j;
	for (i = 0; i < numsSize; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (nums[i] & (1<<j)) 
			{ 
				//左移j位，取出第j位
				number[j]++;
			}
		}
	}
	int result = 0;
	
	for (i = 31; i >=0; i--)
	{
		result *= 2;
		if (number[i] % 3 != 0)
		{
			//result += (1 << i);
			result += number[i]%3;
		}
	}
	//for (int i = 0; i < 32; ++i)
	//{
	//	if (number[i] % 3 != 0)
	//	{
	//		result += (1 << i);
	//	}
	//}
	return result;
}
int singleNumber1(int* nums, int numsSize) {
	// 我表示对这种方法看的不是很明白~~~~
	//总的来说，就是统计各个二进制位1出现的次数。  
	//可以用one,two的每个二进制位分别代表对应位1出现的次数对三取模为1、2。  
	//另外one,two的某个二进制位都为0时，则表示那位1出现的次数取模正好为0。  
	int one = 0, two = 0; //刚开始在每位上1都没出现，所以都是0。  
	int three = 0; //当one,two的某个二进制位都为1时，表明已经出现了三次，可以取模。  

	for (int i = 0; i < numsSize; ++i)
	{
		two |= one&nums[i];
		one ^= nums[i];
		three = one&two;
		//当出现三次后，one,two清0，相当于取模  
		one &= ~three;
		two &= ~three;
	}

	return one | two; //因为不知道那个数是出现一次还是两次，所以将出现一次或两次的都返回
}

int main()
{
	int nums[7] = { 2, 2, 3, 2 };
	//cout << (1 << 7) << endl;
	int numSize = 4;
	printf("%d \n", singleNumber1(nums, numSize));
	return 0;
}