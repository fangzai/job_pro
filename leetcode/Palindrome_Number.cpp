/*
time   :  2015-5-9
author :  ht
comment:  判定回文数
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

bool isPalindrome(int x) {
	//负数不是回文数  需要判定一下是否越界
	//其实没有必要，因为只有负数才可能越界
	int min_int = -(int)pow(2, 31);
	int max_int = (int)pow(2, 31) - 1;
	if (x <0)  //if (x <= min_int)  
		return false;

	int num = abs(x);
	int len = 0;
	while (num >= 10)
	{
		len++;
		num = num / 10;
	}
	num = abs(x);
	int newNum = num;
	int i,j=len;
	int temp1;
	int temp2;
	for (i = 0; i < len; i++)
	{
		temp1 = num % 10;
		num = num / 10;
		int low = pow(10,j);  //计算底数
		temp2 = newNum/low;
		newNum = newNum%low;
		j--;
		if (temp1 != temp2)
			return false;
		if (i >=j)  //比较到中间的时候就可停止了
		{
			break;
		}
	}
	return true;
}
int main()
{
	int num = -2147447412;
	printf("%d \n", sizeof(int));
	printf("%d , %d \n", (int)pow(2, 31), (int)pow(2, 31) - 1);
	if (isPalindrome(num))
	{
		printf("%d is palindrome\n", num);
	}
	else
	{
		printf("%d is NOT palindrome\n", num);
	}
	return 0;
}