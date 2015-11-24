/*
time   :  2015-5-12
author :  ht
comment:  求x的n次方
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
double myPow(double x, int n) {
	int i = 0;
	double result = 1;
	for (i = 0; i < n; i++)
	{
		result = result*x;
	}
	return result;
}
double myPow1(double x, int n)
{
	//使用了二分法，其实我的想法是直接除以10
	//这样效率会更高
	if (n == 0)
		return 1.0;
	if (n < 0)
	{
		if (n == INT_MIN)
			return 1.0 / (myPow(x, INT_MAX)*x);
		return 1.0 / myPow(x, -n);
	}
		
	double half = myPow(x, n >> 1);
	if (n % 2 == 0)   
		return half*half;
	else
		return half*half*x;
}
int main()
{
	double x = 3;
	int num = 3;
	printf("%f \n", myPow(x, num));
	return 0;
}