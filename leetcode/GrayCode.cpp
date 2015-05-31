/*
time   :  2015-5-15
author :  ht
comment:  给定一个n，求它生成的恶意格雷码
*/

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

/*
 *格雷码是指 n个bit 连续出现的数字只有一位不相同
 *例如  n =2;
 * 00 -> 01 -> 11 -> 10
 * http://baike.haosou.com/doc/3793519-3984486.html
 * 一般的，普通二进制码与格雷码可以按以下方法互相转换：

	二进制码->格雷码（编码）：从最右边一位起，依次将每一位与左边一位异或（XOR），
	作为对应格雷码该位的值，最左边一位不变（相当于左边是0）；

	格雷码-〉二进制码（解码）：从左边第二位起，将每位与左边一位解码后的值异或，
	作为该位解码后的值（最左边一位依然不变）。
 */
int* grayCode(int n, int* returnSize) {
	//if (n <= 0)
		//return NULL;
	int len = pow(2, n);  //计算生成的序列的长度
	int* result = (int*)malloc(len*sizeof(int));
	int i, j;
	int index1, index2,mark1,mark2;
	//int standard = (len-1)>>1;
	int temp;
	//printf("%d \n", standard);
	for (i = 0; i < len; i++)
	{
		temp = 0;  //用于存储最后的结果
		index1 = 1;
		index2 = 2;
		for (j = 0; j < n; j++)
		{
			mark1 = index1&i; //取第j个位置 比如，0101，取第二位数字就是 0100
			mark2 = index2&i; //取第j+1个位置
			mark2 = mark2 >> 1;//右移一位 与mark1对齐
			temp = temp|(mark1^mark2);  //mark1与mark2 与一下  加到temp上

			index2 = index2 << 1;  //index2 左移一位
			index1 = index1 << 1;
		}
		//printf("%d \n",temp);
		result[i] = temp;
	}
	returnSize[0] = len;
	return result;
}

int main()
{
	int *result = NULL;
	int n = 3;
	int returnSize = 0;
	result = grayCode(n, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d\n",result[i]);
	}
	return 0;
}