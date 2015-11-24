/*
time   :  2015-5-17
author :  ht
comment:  1.....n可以生成BST 二叉搜索树的数量
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

/*
 * 好吧！我表示这题真的没有什么思路，只知道肯定是有递推公式的
 * 用动态规划额。。。。。。。。
 */


/*
 * 当 n=1的时候根节点只有一个选择  1
 * 当 n=2的时候根节点有两种选择，
 * 当 n=3的时候根节点又3中选择
 * 直观地可以想想，当n个节点的时候，节点固定的时候，
 * 左右子树的BST乘积就是当前root的BST的数量
 */

int numTrees(int n) {
	if (n <= 0)
		return 1;
	int i, j;
	int *result = (int*)malloc((n+1)*sizeof(int));
	result[0] = 1;
	result[1] = 1;
	result[2] = 2;
	for (i = 3; i <= n; i++)
	{
		//root节点固定
		result[i] = 0;
		for (j = 0; j < i; j++)
		{
			//假设左子树分配i个节点，右子树分配的节点数量为 n-j-1
			result[i] += result[j] * result[i - j - 1];
		}
	}

	int num = result[n];
	free(result);
	result = NULL;
	return num;
}
int main()
{
	printf("%d \n", numTrees(3));
	return 0;
}