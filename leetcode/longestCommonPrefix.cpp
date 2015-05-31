/*
time   :  2015-5-10
author :  ht
comment:  求一个string数组里面最长相同前缀
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize <= 0)
	{
		// 如果输入是空的话，居然返回 ""
		// 好没有天理的说
		return "";
	}

	if (strlen(strs[0]) <= 0)
	{
		return strs[0];
	}
	int i,j;
	char *result;
	int len = strlen(strs[0]);
	for (i = 1; i < strsSize; i++)
	{
		if (len >= strlen(strs[i]))
			len = strlen(strs[i]);
	}
	result = (char*)malloc((len + 1)*sizeof(char));
	bool mark = true;
	char first;
	j = 0;
	do
	{
		first = strs[0][j];
		for (i = 1; i < strsSize; i++)
		{
			if (strs[i][j] != first)
			{
				mark = false;
				break;
			}
		}
		if (mark)
		{
			result[j] = first;
			j++;
			if (j >= strlen(strs[0]))
			{
				break;
			}
		}
		//循环结束的时候小心越界
	} while (mark&&j<strlen(strs[0]));
	result[j] = '\0';

	return result;

}

int main()
{
	/*
	char*str[2] = {
	"",
	"wanitao",
	};
	*/
	char*str[1] = { "89" };
	int numSize = 1;
	printf("%s \n",longestCommonPrefix(str,numSize));
	return 0;
}