/*
time   :  2015-5-23
author :  ht
comment:  两个数字相除
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

/*
 * 算法的思想是先对dividend去对数，得到N,然后
 * dividend -2^n，但是取对数的过程不能用乘法和除法，就只能用加法了
 * 每次循环一遍，直到找到被除数可以减掉的最大的一个值，重复计算
 */
class Solution {
public:
	long long internalDivide(unsigned long long dividend, unsigned long long divisor) {
		if (dividend < divisor) {
			return 0;
		}

		long long result = 1;
		unsigned long long tmp = divisor, left;

		while (tmp <= dividend) {
			left = dividend - tmp; 
			//记录被4的某个指数减掉之后剩余的
			tmp <<= 1;

			if (tmp > dividend) {
				break;
			}
			else {
				result <<= 1;
			}
		}

		return result + internalDivide(left, divisor);
	}
	int divide(int dividend, int divisor) {
		unsigned long long _dividend = abs((long long)dividend),
			_divisor = abs((long long)divisor);
		bool positive = ((dividend >= 0) && (divisor > 0)) || ((dividend <= 0) && (divisor < 0));

		return positive ? internalDivide(_dividend, _divisor) : (-1) * internalDivide(_dividend, _divisor);
	}
	int divide1(int dividend, int divisor) {
		//上面是某个作者的递归形式，也可以改成非递归形式
		//这个题目其实和昨天的那个求m n所有的数字 and的结果很相似
		if (dividend == 0 || divisor == 0)
			return 0;  //处理被除数和除数为0的特殊情况
		//处理数字越界的情况

		long long int newDividen = dividend;
		long long int newDivisor = divisor;
		bool flag = false;
		if (newDividen*newDivisor < 0)
			flag = true;
		if (newDividen < 0)
			newDividen = 0- newDividen;
		if (newDivisor < 0)
			newDivisor = 0- newDivisor;
		
		if (newDivisor > newDividen)
			return 0;
		long long int sum = 0;
		int tmp;
		long long int count = 1;
		long long int last = 0;
		while (newDividen >= newDivisor)
		{
			sum = newDivisor;
			count = 1;
			while ((sum +sum) <= newDividen)
			{
				sum = sum +sum;
				count = count << 1;
			}
			newDividen -= sum;
			last += count;
		}
		if (flag)
			last = 0 - last;
		if (last >= INT_MAX)
			return INT_MAX;
		return last;
	}
};

int main()
{
	int dividend = INT_MIN;
	int divisor = -1;
	Solution mine;
	int result;
	result = mine.divide1(dividend,divisor);
	cout << result << endl;
	return 0;
}