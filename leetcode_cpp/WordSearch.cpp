/*
time   :  2015-5-25
author :  ht
comment:  在一个2D board中搜索单词，有每次扩展可以扩展4个方向
          这个题就是要做深度优先搜索
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * 和那个图的扩展几乎一模一样，需要用到深度递归
 */
class Solution {
public:
	bool result;
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() <= 0 || board[0].size() <= 0)
			return false;
		
		int len = board.size();
		int i, j;
		int index = 0;
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == word[index])
				{
					result = traverse(board, word, index, i, j);
					if (result)
						return true;
				}
			}
		}
		return false;
	}
	bool traverse(vector<vector<char>>&board, string word, int index, int x, int y)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()&&word[index]==board[x][y])
		{
			if (word.length() == (index+1))
			{
				return true;  //退出条件
			}
			else
			{
				char tmp = board[x][y];
				board[x][y] = '1';
				bool left =false, right =false, up=false, down=false;
				left = traverse(board, word, index+1, x - 1, y);
				if (left)
				{
					board[x][y] =tmp;
					return true;
				}
					
				right = traverse(board, word, index + 1, x + 1, y);
				if (right)
				{
					board[x][y] = tmp;
					return true;
				}	
				up = traverse(board, word, index + 1, x, y - 1);
				if (up)
				{
					board[x][y] = tmp;
					return true;
				}
				down = traverse(board, word, index + 1, x, y + 1);
				if (down)
				{
					board[x][y] = tmp;
					return true;
				}
					
				board[x][y] = tmp;
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	string str[3];
	str[0] = "ABCE";
	str[1] = "SFCS";
	str[2] = "ADEE";
	vector<vector<char>> board;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		vector<char>tmp;
		for (int j = 0; j < str[0].size(); j++)
		{
			tmp.push_back(str[i][j]);
		}
		board.push_back(tmp);
	}
	Solution mine;
	string word = "SEE";
	bool result;
	result = mine.exist(board,word);
	if (result)
		cout << "Find the word!" << endl;
	else
		cout << "Can't find the word" << endl;
	return 0;
}