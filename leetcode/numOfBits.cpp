#include<iostream>
#include<cstring>
using namespace std;

typedef unsigned long   uint32_t;    //无符号32位数

// 这个题目就是统计化成2进制后里面1的个数的
int hammingWeight(uint32_t n) {
	int len = 0;
	int num;
	while(n>1)
	{
		num = n%2;
		//cout<<num;
		if(num == 1)
		{
			len++;
		}
		n = n/2;
	}
	//cout<<n<<endl;
	if(n==1)
	{
		len++;
	}
	return len;
    
}
int main()
{
	uint32_t num = 10;
	cout<<hammingWeight(num)<<endl;
	return 0;
}