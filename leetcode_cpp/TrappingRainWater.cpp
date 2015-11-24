/*
time   :  2015-5-18
author :  ht
comment:  求能够保存最多的水量
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
 * 这题还有一个思路，里面循环到了ps是峰值的时候就找不到比他小的了
 * 这个时候再让程序逆向扫一遍，最后结果加起来就行了
 */
int trap(int* height, int heightSize) {

	if (heightSize <= 1)
	{
		return 0;
	}
	int ps, pe;
	int result = 0;
	int i, j;
	int min = 0,start,end;


	ps = 0;
	pe = 1;
	int te = 0, tmp = 0;

	bool mark = false;  //mark表示进入了找右边比当前大值的循环
	while (ps < heightSize&&pe < heightSize)
	{
		mark = false;
		while (pe<heightSize&&height[pe] < height[ps])
		{
			if (!mark)
			{
				mark = true;
				tmp = height[pe];  //条语句用于记录当前值右边第一个值的index和 大小
				te = pe;
			}
			else
			{
				if (height[pe] > tmp)
				{
					// 再次循环的时候，把倒数第二大的找到
					te = pe;
					tmp = height[pe];
				}
			}
			pe++;
		}
		if (pe == heightSize)
		{
			//没有找到比height[ps]大的，那就找倒数第二大的
			ps++;  //ps后移挪一位，因为当前的pe没有用了
			pe = te;
			
			start = ps;
			end = pe-1;   //这个地方的end可以包括pe，也可以不用pe，因为pe就是标准值
			min = height[pe]; //倒数第二大的是标准值
			//测试这个分支  需要用的测试集合 是nums={4,2,3};
		}
		else
		{
			start = ps;
			end = pe - 1;
			min = height[ps]; //当前ps是标准值，因为找到了比他大的值
		} 

		//结果累计
		for (i = start; i <= end; i++)
		{
			result += min - height[i];
		}
		ps = pe;
		pe++;


		//下面的代码可以替换上面的if语句，上面的条件更加精简一些
		//if (pe == heightSize)
		//{
		//	//没有找到比height[ps]大的，那就找倒数第二大的
		//	ps++;  //ps后移挪一位，因为当前的pe没有用了
		//	pe = te;
		//	
		//	start = ps;
		//	end = pe-1;   //这个地方的end可以包括pe，也可以不用pe，因为pe就是标准值
		//	for (i = start; i <= end; i++)
		//	{
		//		result += height[pe] - height[i];
		//	}
		//	ps = pe;
		//	pe++;
		//}
		//else
		//{
		//	start = ps;
		//	end = pe - 1;
		//	for (i = start; i <= end; i++)
		//	{
		//		result += height[ps] - height[i];
		//	}
		//	ps = pe;
		//	pe++;
		//}

	}
	return result;
}

int main()
{
	//int nums[12] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int nums[12] = {4,2,3};
	int numSize = 2;
	printf("%d \n", trap(nums, numSize));
	return 0;
}