/*
time   :  2015-5-30
author :  ht
comment:  Dungeon Game 守护者游戏
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

/*
 * 动态规划的算法，从后往前递推
 * 在中间的时候有两种走法，一个right,一个是down
 * 开一个二维数组 dp[i][j]，表示从上一个状态到达这里需要的最小权值
 * 如果是往right走 
           right = myMax(dp[i][j + 1] - dungeon[i][j], 1);
 * 如果是往down走
           down = myMax(dp[i + 1][j] - dungeon[i][j], 1);
 * 首先初始化dp[m-1][n-1] 如果他是负数，则需要1-dungeon[m-1][n-1]的生命力
 *                        如果是正数，则只需要1
 * 然后初始化最后一列和最后一行，然后网上递推，到了最后的时候，就是需要的
 * 最小生命力
 */
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.size() <= 0 || dungeon[0].size() <= 0)
			return 0;

		int result;
		result = minimum(dungeon);
		return result;
	}
	int minimum(vector<vector<int>>& dungeon)
	{
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector<int>>dp(m,vector<int>(n,0)); //开一个二维数组，表示上一个状态到达i,j所需的最小权值
		if (dungeon[m - 1][n - 1] >= 0)
			dp[m - 1][n - 1] = 1;
		else
			dp[m - 1][n - 1] = 1-dungeon[m - 1][n - 1];
		int i = 0,j=0;
		for (i = m - 2; i >= 0; i--)
			dp[i][n - 1] = myMax(dp[i+1][n - 1] - dungeon[i][n - 1],1);
		for (j = n - 2; j >= 0; j--)
			dp[m-1][j] = myMax(dp[m-1][j+1] - dungeon[m-1][j], 1);
		int right, down;
		for (i = m - 2; i >= 0; i--)
		{
			for (j = n - 2; j >= 0; j--)
			{
				down = myMax(dp[i + 1][j] - dungeon[i][j], 1);
				right = myMax(dp[i][j + 1] - dungeon[i][j], 1);
				dp[i][j] = myMin(down,right);
			}
		}
		
		return dp[0][0];

	}
	int myMin(int a, int b)
	{
		return a > b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	vector<vector<int>> board = { {-2,-3,3}, {-5,-10,1}, {10,30,-5} };
	Solution mine;
	int result;
	result = mine.calculateMinimumHP(board);
	cout << result << endl;
	return 0;
}