#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
int trailingZeroes(int n) {
	int factor[2] = {0,0};  //代表2和5的个数
	int i;
	int temp;
	for(i=2;i<=n;i++)
	{
		temp =i;
		while(temp%2==0)
		{
			factor[0]++;
			temp = temp/2;
		}
		while(temp%5==0)
		{
			factor[1]++;
			temp = temp/5;
		}
	}
	if(factor[0]>=factor[1])
	{
		return factor[1];
	}
	else
	{
		return factor[0];
	}
}
int trailingZeroes1(int n)
{
    //这道题恶心死我了，就是计算5的个数
	//可以看到每次除5得到整数就是该次幂底数的5的倍数，加上去，直到再也除不尽了
	int num =n;
	int max_index =0;
	int single_five = num/5;
	int total_five =0;
	while(num>=5)
	{
		max_index++;
		num = num/5;
		total_five += num;  //就是这句话
	}
	//printf("single five is %d \n",single_five);
	//printf("complex five is %d \n",max_index);
	
	//printf("total five is %d \n",total_five);
	return total_five;
	
}
int main()
{
	printf("%d \n",trailingZeroes1(200));
	return 0;
}