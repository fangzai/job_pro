#include <stdio.h>
#include <stdlib.h>

/*
time   :  2015-5-20
author :  ht
comment:  原址reverse string里面的word
*/

#include<math.h>
#include<string.h>
#include<time.h>


#define true 1
#define false 0
void myCopy(char*dis,char*src,int n)
{
        int i =0;
        for(i=0;i<n;i++)
        {
                dis[i] = src[i];
        }
}
void removeRepeat(char*s)
{
	//原址去掉空格
	int i = 0,count=0,start,end,len;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
		{
			count = 0;
			start = i;
			end = start+1;
			len = strlen(s);
			while (s[end] == ' ')
			{
				count++;
				end++;
			}
			//end = start;
			//memcpy(s + start+1, s + end, (len - end)*sizeof(char));
			myCopy(s + start+1, s + end, (len - end)*sizeof(char));
			s[len - count] = '\0';
		}
	}
	//return s;
}
int	in(char s)
{
	if ((s >= 'a'&&s <= 'z') || (s >= 'A'&&s <= 'Z') || (s >= '0'&&s <= '9'))
	{
		return true;
	}
	return false;
}
void reverseWords(char *s) {
	int len = strlen(s);

        if(len>150)
	    return;
	int i = 0;
	char sep = ' ';
	for (i = 0; i < len - 1; i++)
	{
		if ((!in(s[i]))&&s[i]!=sep)
		{
			s[i] = sep;
		}
	}
	len = strlen(s);
	//printf("%s===%d\n", s, len);
	removeRepeat(s);  //原址去掉重复的字符串
	len = strlen(s);
	//printf("%s===%d\n", s, len);

	//去掉第一个空格
	if (s[0] == sep)
	{
		//memcpy(s,s+1,(len-1)*sizeof(char));
		myCopy(s,s+1,(len-1)*sizeof(char));
		s[len - 1] = '\0';
	}
	len = strlen(s);  //更新字符串的长度

	//printf("%s===%d\n", s, len);
	//去掉最后的空格
	if (len <= 0)
		return;
	if (s[len - 1] == sep)
	{
		s[len - 1] = '\0';
	}
	len = strlen(s);

	char mark;
	int flag = false;
	if (!in(s[len - 1]))
	{
		flag = true;
		mark = s[len - 1];
		s[len - 1] = '\0';
	}
	len = strlen(s);
	//printf("%s===%d\n",s,len);
	int maxSize = 100;
	char *str = (char*)malloc(maxSize * sizeof(char));

	int ps = 0;
	int pe = 0;
	str[0] = sep;
	int range = 0;//记录单词的长度
	int count = 0;

	for (i = 0; i < len; )
	{
		range = 0;
		//while (s[ps] != sep)
		while (s[ps] != sep&&s[ps] != '\0')
		{
			ps++;
			range++;
		}
		//ps 一直是0
		if (s[ps] == '\0')
		{
			break;
		}
		//memcpy(str+1,s,(range)*sizeof(char));
		myCopy(str+1,s,(range)*sizeof(char));
		//第一个位置被空白占了
		pe = count + range + 1;
		if ((len - pe) <= 0)
		{
			break;
		}
		//memcpy(s,s+ps+1,(len-pe)*sizeof(char));//因为多了一个空格
               myCopy (s,s+ps+1,(len-pe)*sizeof(char));//因为多了一个空格
		//memcpy(s+len-pe,str,(range+1)*sizeof(char));
		myCopy(s+len-pe,str,(range+1)*sizeof(char));
		count += range + 1;
		ps=0;
		i += range+1;
	}

	len = strlen(s);
	//去掉第一个空格
	if (s[0] == sep)
	{
		//memcpy(s, s + 1, (len - 1)*sizeof(char));
		myCopy(s, s + 1, (len - 1)*sizeof(char));
		s[len - 1] = '\0';
	}
	len = strlen(s);  //更新字符串的长度
	//printf("%s===%d\n", s, len);
	if (flag)
	{
		s[len] = mark;
		s[len + 1] = '\0';
	}
	//printf("%s===%d\n", s, len);
}

int main()
{
	char*s = (char*)malloc(100*sizeof(char));
	char*str = "  the   sky     is blue!";
	//char*str = "   a   b  c d   e  ";
	//char*str = "hello world!";
	int len = strlen(str);
	int i;
	for (i = 0; i < len; i++)
	{
		s[i] = str[i];
	}
	s[len] = '\0';
	reverseWords(s);
	len = strlen(s);
	printf("%s===%d\n", s, len);
	return 0;
}
