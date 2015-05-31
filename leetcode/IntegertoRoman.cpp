/*
time   :  2015-5-16
author :  ht
comment:  将十进制数字转化为罗马数字
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;


char* intToRoman(int num) {
	int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	char *str[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int i, j;
	char* myStr[100];
	int number = num;
	int index = 0;
	for (i = 0; i < 13; i++)
	{
		while (number>=values[i])
		{
			myStr[index] = str[i];
			index++;

			number -= values[i];	
		}
	}
	int len = 0;
	char*result = (char*)malloc(100*sizeof(char));
	int pointer = 0;
	for (i = 0; i < index; i++)
	{
		len = strlen(myStr[i]);
		memcpy(result + pointer, myStr[i], len*sizeof(char));
		pointer += len;
	}

	result[pointer] = '\0';
	return result;
}

int main()
{
	printf("%s \n", intToRoman(1999));
	return 0;
}