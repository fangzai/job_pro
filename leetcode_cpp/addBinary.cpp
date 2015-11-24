#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

char* addBinary(char* a, char* b) {

	int len1 = strlen(a);
	int len2 = strlen(b);
	int size = len1 > len2 ? len1 : len2;
	size++;  //因为可能需要进一位

	char* newStr = (char*)malloc((size+1)*sizeof(char));  // 这个地方要给 '\0'分配一个空间，否则在leetcode上报错  runtime error
	int i;
	int index1 = len1 - 1;
	int index2 = len2 - 1;
	int temp = 0;
	newStr[size] = '\0';
	for (i = size - 1; i >= 1; i--)
	{
		//temp = 0;
		if (index1 >= 0)
		{
			temp += a[index1]-'0';
			index1--;
		}
		if (index2 >= 0)
		{
			temp += b[index2]-'0';
			index2--;
		}
		if (temp >= 2)
		{
			newStr[i] = temp%2 + '0';
			temp = 1;
		}
		else
		{
			newStr[i] = temp + '0';
			temp = 0;
		}
		
	}
	if (temp >= 1)   // 考虑最高位
	{
		newStr[0] = temp + '0';
		return newStr;
	}
	else
	{
		return newStr + 1;
	}

	
}

int main()
{
	char * str1 = "1111";
	char * str2 = "1111";
	printf("%s \n", addBinary(str1, str2));
	return 0;
}