/*
time   :  2015-5-24
author :  ht
comment:  求出矩阵中连通区域的个数
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*  
 * 以前没做过这样的题，不过感觉上可以用深度遍历来做
 * 参考网上的确实这种解法，每次遍历过后就把经过的点抹掉
 */
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size()<=0 || grid[0].size()<=0)
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		int count = 0; //用来计数的
		int i, j;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (grid[i][j] == '1')
				{
					traverse(grid,i,j);
					count++;
				}
			}
		}
		return count;
	}
	void traverse(vector<vector<char>>& grid,int x,int y)
	{
		if (x >= 0 && y >= 0  && x < grid.size()&& y < grid[0].size()&&grid[x][y]=='1')
		{
			grid[x][y] = '0';
			traverse(grid, x - 1, y);  //left
			traverse(grid, x + 1, y);  //right
			traverse(grid, x, y-1);  // up
			traverse(grid, x, y+1);  //down
		}
	}
};

int main()
{
	/*vector<vector<char>> grid = { { '1', '1', '1', '1', '0' }, 
								  { '1', '1', '0', '1', '0' },
								  { '1', '1', '0', '0', '0' },
								  { '0', '0', '0', '0', '0' } };
	*/
	vector<vector<char>> grid = { { '1', '1', '0', '0', '0' }, 
								  { '1', '1', '0', '1', '0' },
								  { '1', '1', '0', '0', '0' },
								  { '0', '0', '0', '1', '1' } };
	Solution mine;
	int result;
	result = mine.numIslands(grid);
	cout << result << endl;
	return 0;
}