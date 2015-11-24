#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

bool isIsomorphic(char* s, char* t) {
	//这个算法思路比较朴素导致的效率不高
	int len = strlen(s);  // 假设两个字符长度是相同的
	int i, j;
	bool * mark = (bool*)malloc(len*sizeof(bool));  //标记已经出现过的字符

	char temp;
	char * newS = (char*)malloc(len*sizeof(char));
	for (i = 0; i < len; i++)
	{
		mark[i] = false;
		newS[i] = '0';
	}
	newS[len] = '\0';

	for (i = 0; i < len; i++)
	{
		if (!mark[i])  //用来跳过已经比较过的对
		{
			//temp = s[i];
			for (j = i; j < len; j++)
			{
				if (s[j] == s[i])
				{
					newS[j] = t[i];
					mark[j] = true;
					if (t[i] != t[j])
					{
						return false;
					}
				}
				if (t[j] == t[i])
				{
					mark[j] = true;
					if (s[i] != s[j])
					{
						return false;
					}
				}
			}
		}
		//printf("%s \n", newS);
	}
	//for (i = 0; i < len; i++)
		//printf("%d  \n",mark[i]);
	return true;
}
bool isIsomorphic1(char* s, char* t) {
	//参照网上的思路，利用hash表来做的话  效率就会提高很多了

	int len = strlen(s);
	int mem1[256],mem2[256];
	int size = 256;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		mem1[i] = 0;
		mem2[i] = 0;
	}
	//以s  = paper 和 t = title为例说明
	// mem1[p]= 1  mem[t] = 1
	// mem1[a]= 2  mem[i] = 2
	// mem1[p]= 3  mem[t] = 3
	for (i = 0; i < len; i++)
	{
		if (mem1[s[i]] != mem2[t[i]])  
		{
			//严格来说，这里是比较上次的出现位置，如果一样的
			//自然就过了，不一样的直接return了
			return false;
		}
		mem1[s[i]] = i+1;  
		mem2[t[i]] = i+1;
	}
	return true;
}
int main()
{
	char* str1 = "ab";
	char* str2 = "aa";
	if (isIsomorphic1(str1, str2))
	{
		printf("Isomorphic....... ");
	}
	else
	{
		printf("Not isomorphic......");
	}
	return 0;
}