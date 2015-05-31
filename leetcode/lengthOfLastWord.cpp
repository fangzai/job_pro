#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int lengthOfLastWord(char* s) {
	int len = strlen(s);
	int i;
	int count = 0;
	char sep = ' ';
	int start;
	i = len - 1;

	// 该循环先找到last word的起点
	while ((s[i] == sep)&&(i>=0))
	{
		i--;
	}
	start = i;
	//printf("%d \n", start);
	for (i = start; i >= 0; i--)
	{	

		if (s[i] == sep)
		{
			break;   //找到 空格之后就break 停止搜索
		}
		count++;
	}
	return count;
}

int main()
{
	//char* str = "Hello world";
	char* str = "   ";
	printf("%d \n", lengthOfLastWord(str));
	return 0;
}