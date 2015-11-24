/*
time   :  2015-5-20
author :  ht
comment:  gas station问题，判断其是否能够跑完全程
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>

using namespace std;

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {

	int i, j;
	int n = gasSize, sum = 0,sum1=0, index = 0;
	for (i = 0; i < n; i++)
	{
		sum += gas[i];
		sum1 += cost[i];
	}
	if (sum < sum1)
		return -1;
	sum = 0;
	srand((unsigned)time(NULL));
	int k = rand()%n;
	//暴力的方法，加了一个随机之后能过leetcode了，但是性能并不好
	//严格来说还是n^2的求求解时间
	for (i = 0; i < n; i++)
	{
		sum = 0;
		j = 0;
		while (j < n)
		{
			index = k + j;
			index = index%n;
			sum += gas[index];
			if (sum >= cost[index])
			{
				sum -= cost[index];
				//能够走完i->i+1这一段路程
			}
			else
			{
				break;
			}
			j++;
		}
		if (j == n)
			return k%n;
		k++;
	}

	return -1;
}
int canCompleteCircuit1(int* gas, int gasSize, int* cost, int costSize) {
	//网上还有一个o(n）的算法，就是如果走了step之后 突然发现不能走了
	//起点还是选i+1，但是这个时候达到i+step的油量剩余可以直接计算出来
	int i, j;
	int n = gasSize, sum = 0, sum1 = 0, index = 0;
	for (i = 0; i < n; i++)
	{
		sum += gas[i];
		sum1 += cost[i];
	}
	if (sum < sum1)
		return -1;

	i = 0;
	sum = 0;
	j = 0;
	while (j < n&& i < n)
	{
		index = i + j;
		index = index%n;
		sum += gas[index];
		sum -= cost[index];
		if (sum >= 0)
		{
			
			//能够走完i->i+1这一段路程
		}
		else
		{
			int count = 0;
			while (sum < 0)
			{
				sum = sum + cost[i] - gas[i];
				//把第i->i+1那一段路给截掉
				i++;
				count++;
			}
			j = j-count;  //减掉截去的步数

		}
		j++;
	}
	if (j == n)
	{
		return i;
	}

	return -1;
}
int main()
{ 
	int gas[5] = {4,3,3,7,3};
	int cost[5] = {5,2,4,6,3};
	//int gas[5] = { 1, 2, 3, 4, 5 };
	//int cost[5] = { 3, 4, 5, 1, 2 };
	int gasSize = 5;
	printf("%d \n", canCompleteCircuit1(gas, gasSize, cost, gasSize));
	return 0;
}