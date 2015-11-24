/*
time   :  2015-5-30
author :  ht
comment:  给一堆点找出在某条直线上最多点的数量
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;


/*
 * 这个题的解法好傻啊！
 * 直接计算每个点和别的点的斜率然后统计最大数量
 * 我真不知道这个题的为什么那么小的提交成功率
 * http://www.cnblogs.com/easonliu/p/4527792.html
 */
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int res = 0, same_cnt, ver_cnt, cnt;
		unordered_map<double, int> mp;
		double k;
		for (int i = 0; i < points.size(); ++i)
		{
			same_cnt = 0;  //和i重复的点
			ver_cnt = 0;
			cnt = 0; //计算最大数量
			mp.clear();
			for (int j = 0; j < points.size(); ++j) 
			{
				if (points[i].x == points[j].x)
				{
					//需要考虑x相同，斜率无穷大的情况
					if (points[i].y == points[j].y)
					{
						++same_cnt; //重复的点
						continue;
					}
					else 
					{
						++ver_cnt;
						//斜率无穷大点计数
						cnt = max(cnt, ver_cnt);
					}
				}
				else 
				{
					//计算斜率，然后map映射是斜率和数量
					k = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
					++mp[k];
					cnt = max(cnt, mp[k]);
				}
			}
			//因为最后还需要考虑重复的点
			res = max(res, cnt + same_cnt);
		}
		return res;
	}
};
int main()
{
	return 0;
}