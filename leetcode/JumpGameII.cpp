/*
time   :  2015-5-25
author :  ht
comment:  关于jump的最小步数
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int jump1(vector<int>& nums) {
		//适用dp策略  dp[i]维护跳到i所需要的最小步数
		//动态规划的超时了，只能用那个线性的了
		int len = nums.size();
		vector<int>dp(len,INT_MAX);

		dp[0] = 0;  //第一步不需要跳就行了
		int i, j;
		for (i = 1; i < len; i++)
		{
			for (j = 0; j < i; j++)
			{
				if ((j + nums[j]) >= i)
				{
					//说明能从j跳到i;这里找最小值就可以了
					int tmp = dp[j] + 1;//就是说从0-j再跳一步就可以了
					if (tmp < dp[i])
					{
						dp[i] = tmp;   //把最小值赋给dp[i]
						break;//这个地方break是因为 dp是一个非递减的，后面的肯定>=前面的
						//所以没有必要让j继续往后循环了
					}
				}
			}
		}

		return dp[len - 1];
	}
	/*
	 * 算法可以这么理解，上次能跳的最远距离是last
	 * 当走到i的时候，如果last比i大的，则跳数不用增加
	 * 但是还是要维护一下当前能到达的最大距离
	 * 当last<i了之后就开始更新last  然后跳的步数也要  +1
	 */
	int jump(vector<int>& nums) {
		//http://blog.csdn.net/loverooney/article/details/38455475
		//算法不太好懂
		int count = 0;    //当前跳数  
		int last = 0;     //上一跳可达最远距离  
		int current = 0;      //当前一跳可达最远距  
		int len = nums.size();
		for (int i = 0; i < len; ++i) 
		{
			//无法向前继跳直接返回  
			if (i>current)
			{
				return -1;
			}
			//需要进行下次跳跃，则更新last和当执行的跳数ret  
			if (i > last)
			{
				last = current;
				count++;
			}
			//记录当前可达的最远点  
			current = myMax(current, i + nums[i]);
		}
		return count;
	}
	int myMax(int a,int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	vector<int>nums = { 2, 3, 1, 1, 4 };
	Solution mine;
	int result;
	result = mine.jump(nums);
	cout << result << endl;
	return 0;
}