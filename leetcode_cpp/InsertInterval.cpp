/*
time   :  2015-5-25
author :  ht
comment:  插入一个interval,合并他们重叠的
*/
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;


//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b)
{
	if (a.start == b.start)
	{
		return a.end > b.end;
	}
	else
	{
		return a.start < b.start;
	}

}
/*
 *这一题的下标计算恶心死我了
 */
class Solution {
public:
	vector<Interval> result;
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)  {
		int len = intervals.size();
		result.clear();
		if (len <= 0)
		{
			result.push_back(newInterval);
			return result;
		}
			
		sort(intervals.begin(), intervals.end(), cmp); //先快排序

		traverse(intervals, newInterval);
		return result;
	}
	void traverse(vector<Interval> intervals, Interval newInterval)
	{
		Interval head(INT_MIN, INT_MIN), tail(INT_MAX, INT_MAX);
		//加一个头  和  一个尾巴  避免下面越界
		intervals.insert(intervals.begin(), head);
		intervals.insert(intervals.end(), tail);
		int len = intervals.size();
		int ps, pe;
		ps = 0;
		pe = 0;
		Interval current;
		//循环融合
		int i, j;
		for (i = 0; i<len; i++)
		{
			if (intervals[i].start < newInterval.start)
			{
				ps++;
			}
			if (intervals[i].end < newInterval.end)
			{
				pe++;
			}
		}
		//先把他们该插入的位置查找出来  一个是ps还有一个是pe
		for (i = 0; i< ps - 1; i++)
		{
			result.push_back(intervals[i]);
		}

		////中间交错的区间判定
		//if (newInterval.start>intervals[ps-1].end)
		//{
		//	result.push_back(intervals[ps-1]);
		//	//newInterval和ps-1下标区间没有交差
		//	
		//	//接着判定newInterval.end是否和后面的区间有交差
		//	current.start = newInterval.start;
		//	if (newInterval.end >= intervals[pe].start)
		//	{
		//		current.end = intervals[pe].end;
		//		result.push_back(current);
		//		//有交叉，三个融合成一个了
		//	}
		//	else
		//	{
		//		//没有交差，一个current，还有一个是下标为pe的interval
		//		current.end = newInterval.end;
		//		result.push_back(current);
		//		result.push_back(intervals[pe]);
		//	}

		//}
		//else
		//{
		//	//和前面一个区间有交差
		//	current.start = intervals[ps-1].start;
		//	//判定和pe是否有交差
		//	if (newInterval.end >= intervals[pe].start)
		//	{
		//		current.end = intervals[pe].end;
		//		result.push_back(current);
		//		//有交叉，三个融合成一个了
		//	}
		//	else
		//	{
		//		//没有较差，一个current，还有一个是下标为pe的interval
		//		current.end = newInterval.end;
		//		result.push_back(current);
		//		result.push_back(intervals[pe]);
		//	}
		//}


		//判定ps-1下标区间是否交差
		if (newInterval.start>intervals[ps-1].end)
		{
			//newInterval和ps-1下标区间没有交差
			result.push_back(intervals[ps-1]);
			
			current.start = newInterval.start;
			//当前的起点试试newInterval的start
		}
		else
		{
			//和前面一个区间有交差
			current.start = intervals[ps-1].start;
		}

		//判定和pe是否有交差
		if (newInterval.end >= intervals[pe].start)
		{
			current.end = intervals[pe].end;
			result.push_back(current);
			//有交叉，三个融合成一个了
		}
		else
		{
			//没有交叉，一个current，还有一个是下标为pe的interval
			current.end = newInterval.end;
			result.push_back(current);
			result.push_back(intervals[pe]);
		}



		//后面没有交错区间的处理
		pe++;
		while (pe<len)
		{
			result.push_back(intervals[pe]);
			pe++;
		}
		//去掉第一个元素 和最后一个区间
		result.erase(result.begin());
		result.erase(result.end()-1);

	}
	int myMin(int a, int b)
	{
		return a>b ? b : a;
	}
	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	vector <Interval> nums;
	Interval p[5];
	p[0] = Interval(1, 2);
	p[1] = Interval(3, 5);
	p[2] = Interval(6 , 7);
	p[3] = Interval(8, 10);
	p[4] = Interval(12, 16);
	int i = 0;
	int len = 5;
	for (i = 0; i < len; i++)
		nums.push_back(p[i]);

	Interval point(3,17);
	Solution mine;
	vector<Interval> result;
	result = mine.insert(nums,point);
	for (i = 0; i < result.size(); i++)
	{
		cout << "[" << result[i].start << "," << result[i].end << "]" << endl;
	}
	return 0;
}