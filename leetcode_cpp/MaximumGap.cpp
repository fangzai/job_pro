/*
time   :  2015-5-28
author :  ht
comment:  连续整数的max gap的问题
*/
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;

/*
 * 我表示开始的时候没有理解题意
 * 题目的意思是返回其排序后最大的max gap
 * 要求线性时间空间
 * 这样就不能用一般的比较排序了 因为普通的比较排序有一个下界线 nlogn
 * 所以只能用其他的排序方法
 */
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int len = nums.size();
		if (len < 2) return 0;
		return buckerOrder(nums);

	}
	int buckerOrder(vector<int> nums)
	{
		//使用桶排序，有多少个元素就有多少个桶，  擦 这都行（前提是他均匀分布的）
		//自然其空间时间复杂度就是线性的了
		// 第一步就算每个桶里面的最大元素和最小元素
		//算出来之后求前一个桶和后一个桶里面的大gap,取最大值
		
		//这个提交了貌似有问题
		int maxVal = *max_element(nums.begin(),nums.end());
		int minVal = *min_element(nums.begin(), nums.end());

		int avergeGap = ceil((double)(maxVal - minVal) / (nums.size() - 1)); //安排桶的数量
		int bucketNum = ceil((double)(maxVal - minVal) / avergeGap);
		vector<int> bucketMin(bucketNum, INT_MAX);
		vector<int> bucketMax(bucketNum, INT_MIN);
		int i;
		int bucketId;
		for (i = 0; i < bucketNum; i++)
		{
			if (nums[i] != maxVal&&nums[i] != minVal)
			{
				bucketId = (nums[i] - minVal) / avergeGap;
				bucketMin[bucketId] = myMin(bucketMin[bucketId],nums[i]);
				bucketMax[bucketId] = myMax(bucketMax[bucketId], nums[i]);
			}
		}
		int maxGap = INT_MIN;
		int previous = minVal;
		for (i = 0; i < bucketNum; i++)
		{
			//考虑一下桶是空的情况
			if (bucketMin[i] == INT_MAX || bucketMax[i] == INT_MIN)
				continue;
			maxGap = myMax(maxGap,bucketMin[i]-previous);
			previous = bucketMax[i];
		}
		maxGap = myMax(maxGap,maxVal-previous);
		return maxGap;
	}
	int common(vector<int> nums)
	{
		sort(nums.begin(),nums.end()); //nlogn的复杂度 很明显是不行的
		int len = nums.size(); 
			int maxGap = INT_MIN;
		for (int i = 1; i < len; i++)
		{
			maxGap = myMax(maxGap, nums[i] - nums[i - 1]);
		}
		return maxGap;
	}
	int myMax(int a,int b)
	{
		return a > b ? a : b;
	}
	int myMin(int a, int b)
	{
		return a > b ? b : a;
	}

	int maximumGap1(vector<int> &num) {
		//这个是好的
		if (num.size() < 2) return 0;
		// 1. 算出用的桶数：取平均间隔，再用最大值和最小值之差除以间隔，得到桶数
		// 因为假设所有值都是平均分布的时候，如此取桶数可得时间复杂度是0(n)
		auto maxVal = *max_element(num.begin(), num.end());
		auto minVal = *min_element(num.begin(), num.end());
		int agGap = ceil((double)(maxVal - minVal) / (num.size() - 1)); // 平均间隔
		int bucketCount = ceil((double)(maxVal - minVal) / agGap);
		// 2. 记录每个桶的最大值和最小值
		vector<pair<int, int> > buckets(bucketCount, make_pair(INT_MIN, INT_MAX)); // 初始化桶
		for (auto val : num){
			if (val == maxVal || val == minVal) continue;
			int bucketNum = (val - minVal) / agGap;
			if (val > buckets[bucketNum].first)
				buckets[bucketNum].first = val; // 存储最大值
			if (val < buckets[bucketNum].second) buckets[bucketNum].second = val; // 存储最小值
		}
		// 3. 算出最大间隔
		int maxGap(0), lastMax(minVal);
		for (auto bucket : buckets){
			if (bucket.first == INT_MIN) continue; // 空桶
			int curMax(bucket.first), curMin(bucket.second);
			maxGap = max(maxGap, curMin - lastMax);
			lastMax = curMax;
		}
		maxGap = max(maxGap, maxVal - lastMax);
		return maxGap;
	}
};

int main()
{
	vector<int> nums = { 13684, 13701, 15157, 2344, 28728, 16001, 9900, 7367, 30607, 5408, 17186, 13230, 1598, 9766, 13083, 27618, 29065, 9171, 2470, 20163, 5530, 20665, 14818, 4743, 24871, 27852, 8129, 4071, 17488, 30904, 1548, 16408, 1734, 17271, 19880, 22269, 18738, 30242, 6679, 19867, 13781, 4615, 10049, 28877, 9323, 5373, 11381, 18489, 13654, 14324, 28843, 27010, 10232, 31696, 29708, 3008, 28769, 30840, 21172, 28461, 20522, 8745, 17590, 27936, 30368, 30993, 24416, 17472 };
	Solution mine;
	int result;
	result = mine.maximumGap(nums);
	cout << result << endl;
	return 0;
}