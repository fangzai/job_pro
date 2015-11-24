/*
time   :  2015-5-9
author :  ht
comment:  产生zigzag的字符串读取方式
说明： 这道题的边界问题恶心死我了
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

char* convert(char* s, int numRows) {
	//想法比较朴素
	//首先确定需要分配的长度
	char sep = ' ';
	int len = strlen(s);

	char*result = (char*)malloc((len + 1)*sizeof(char));
	if (numRows == 1)
	{
		memcpy(result, s, len + 1);   //只有一行，不用转换了
		return result;
	}
	int size = len / (2*numRows-2);  
	//如果没有numRows的判断，这里可能出现除数为0
	//刚开始这么干了，死活不让过
	size = size*(numRows-1);
	int mode = len % (2 * numRows - 2);
	if (mode <= numRows)
	{
		size = size + 1;
	}
	else
	{
		size = size + 1 + mode - numRows;
	}
	char** str = (char**)malloc(numRows*sizeof(char*));
	int i, j;
	for (i = 0; i < numRows; i++)
	{
		str[i] = (char*)malloc(size*sizeof(char));
		for (j = 0; j < size; j++)
		{
			str[i][j] = sep;
		}
	}
	int current = 0;
	i = 0; //确定在哪一行
	for (j = 0; j < size; j++)
	{
		if (current >= len)
			break;
		if (j % (numRows - 1)==0)
		{
			// 确定该列是要填满的
			while (i<numRows)
			{
				str[i][j] = s[current];
				current++;
				i++;
				if (current >= len)
				{
					break; // 越界了
				}
			}
			i = i - 2;;
		}
		else
		{
			//不能填满
			str[i][j] = s[current];
			current++;
			if (current >= len)
				break;
			i--;
		}
	}
	
	current = 0;
	for (i = 0; i < numRows; i++)
	{
		for (j = 0; j < size; j++)
		{
			//printf("%c", str[i][j]);
			if (str[i][j] != sep)
			{
				result[current] = str[i][j];
				current++;
			}
		}
		//printf("\n");
	}
	result[current] = '\0';
	for (i = 0; i < numRows; i++)
	{
		free(str[i]);
	}
	free(str);
	return result;
}

char* convert1(char* s, int numRows)
{
	/*  效率比较高的方法
	 *1 第i排从i开始
	 *2 第i排两个数的间隔是2(m-i),2(i-1)交替
	 */

	int len = strlen(s);
	if (numRows == 1)
	{
		return s;
	}
	char*result = (char*)malloc((len + 1)*sizeof(char));
	int index = 0,step1,step2;
	int i,current =0;
	for (i = 0; i < numRows; i++)
	{
		index = i;
		step1 = 2 * (numRows - i-1);
		step2 = 2 * i;
		result[current] = s[index];
		current++;
		while (index < len)
		{
			
			if (step1 > 0)
			{
				index += step1;
				if (index >= len)  // 可能加了之后就越界了
				{
					break;
				}
				result[current] = s[index];
				current++;
			}
			if (step2 > 0)
			{
				index += step2;
				if (index >= len)
				{
					break;
				}
				result[current] = s[index];
				current++;
			}
		}

	}
	result[current] = '\0';
	//printf("%s\n",result);
	return result;
}


int main()
{
	//char * str = "PAYPALISHIRING";
	char * str = "P";
	int nums = 1;
	char *result = convert1(str, nums);
	printf("%s \n", result);
	return 0;
}