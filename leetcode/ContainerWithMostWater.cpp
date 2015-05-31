/*
time   :  2015-5-18
author :  ht
comment:  求一个数组之间的最大面积，不是动态规划
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int maxArea(int* height, int heightSize) {
	int i, j;
	int width;
	int area = INT_MIN,min;
	int ps, pe;
	for (i = 0; i < heightSize; i++)
	{
		for (j = i + 1; j < heightSize; j++)
		{
			width = j - i;
			min = height[i]>height[j] ? height[j] : height[i];
			int tmp = width*min;
			if (area < tmp)
			{
				ps = i;
				pe = j;
				area = tmp;
			}

		}
	}
	printf("%d  ->   %d \n", ps,pe);
	return area;
}
int myMin(int a,int b)
{
	return a>b ? b : a;
}
int myMax(int a, int b)
{
	return a>b ? a : b;
}
/*
 * 首先假设我们找到能取最大容积的纵线为 i , j (假定i<j)，那么得到的最大容积 C = min( ai , aj ) * ( j- i) ；
 * 在 j 的右端没有一条线会比它高！ 假设存在 k |( j<k && ak > aj) ，那么  由 ak> aj，所以 
 * min( ai,aj, ak) =min(ai,aj) ，所以由i, k构成的容器的容积C' = min(ai,aj ) * ( k-i) > C，与C是最值矛盾，所以得证j的后边不会有比它还高的线；
 *
 * 同理在i的左端不会有一条线比他高
 */
int maxArea1(int* height, int heightSize) {
	if (heightSize <= 1)
	{
		return 0;
	}
	int  result = 0;
	int ps = 0, pe = heightSize-1;
	while (ps < pe)
	{
		int temp = myMin(height[ps], height[pe])*(pe - ps);
		result = myMax(result,temp);
		//从较小的边开始收缩
		if (height[ps] < height[pe])
		{
			// 在ps的右边边找一条比  ps高的线
			int k = ps;
			while ((k < pe) && (height[k] <= height[ps]))
			{
				k++;
			}
			ps = k;
		}
		else
		{
			// 在pe的左边找一条比  pe高的线
			int k = pe;
			while ((k > ps) && (height[k] <= height[pe]))
			{
				k--;
			}
			pe = k;
		}
	}
	return result;

}

int main()
{
	//int nums[10] = { 2, 1, 2, 4, 2, 3, 5, 8, 4 };
	int nums[10] = {2,3,10,5,7,8,9};
	int numSize = 7;
	printf("%d \n", maxArea(nums, numSize));

	printf("%d \n", maxArea1(nums, numSize));
	return 0;
}