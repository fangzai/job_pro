#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int climbStairs(int n) {
	// 题目原意说  一个人每次可以走1步或者2步
	// 问n步的楼梯有多少中走法
	// 很明显可以用递归的方式，也就是说
	// s[n]可以看成在n-2上直接走一个2步
	// n-1上走一步 所以 s[n] = s[n-2] +s[n-1]
	// 很多人想用递归，用递归的话对于比较大的数字容易
	// 堆栈溢出  直接用循环就可以了

	int *count = (int*)malloc((n+1)*sizeof(int));
	count[1] = 1;  // 一步台阶只有一种走法
	count[2] = 2;  // 两步台阶有两种走法
	int i;
	for (i = 3; i <= n; i++)
	{
		count[i] = count[i - 1] + count[i - 2];
	}
	return count[n];
}

int main()
{
	int n = 10;
	printf("%d \n",climbStairs(n));
	return 0;
}