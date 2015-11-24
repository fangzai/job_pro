/*
time   :  2015-5-11
author :  ht
comment:  一个数组中两数的和等于target
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int* twoSum(int* nums, int numsSize, int target) {

	int *result = (int*)malloc(2 * sizeof(int)); 
	int i, j;
	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				result[0] = i + 1;
				result[1] = j + 1;
				return result;
			}
		}
	}
	result[0] = -1;
	result[0] = -1;
	return result;
}


struct Node
{
	int num, pos;  
	//因为要返回后来的地址所以这里需要保存原来的pos
};
bool cmp(Node a, Node b)
{
	return a.num < b.num;
}
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector <int> result;
		vector <Node> array;
		int i,j;
		
		for (i = 0; i < nums.size();i++)
		{
			Node temp;
			temp.num = nums[i];
			temp.pos = i;
			array.push_back(temp);
		}
		//调用排序算法，这里的复杂度是nlogn
		//反正要我自己写就挺恶心的了
		sort(array.begin(), array.end(), cmp);
		i = 0;
		j = array.size() - 1;
		int tempNum;
		while (i != j)
		{
			tempNum = array[i].num + array[j].num;
			if (tempNum == target)
			{
				if (array[i].pos > array[j].pos)
				{
					result.push_back(array[j].pos + 1);
					result.push_back(array[i].pos + 1);
				}
				else
				{
					result.push_back(array[i].pos + 1);
					result.push_back(array[j].pos + 1);
				}
				break;
			}
			else
			{
				if (tempNum > target)
				{
					j--;
				}
				else
				{
					i++;
				}
			}

		}
		return result;
		
	}
	// //建立hash ,就算有重复也可以做
	vector<int> twoSum1(vector<int>& nums, int target)
	{
		vector<int>result;
		map<int, int>myMap;
		int i;
		for (i = 0; i < nums.size(); i++)
		{
			if (!myMap.count(nums[i]))
			{
				myMap.insert(pair<int, int>(nums[i], i));
			}
			if (myMap.count(target - nums[i]))
			{
				int n = myMap[target - nums[i]];
				if (n < i) 
				{
					//n只可能在i的后面
					result.push_back(n+1);
					result.push_back(i+1);
					break;
				}
			}
		}
		return result;
	}
};

int main()
{
	int nums[4] = { 3, 2, 4, 15 };
	int numSize = 3;
	int target = 6;

	vector<int> content;
	for (int i = 0; i < numSize; i++)
	{
		content.push_back(nums[i]);
	}
	Solution mine;
	vector<int>result = mine.twoSum1(content,target);

	cout << result[0] << result[1] << endl;

	return 0;
}