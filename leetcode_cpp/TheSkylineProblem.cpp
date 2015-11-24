/*
time   :  2015-5-30
author :  ht
comment:  地平线问题
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
/*
 * 我觉得，这一题要是不用高级的数据结构肯定得恶心死
 * merge interval 那一题就是这个样子，自己确定下标可以但是需要做大量的判断
 * 参考网上的思路
 */
class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> height;
		for (auto &b : buildings) 
		{
			height.push_back({ b[0], -b[2] }); 
			//左节点存为负值，这样在后面就不需要判定到底是右边界还是左边界了
			height.push_back({ b[1], b[2] });
		}
		//先按照x坐标排序，高度不参与
		sort(height.begin(), height.end());
		multiset<int> heap;
		heap.insert(0);
		
		vector<pair<int, int>> res;
		int pre = 0, cur = 0;
		for (auto &h : height) 
		{
			//遍历所有的高度
			if (h.second < 0) 
			{
				//遇到左边界就插入高度
				heap.insert(-h.second);
			}
			else 
			{
				//遇到右边界就删除高度
				heap.erase(heap.find(h.second));
			}
			/*
			 * 在这里举一个例子 [0,3] [2,2] [3,3 [5,2] 
			 * 实际height里面是这么存的  [0,-3] [2,-2] [3,3] [5,2]
			 * 遇到第一个高度 插入cur =0, heap 里面存{0 3},  结果里面存了一个[0,3]点
			 * 遇到第二个高度 （2，-2）插入，heap 里面存{ 0,2，3}，cur =3,pre =3; 相等，结果 [0,3]
			 * 遇到第三个高度，删除高度3 ,heap里面存{0,2},cur = 2，pre=3,不等结果存[0,3] [3，2]
			 * 遇到第四个，删除高度2 ,cur =0,pre =2 不等，结果存[0,3] [3，2][0,0]
			 */
			cur = *heap.rbegin();
			if (cur != pre)
			{
				res.push_back({ h.first, cur });
				pre = cur;
			}
		}
		return res;
	}
};
int main()
{
	vector<vector<int>> buildings = { {0,3,3}, {2,5,2} };
	vector<pair<int, int>> result;
	Solution mine;
	result = mine.getSkyline(buildings);
	return 0;
}