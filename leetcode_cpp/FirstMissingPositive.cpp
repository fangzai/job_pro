/*
time   :  2015-5-25
author :  ht
comment:  找到第一个丢失的正数
*/
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

/*
 * 题目要求线性时间内完成，然后还只能开常数空间
 * 这样就比较恶心了
 */
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0) return 1;

		//把元素放到他们固定的位置 元素2放在 nums[1]  元素3 放在num[2]
		int i;
		for (i = 0; i < len; i++)
		{
			while (nums[i] != (i + 1))
			{
				if (nums[i] <= 0 || nums[i] >= len || nums[i] == nums[nums[i] - 1])
					break;
				//第一个条件是负数的话不用管，第二个条件是nums[i]太大了，肯定不在范围内也不用管
				//第三个是要交换的两个地方的元素一样，不用交换，要是交换了，就陷入死循环了
				//交换
				
				//nums[i]应该放的位置的下标是  nums[i]-1
				int tmp = nums[i];
				nums[i] = nums[tmp - 1];
				nums[tmp - 1] = tmp;
			}
		}
		for (i = 0; i < len; i++)
		{
			if (nums[i] != i + 1)
				return i + 1;
		}
		//已经循环到最后了
		return len + 1;

	}
};

int main()
{
	vector<int>nums = { 3, 4, 2, 1 };
	Solution mine;
	int result;
	result = mine.firstMissingPositive(nums);
	cout << result << endl;
	return 0;
}