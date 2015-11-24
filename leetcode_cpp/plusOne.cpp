#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int len = (digitsSize + 1);
	int *newDigits = (int*)malloc(len *sizeof(int));
	int i;
	int num = 1;
	for (i = len-1; i >=1; i--)
	{
		num = num + digits[i-1];
		newDigits[i] =num%10;
		num = num / 10;

	}
	if (num > 0)
	{
		newDigits[0] = num;
		returnSize[0] = len;
		return newDigits;
	}
	else
	{
		returnSize[0] = len - 1;
		return newDigits + 1;
	}

}

int main()
{
	int a[3] = { 9, 9, 9 };
	int digitSize = 3;
	int newSize;
	int *newDigits;//= (int*)malloc((newSize + 1)*sizeof(int));
	newDigits = plusOne(a, digitSize, &newSize);
	for (int i = 0; i < newSize; i++)
	{
		printf("%d ", newDigits[i]);
	}
	printf("\n");
	return 0;
}