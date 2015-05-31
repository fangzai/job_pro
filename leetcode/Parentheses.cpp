#include<iostream>
#include<cstring>
using namespace std;


// 实现leetcode第20题
bool isValid(char* s) {
    int lenth = strlen(s);  //计算输入字符的长度
	int i =0;
	char head,tail;
	char *newS = (char*)malloc(lenth*sizeof(char));
	newS[0] = s[0];        //将首个字符压入栈中
	int stackPoint = 0;    //记录栈顶的位置
	char pop;              //pop出的字符
	char current;          //当前来匹配的字符
	bool isEmpty = false;  //判定是否匹配完毕
	for(i=1;i<lenth;i++)   //从第二个字符开始匹配
	{
		pop = newS[stackPoint];  //弹出栈顶
		current = s[i];          //待匹配字符
		if((pop == '{'&& current== '}')||(pop == '('&& current== ')')||(pop == '['&& current== ']'))//匹配判定条件
		{   
			//如果匹配完成
			if(stackPoint==0)
			{
				//在栈为空的情况下需要单独考虑
				if((i+1)<lenth)  //后面是否还有括号
				{
					newS[stackPoint] = s[i+1];  
					i++;
				}
				else
				{
					isEmpty = true;  //这个地方判定是否为空也就是括号是否匹配完毕
				}
			}
			else
			{
				//栈不为空 栈需要减一个位置
				stackPoint --;  //后移一个位置
			}
		}
		else
		{
			//不匹配的话，需要压栈
			stackPoint++;  //栈顶   +1
			newS[stackPoint]=s[i];
		}
	}
	//cout<<lenth<<endl;
	return isEmpty;
}
int main()
{
	char * myString = "((";
	if(isValid(myString))
	{
		cout<<"是匹配的！"<<endl;
	}
	else
	{
		cout<<"不匹配！"<<endl;
	}
	return 1;
}