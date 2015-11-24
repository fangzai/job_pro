#include<iostream>
#include<cstring>
using namespace std;
int happySquare(int n)
{
	//分解数字，获取数字中每一位的num
	int i;
	int *num_set = (int*)malloc(20*sizeof(int));
	int len = 0;
	while(n>=10)
	{
		num_set[len]=n%10;
		n = n/10;
		len++;
		//cout<<n<<endl;
	}
	num_set[len]=n;
	len++;

	int result =0;
	for(i=0;i<len;i++)
	{
		//cout<<num_set[i]<<"  ";
		result += num_set[i]*num_set[i];
	}
	return result;
}


bool isHappy(int n) {
	int i= 0;
	int result = n;

	//严格来说不应该用这种循环的方法
	//一种方法就是设置一个hashset，然后每次运行结果放进去
	//如果某个结果重复出现了，就表示这个数不是happy numer
	for(i=0;i<100;i++)
	{
		result = happySquare(result); 
		if(result ==1)
		{
			return true;
		}
	}
	return false;
    
}

int main()
{
	int n=19;
	if(isHappy(19))
	{
		cout<<"Happy number....."<<endl;
	}
	else
	{
		cout<<"Not happy number....."<<endl;
	}
	return 0;
}