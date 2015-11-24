#include<iostream>
#include<cstring>
using namespace std;

int strStr(char* haystack, char* needle) {
	// this is the  Brute force algorithm o(nm)
	// 暴力搜索的方法，效率是比较慢的
	int i=0,j=0;
	while((haystack[i+j])!='\0'&&(needle[j]!='\0'))
	{
		if(haystack[i+j]==needle[j])
		{
			j++;
		}
		else
		{
			i++;  //haystack的下标往前移动1
			j=0;
		}
	}

	if(needle[j]=='\0')
	{
		return i;
	}
	else
	{
		return -1;
	}
}
void get_nextval(const char *T, int* next)
{
	// 求模式串T的next函数值并存入数组 next， 这个函数是从下面参考的文中抄的
	int j = 0, k = -1;
	next[0] = -1;
	while ( T[j+1] != '\0' )
	{
		if (k == -1 || T[j] == T[k])
		{
			++j;
			++k;
			if (T[j]!=T[k])
			{
				next[j] = k;
			}
			else
			{
				next[j] = next[k];
			}
		}
		else
		{
			k = next[k];
		}
	}// while
	////这里是我加的显示部分
	// for(int i=0;i<j;i++)
	//{
	//     cout<<next[i];
	//}
	//cout<<endl;
}
int strStr1(char* haystack, char* needle) 
{
	// 这里实现一下更有效的kmp算法  就是利用不匹配字符的前缀尽可能跳过最大的距离
	if( !haystack||!needle|| needle[0]=='/0' || needle[0]=='/0' )
	{

		return -1;//空指针或空串，返回-1
	}
	int lenNeedle = strlen(needle);  //求模式needle的长度
	//cout<<lenNeedle<<endl;
	int *next = (int*)malloc(lenNeedle*sizeof(int));
	get_nextval(needle,next); //调用计算next的函数，我表示不是我写的，反正我不会

	int i=0,j=0,index =0;
	while((haystack[i])!='\0'&&(needle[j]!='\0'))
	{
		if(haystack[i] == needle[j])
		{
			i++;  // 如果相等的话当然ok
			j++;
		}
		else
		{
			//这个时候就要用到next了
			index += j-next[j];  // j-next[j]就是表示前缀前面的那个字符的位置
			//index是用来计当前haystack的移动的下标的
			if(next[j]!=-1)      //如果模式不是-1的说明有重叠的部分
			{
				j=next[j];// 模式串向右移动，也就是此时needle的话就要从下标j开始
			}
			else
			{
				j=0;
				i++;     //如果等于-1的话那就没有办法了，只能j重置，i后移
			}
		}
	}

	free(next);
	if(needle[j]=='\0')  // j这个下标如果移到了最后的话
	{
		return index;
	}
	else
	{
		return -1;
	}

}


int main()
{
	char *haystack ="abcabcabdabba";
	char *needle ="abcabd";
	cout<<strStr(haystack,needle)<<endl;
	cout<<strStr1(haystack,needle)<<endl;
	return 1;
}