/*
time   :  2015-5-21
author :  ht
comment:  求最长公共子序列
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

void show(int **matrix,int m,int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int LCS(char*s1,char*s2)
{
	/*
	 *算法还可以改进，我们可以将查找最大长度和对应字符的工作放在构造矩阵的过程中完成，
	 *一边构造一边记录当前的最大长度和对应位置，这样就节省了n^2的查找时间。

     *空间上也可以做改进，如果按照如上的方式构造，我们发现，当矩阵的第i+1行的值
	 *计算完成后，第i行的值就没有用了，即便是最长的长度出现在第i行，我们也已经用
	 *变量记录下来了。因此，可以将矩阵缩减成一个向量来处理，向量的当前值对应第i行，
	 *向量的下一个循环后的值对应第i+1行
	 */
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int** mark = (int**)malloc(len1*sizeof(int*));

	int i, j;
	for (i = 0; i < len1; i++)
	{
		mark[i] = (int*)malloc(len2*sizeof(int));
		for (j = 0; j < len2; j++)
		{
			mark[i][j] = 0;
		}
	}
	for (i = 0; i < len1; i++)
		mark[i][0] = (s1[i] == s2[0]) ? 1 : 0;
	for (j = 0; j < len2; j++)
		mark[0][i] = (s1[0] == s2[j]) ? 1 : 0;

	int max = 0;
	int ps, pe = 0;
	for (i = 1; i < len1; i++)
	{
		for (j = 1; j < len2; j++)
		{
			if (s1[i] == s2[j])
			{
				mark[i][j] = mark[i - 1][j - 1]+1;
			}
			else
			{
				mark[i][j] = 0;
			}
			if (mark[i][j] > max)
			{
				max = mark[i][j];
				pe = i;
			}
		}
	}

	show(mark,len1,len2);
	i = 0;
	j = pe-max+1;
	while (i < max)
	{
		cout << s1[j];
		j++;
		i++;
	}
	cout <<endl<< max << endl;
	return max;
}

string LCS1(string s1, string s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	vector<int>mark(len2+1,0);
	int i, j;

	int max = 0;
	int ps, pe = 0;
	for (i = 0; i < len1; i++)
	{
		for (j = len2; j > 0; j--)
		{
			if (s1[i] == s2[j - 1])
			{
				mark[j] = mark[j - 1] + 1;
				if (mark[j] > max)
				{
					max = mark[j];
					pe = i;
				}
			}
			else
			{
				mark[j] = 0;
			}
		}
	}
	string result;
	i = 0;
	j = pe - max + 1;
	result = s1.substr(j, max);
	return result;
}
int main()
{
	char* str1 = "wanghaitao";
	char* str2 = "fhaitwhaitaowanggg";

	//int len = LCS(str1, str2);
	//string str = "h";
	string s1 = "esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq";
	string s2 = s1;
	reverse(s1.begin(),s1.end());
	string result = LCS1(s1,s2);
	cout << result << endl;
	return 0;
}