/*
time   :  2015-5-26
author :  ht
comment:  sodoku solver  暴力搜索九宫格
*/
#include<iostream>
#include<vector>

using namespace std;
/*
*空白的部分用那个‘.’填补的
*规则：
*	   1. 每一列1-9每个出现的次数不能超过1次
*	   2. 每一行1-9每个出现的次数不能超过1次
*	   3. 每一个3*3的格子1-9每个出现的次数不能超过1次
*暴力搜索，就是深度遍历，需要注意的就是最后退出的时候一定要把结果保存要起来
*/
class Solution {
public:
	char sep = '.';
	vector<vector<char>>result;
	void solveSudoku(vector<vector<char>>& board) {
		int startX = 0;
		int startY = 0;
		traverse(board,startX,startY);
		board = result;
	}
	void traverse(vector<vector<char>>& board,int x,int y)
	{
		int n = board.size();
		if (board[x][y] == sep)
		{
			for (int k = 0; k < n; k++)
			{
				if (isValidSudoku(board, x, y, k+1))
				{
					board[x][y] = k + '1';
					if ((y+1) < n)
					{
						traverse(board, x, y+1);
						board[x][y] = sep;
					}
					else
					{
						
						if (x == (n - 1) && y == (n - 1))
						{
							//一定要记录一下结果，否则就坑爹了
							result = board;
							return;
						}
						else
						{
							int tmp = 0;
							traverse(board, x + 1, tmp);
							board[x][y] = sep;
						}

					}
					
				}
			}
		}
		else
		{
			if ((y + 1) < n)
			{
				traverse(board, x, y + 1);
			}
			else
			{
				if (x == (n - 1) && y == (n - 1))
				{
					//一定要记录一下结果，否则就坑爹了
					result = board;
					return;
				}
				else
				{
					int tmp = 0;
					traverse(board, x + 1, tmp);
				}

			}
		}

	}
	bool isValidSudoku(vector<vector<char>>board,int x,int y,int label)
	{
		int m = board.size();
		int n = board[0].size();
		int i, j;

		vector<int>mem(10, 0);
		vector<int>hashDock(10, 0);
		int value = 0;

		//验证第x行
		hashDock = mem;
		hashDock[label]++;
		for (i = 0; i < n; i++)
		{
			if (board[x][i] != sep)
			{
				value = board[x][i] - '0';
				hashDock[value]++;
				if (hashDock[value] >= 2)
					return false;
			}
		}
		//验证列
		hashDock = mem;
		hashDock[label]++;
		for (i = 0; i < m; i++)
		{
			if (board[i][y] != sep)
			{
				value = board[i][y] - '0';
				hashDock[value]++;
				if (hashDock[value] >= 2)
					return false;
			}
		}
		
		//验证其所在的小框
		hashDock = mem;
		hashDock[label]++;
		int num = 3;
		int numX = x / 3;
		int numY = y / 3;
		int startX = numX * 3;
		int startY = numY * 3;
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				if (board[i + startX][j + startY] != sep)
				{
					value = board[i + startX][j + startY] - '0';
					hashDock[value]++;
					if (hashDock[value] >= 2)
						return false;
				}
			}
		}
		return true;
	}
};
int main()
{
	char * str[9] = {
	"53..7....",
	"6..195...",
	".98....6.",
	"8...6...3",
	"4..8.3..1",
	"7...2...6",
	".6....28.",
	"...419..5",
	"....8..79",
	};
	

	//char * str[9] = {
	//	"..4...63.",
	//	".........",
	//	"5......9.",
	//	"...56....",
	//	"4.3.....1",
	//	"...7.....",
	//	"...5.....",
	//	".........",
	//	"........."
	//};
	int n = 9;
	vector<char>tmp(n,'.');
	vector<vector<char>>board(n,tmp);
	
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			board[i][j] = str[i][j];

	Solution mine;
	mine.solveSudoku(board);
	return 0;
}