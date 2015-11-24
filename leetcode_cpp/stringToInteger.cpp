/*
time   :  2015-5-9
author :  ht
comment:  读取字符串转化为数字

*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

bool isIn(char str)
{
	if (str >= '0'&&str <= '9')
	{
		return true;
	}
	return false;
}
int myAtoi(char* str) {
	int len = strlen(str);
	int current = 0;
	while (str[current] == ' ')
	{
		current++;
	}
	bool mark = true;
	bool flag = false;  //确定 -+是否已经出现过了
	if (str[current] == '-')
	{
		mark = false;
		flag = true;
		current++;
	}
	if (str[current] == '+'&&!flag)
	{
		current++;
	}
	if (!isIn(str[current]))
	{
		//exit(0);
		return  0;
	} 
	long long int result = 0; 
	//定义long long型  免得数又不够大
	while (isIn(str[current]))
	{
		result = result * 10;

		if (mark)
		{
			if (result >= INT_MAX)
			{
				printf("%d\n", 1);
				return INT_MAX;
			}
		}
		else
		{
			if (-result <= INT_MIN)
			{
				printf("%d\n", 2);
				return INT_MIN;

			}
		}
		int temp = str[current] - '0';
		result = result + str[current] - '0';

		if (mark)
		{
			if (result >= INT_MAX)
			{
				printf("%d\n", 3);
				return INT_MAX;
			}
		}
		else
		{
			if (-result <= INT_MIN)
			{
				printf("%d\n", 4);
				return INT_MIN;
			}
		}

		current++;
	}
	//printf("%d \n", current);
	if (mark)
		return result;
	else
		return -result;
}

int main()
{
	char *str = "-2147483649";
	int num = myAtoi(str);
	printf("%d \n", num);
	return 0;
}