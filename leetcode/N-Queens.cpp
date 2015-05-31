/*
time   :  2015-5-25
author :  ht
comment:  N皇后问题，就是判定在一个board中
          任何两个皇后不能在同一行、同一列，也不能在斜对角上
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<vector<string>> result;
	vector<vector<string> > solveNQueens(int n) {
		if (n <= 0)
			return result;
		vector<int>queen(n, -1);//棋盘中所有的元素都存-1
		result.clear();
		int index = 0;
		traverse(queen,index);
		return result;
	}
	void traverse(vector<int>&queen,int index)
	{
		//queen[i]表示第i行  皇后的位置
		int len = queen.size();
		int i = 0;
		//index表示现在该存第几个皇后到了
		if ((index + 1) == len)
		{
			//退出条件是最后一个皇后是否能够放置
			bool mark = false;
			for (i = 0; i < len; i++)
			{
				if (!conflict(queen, index, i))
				{
					//找到答案了
					queen[index] = i;
					mark = true;
					break;
				}
			}
			//构造最终结果
			if (mark)
			{
				string str(len, '.');
				vector<string>res;
				for (i = 0; i < len; i++)
				{
					res.push_back(str);
					res[i][queen[i]] = 'Q';
				}
				result.push_back(res);
			}
		}
		else
		{
			bool mark = false;
			for (i = 0; i < len; i++)
			{
				mark = conflict(queen, index, i);
				if (!mark)
				{
					queen[index] = i; //第index行的Q放在 i列上
					traverse(queen, index + 1); //遍历下一个皇后的位置
				}
			}
		}
	}
	bool conflict(vector<int>queen,int index,int col)
	{
		//index表示的行
		//col 表示的是列
		//判定如果第index行放在第col列是否冲突
		int i = 0;
		int dis1, dis2,dis3,dis4;
		for (i = 0; i <index;i++)
		{
			//擦，开始的时候判定规则写错了，恶心死我了
			//注释里面的一个一个正确的规则
			//dis1 = i - queen[i];
			//dis2 = index - col;
			//dis3 = i + queen[i];
			//dis4 = index + col;
			//if (dis2 == dis1||col==queen[i]||dis3==dis4)
			//	return true;
			dis1 = abs(i - index);
			dis2 = abs(queen[i] - col);

			if (dis2 == dis1||col==queen[i])
				return true;
		}
		return false;
	}
};
/*
 * 
 *写一下N皇后问题的非递归解
 */
class Solution1 {
public:
	vector<vector<string>> result;
	vector<vector<string> > solveNQueens(int n) {
		if (n <= 0)
			return result;
		vector<int>queen(n,-1);
		traverse(queen);
		return result;
	}
	void traverse(vector<int>queen)
	{
		int i, j;
		i = 0; //表示放的皇后的下标
		j = 0; //表示放的列下标
		int len = queen.size();
		bool mark = false;
		
		int k = 0;  //第一个皇后有n种可能
		for (k = 0; k < len; k++)
		{
			mark = conflict(queen, 0, k);  //第一个皇后放在(0,k)位置
			if (!mark)
			{
				queen[0] = k;
				j = 0;
				i = 1;
				while (j < len&&i<len)
				{
					mark = conflict(queen, i, j);
					if (!mark)
					{
						//不冲突   
						queen[i] = j;
						i++;
						j = 0;
						if (i == len)
						{
							//找到了
							string str(len, '.');
							vector<string>res;
							for (int ii = 0; ii < len; ii++)
							{
								res.push_back(str);
								res[ii][queen[ii]] = 'Q';
							}
							result.push_back(res);
						}
						//break;
					}
					else
					{
						j++;
					}
				}
			}
			//第一个皇后的位置继续往后挪
		}

	
	}
	bool conflict(vector<int>queen, int index, int col)
	{
		//index表示的行
		//col 表示的是列
		//判定如果第index行放在第col列是否冲突
		int i = 0;
		int dis1, dis2;
		for (i = 0; i <index; i++)
		{
			dis1 = abs(i - index);
			dis2 = abs(queen[i] - col);

			if (dis2 == dis1 || col == queen[i])
				return true;
		}
		return false;
	}
};
int main()
{
	int n = 4;
	Solution1 mine;
	vector<vector<string>> result;
	result = mine.solveNQueens(n);
	//cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout <<"=========================="<<endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << endl;
	}
	return 0;
}