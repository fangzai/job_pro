#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

// 该程序考虑小于某个给定数字的所有素数的个数
//正如大家都知道的那样，一个数 n 如果是合数，那么它的所有的因子不超过<=sqrt(n)--n的开方,
//那么我们可以用这个性质用最直观的方法
bool isPrime()
{
	return true;
}
int countPrimes(int n) 
{
	int i =0, j =1;
	int num =0;
	bool mark =true;
	for(i=2;i<n;i++)
	{
		mark = true;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				mark = false;
				break;
			}
		}
		if(mark)
		{
			num++;
			//printf("%d  ",i);
		}
	}
    return num;
}
//分为三步
// 1 开一个很大的数组prime[n+1]  所有奇数标记为true 所有偶数标记为false
// 2 从3开始遍历到sqr(n)
int countPrimes1(int n) 
{
	int range = n-1;
	bool *prime = (bool*) malloc((n+1)*sizeof(bool));
	int i;
	prime[1]=false;
	prime[2]=true;
	for(i = 3; i<=range;i++)
	{
		if(i%2==0)
		{
			prime[i] = false;
		}
		else
		{
			prime[i] = true;
		}
	}
	int j =0;
	for(i = 3; i<=sqrt(range);i++)
	{
		if(prime[i])
		{
			for(j = i+i;j<=range;j+=i)  //边界一定要考虑到  否则就多了了
			{
				prime[j]= false;
			}
		}
	}
	int len = 0;
	for(i = 1; i<=range;i++)    //有等号
	{
		if(prime[i])
		{
			len++;
			//printf("%d ",i);
		}
	}
	free(prime);
	return len;
}
int main()
{
	int num = 10;
	printf("\n%d \n",countPrimes1(num));
	return 0;
}

