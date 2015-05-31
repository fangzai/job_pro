/*
time   :  2015-5-9
author :  ht
comment:  将罗马数字转换为十进制数字

注释：罗马数字有 7个标记
I=1
V=5
X=10
L=50
C=100
D=500
M=1000
*/

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int getInt(char s)
{
	switch (s)
	{
	case 'I':
		return 1;
		break;
	case 'V':
		return 5;
		break;
	case 'X':
		return 10;
		break;
	case 'L':
		return 50;
		break;
	case 'C':
		return 100;
		break;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return -1;
		break;
	}
}
int romanToInt(char* s) {
	int len = strlen(s);
	int i = 0;
	int result = 0;
	int temp = 0;
	temp = getInt(s[i]);
	int num1, num2;
	//加的过程有三条规则，我想说，真的分析不出来的
	/*
	 * 1 如果当前处理的字符对应的值和上一个字符一样，那么临时变
	 *   量加上这个字符。比如III = 3
	 *
	 * 2 如果当前比前一个大，说明这一段的值应该是当前这个值减去
	 *   前面记录下的临时变量中的值。比如IIV = 5 – 2
	 * 3 如果当前比前一个小，那么就可以先将临时变量的值加到结果中
	 *  ，然后开始下一段记录。比如VI = 5 + 1
	 *  第三条最纠结，就是current 是I的时候，前面的临时变量加到
	 *  结果中，然后开始下一段字符的记录
	 */
	
	for (i = 1; i < len; i++)
	{
		num1 = getInt(s[i]);
		num2 = getInt(s[i - 1]);
		if (num1 == num2)
		{
			temp = temp + num1; // temp 其实可以换成getInt(s[i])
		}
		else
		{
			if (num1 > num2)
			{
				temp = num1 - temp;
			}
			else
			{
				result += temp;
				temp = num1;
			}
		}

	}
	result += temp;
	return result;
}
int main()
{
	char* str = "MCMXCVI";
	printf("%d \n", romanToInt(str));
	return 0;
}