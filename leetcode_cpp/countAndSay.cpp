#include<iostream>
#include<cstring>
using namespace std;
bool isIn(int*S,int len,int str)
{
	// 判定某个数字是否在整型数组中，这个也可以推广到字符匹配中
	int i=0;
	//bool mark = false;
	for(i=0;i<len;i++)
	{
		if(S[i] == str)
			return true;
	}
	return false;
}
char* countAndSay1(int n) {
	int len = 0;
	int myNum = n;
	int temp;
	int*sequence=(int*)malloc(10*sizeof(int));
	int *intS = (int*)malloc(100*sizeof(int));
	while(myNum>=10)
	{
		temp = myNum%10;
		//cout<<temp<<"  ";
		myNum = myNum/10;
		intS[len]= temp;
		//sequence[len] = temp+'0';
		len++;
	}
	//cout<<myNum<<endl;
	//sequence[len]=myNum+'0';
	intS[len]=myNum;    //将每个位置的数字存到intS中
	len++;				//表示intS的长度
	//sequence[len+1]='\0';
	//获取数字的每个位置的数字结束

	int i;
	int counts[10];
	for(i=0;i<10;i++)
	{
		counts[i]=0;  //计数置0
	}
	int current =0;
	//cout<<len<<endl;
	for(i=len-1;i>=0;i--)
	{
		if(isIn(sequence,current,intS[i]))
		{
			counts[intS[i]]++;   //开始统计
		}
		else
		{
			sequence[current]=intS[i];
			counts[intS[i]]++;
			current ++;
		}
	}

	char*myString=(char*)malloc(2*current*sizeof(char));
	//cout<<current<<endl;
	for(i=0;i<current;i++)
	{   //字符串拼接
		//cout<<counts[sequence[i]]<<" :"<<sequence[i]<<endl;
		myString[2*i]=counts[sequence[i]]+'0';
		myString[2*i+1]=sequence[i]+'0';
	}
	myString[2*current]='\0';
	return myString;
    
}

char* generate_next_num(char*str)
{
	int len=strlen(str);
	int i=0;
	char current_str = str[0];
	int *count=(int*)malloc(len*sizeof(int));   //统计数字字符的个数
	char*storage=(char*)malloc(len*sizeof(char));//存储数字字符的位置
	int pointer=0;
	
	for(i=0;i<len;i++)
	{
		count[i]=0;    //统计置0
	}
	storage[pointer]=str[0];  //先把第一个字符放在0位置
	count[pointer]++;         //该字符统计 +1


	for(i=1;i<len;i++)
	{
		if(storage[pointer]!=str[i])  
		{
			//如果the string coming 不等于 当前pointer所指的，则需要pointer后移
			pointer++;
			storage[pointer]=str[i];
			count[pointer]++;  //统计  +1
		}
		else
		{
			//如果the string coming等于 当前pointer所指的，则pointer不变
			count[pointer]++;  //只需要统计  +1
		}
	}
	storage[pointer+1]='\0';

	char*result=(char*)malloc(2*len*sizeof(char));

	//cout<<storage<<endl;
	for(i=0;i<pointer+1;i++)
	{
		result[2*i]=count[i]+'0';
		result[2*i+1]=storage[i];
		//cout<<count[i]<<" ";
	}
	result[2*(pointer+1)]='\0';
	//cout<<result<<endl;
	
	free(count);
	
	//free(storage);
	return result;
}
char* countAndSay(int n) {
	char*str_result="1";
	if(n<=1)
	{
		return str_result;
	}

	while(n>1)
	{
		str_result = generate_next_num(str_result);
		//cout<<n<<" : "<<str_result<<endl;
		n--;
	}
	return str_result;
}
int main()
{
	int num =5;
	cout<<countAndSay(num)<<endl;
	return 0;
}