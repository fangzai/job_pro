/*
time   :  2015-5-30
author :  ht
comment:  验证输入的数字是否合法
*/
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

/*
 * 不想写这个了，那个数字分数除法恶心死我了~~~大体思路知道
 * 搞各种判断的方法就太low了，网上有大神做了一个有限状态机，吊炸天
 *
 *
 *
 * 下面描述一下状态
 * 基本状态 6个  0~5
 *	   状态  0 ：起始状态，它是不合法状态，
				 1.接受空格的时候状态仍然是0
				 2.输入符号的时候状态变为3，状态3和0基本一样除了无法再接受符号，
				 3.故而再0的基础上，将接受符号置为-1则就是3的状态
				 4.接受数字后，状态变为1，状态1无法在接受符号，可以接受空格、数字、点、指数
				 5.当输入为.的时候状态转为2，后面必须接受数字，其他均为非法
				 6.输入指数的时候非法
 
 *     状态  1 : 可以认为是空格状态
				 1.接受数字时仍转为状态1
				 2.接受点时，转为状态4，可以接受空格，数字，指数，状态4为合法的结束状态
				 3.接受指数时，转为状态5，可以接受符号，数字，不能再接受点，
				 因为指数必须为整数，而且必须再接受数字

 *     状态  2 : 可以认为是.号状态
		         1.接受数字后转为状态4

 *     状态  3 : 可以认为是符号状态

 *     状态  4 : 可以认为是数字状态
				 1.接受空格，合法结束
				 2.接受数字，仍然是数字
				 3.接受指数，转为状态5
 
 *     状态  5 : 可以认为是指数状态
				 1.接受符号，转为状态6，状态6和5几乎一样，只是不能再接受符号
				 2.接受数字，转为状态7，7状态只能接受空格或者数字，状态7是合法结束状态

 * 扩展了3个状态
	   状态  6 : 可以认为是指数状态后的符号状态
				 1.只能接受数字，转换为状态7

	   状态  7 : 可以认为是指数状态后的数字状态
				 1.接受空格状态转换为状态8，状态7是合法结束状态
				 2.接受数字仍然后状态7

	   状态  8 : 可以认为是指数状态后的空格状态
			     1.只能接受空格，保持状态8，状态8为合法状态
 */
class Solution1
{
public:
	bool isNumber(string s)
	{
		enum InputType
		{
			INVALID,    // 0
			SPACE,      // 1
			SIGN,       // 2
			DIGIT,      // 3
			DOT,        // 4
			EXPONENT,   // 5
			NUM_INPUTS  // 6
		};

		int transitionTable[][NUM_INPUTS] =
		{
			-1, 0, 3, 1, 2, -1,     // next states for state 0
			-1, 8, -1, 1, 4, 5,     // next states for state 1
			-1, -1, -1, 4, -1, -1,     // next states for state 2
			-1, -1, -1, 1, 2, -1,     // next states for state 3
			-1, 8, -1, 4, -1, 5,     // next states for state 4
			-1, -1, 6, 7, -1, -1,     // next states for state 5
			-1, -1, -1, 7, -1, -1,     // next states for state 6
			-1, 8, -1, 7, -1, -1,     // next states for state 7
			-1, 8, -1, -1, -1, -1,     // next states for state 8
		};

		int state = 0;
		int len = s.length();
		int i = 0;
		while (i<len)
		{
			InputType inputType = INVALID;
			if (isspace(s[i]))
				inputType = SPACE;
			else if (s[i] == '+' || s[i] == '-')
				inputType = SIGN;
			else if (isdigit(s[i]))
				inputType = DIGIT;
			else if (s[i] == '.')
				inputType = DOT;
			else if (s[i] == 'e' || s[i] == 'E')
				inputType = EXPONENT;

			state = transitionTable[state][inputType];

			if (state == -1)
				return false;
			else
				i++;
		}
		//1、4、7、8均为合法状态
		return state == 1 || state == 4 || state == 7 || state == 8;
	}
};
int main()
{
	return 0;
}