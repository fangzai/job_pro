/*
time   :  2015-5-29
author :  ht
comment:  单词文本格式变换  需要用到贪心算法
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	vector<string> result;
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int len = words.size();
		result.clear();
		if (len <= 0)
			return result;
		traverse(words,maxWidth);
		return result;
	}
	void traverse(vector<string> words, int maxWidth)
	{
		int i = 0, j = 0;
		vector<string>tmp;
		int len = words.size();
		int range;
		
		int num = 0;//表示这一行存了一个单词
		int stringLen = 0;//表示单词的总长度
		int pe, ps;
		while (i<len)
		{
			ps = i;
			range = 0;
			tmp.clear();
			while (i<len && range <= maxWidth)
			{
				tmp.push_back(words[i]);
				if (range != 0)
					range += 1;//多加一个空格

				range += words[i].size();
				i++;
			}
			pe = i - 1;
			if (range > maxWidth)
			{
				tmp.erase(tmp.end()-1);
				i--;
			}

			if (i == len)
			{
				//处理最后一行  最后一行不能像中间行一样两边对齐，需要左边对齐
				string res;
				int count=0;
				num = tmp.size();
				for (j = 0; j < num-1; j++)
				{
					res.append(tmp[j]);
					res.append(" ");
					count += tmp[j].size() + 1;
				}
				res.append(tmp[num - 1]);
				count += tmp[num - 1].size();
				res.append(string(maxWidth - count, ' '));
				result.push_back(res);
			}
			else
			{			
				string res = formatted(tmp,maxWidth);
				result.push_back(res);
			}

		}
	}
	string formatted(vector<string>array,int maxWidth)
	{
		//该函数用于将非最后一行格式话，分配每个string之间的空白
		int stringLen = 0;
		int j;
		for (j = 0; j < array.size(); j++)
			stringLen += array[j].size();
		int num = array.size();

		int spaceLen = maxWidth - stringLen; // 需要补充的总的空白数量
		if (num == 1)
			return array[0].append(spaceLen,' '); //如果只有一个的，后面全部补空
		int leftSpace = spaceLen % (num - 1);     //前面的可能需要多补一个空白

		int averageSpace = spaceLen / (num - 1);
		string res;
		for (j = 0; j < num - 1; j++)
		{
			if (j < leftSpace)
			{
				string extraSpace(averageSpace + 1, ' ');
				array[j].append(extraSpace);
			}
			else
			{
				string extraSpace(averageSpace, ' ');
				array[j].append(extraSpace);
			}
			res.append(array[j]);
		}
		res.append(array[num - 1]);
		//result.push_back(res);
		return res;
	}
};

int main()
{
	vector<string> words = { "This", "is", "an", "example", "of", "text", "justiftion." ,"a"};
	//vector<string> words = { "This", "is", "an", "example", "of", "text" };
	int L = 16;
	vector<string> result;
	Solution mine;
	result = mine.fullJustify(words,L);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "==================="<<endl;
	return 0;
}