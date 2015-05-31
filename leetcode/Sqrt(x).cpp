/*
time   :  2015-5-18
author :  ht
comment:  自己写函数开方
		  用牛顿法  递推公式为  m = (m + x/m)/2  x是输入值，m是自己取的是一个初始点
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int mySqrt(int x) {
	long double m = 1.0,tmp;
	tmp = m*m - x;
	if (tmp < 0)
		tmp = tmp*(-1.0);

	//看来以后要少用abs这个函数了，特别不靠谱，经常越界
	while (tmp > 1e-5)
	{
		m = (m+ x / m) / 2;
		tmp = m*m - x;
		if (tmp < 0)
			tmp = tmp*(-1.0);
	}
	return m;
}

int main()
{
	int n = 2147395599;
	printf("%d \n", mySqrt(n));
	return 0;
}