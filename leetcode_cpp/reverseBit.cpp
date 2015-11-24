#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

typedef unsigned long   uint32_t;    //无符号32位数

uint32_t reverseBits(uint32_t n) {

	int i =0;
	int *stack = (int*)malloc(32*sizeof(int));
	int num;
	uint32_t result = 0;
	for(i=0;i<32;i++)
	{
		num = n%2;
		n = n/2;
		result *= 2;
		result += num;
	}
	//result *= 2;
	//result += n;
	return result;
    
}
int reverse(int x) {

	int MAX_INT=pow(2.0,31)-1;
	//cout<<MAX_INT<<endl;
	int MIN_INT=-pow(2.0,31);
	if(x<=MIN_INT)  // 不加这句会有惊喜出现的
		return 0;
	int n = abs(x);
	bool mark = true;  //表示x输入是正数，下面对n进行操作
	cout<<MIN_INT<<endl;
	if(x<0)
	{
		mark = false;
	}
	int num;
	long long int result = 0;
	while(n>=10)
	{
		num = n%10;
		//cout<<num;
		n = n/10;
		result *=10;
		result += num;
		if(result>MAX_INT/10)         //判断正数出界了
			return 0;
		if(!mark&&result<MIN_INT/10)  //判断负的出界了
			return 0;
		cout<<result<<endl;
	}
	//cout<<n<<endl;
	result *=10;
	result += n;
	//cout<<result<<endl;
	if(!mark)
	{
		return -result;
		//result = -result;
	}
	else
	{
		return result;
	}
    
}
int main()
{
	uint32_t num = 43261596;
	//cout<<reverseBits(num)<<endl;
	//int num1 = 1534236469;
	int num1 = -2147483648;
	cout<<"original number is "<<num1<<endl;
	cout<<"reverse number is  "<<reverse(num1)<<endl;
	return 0;
}