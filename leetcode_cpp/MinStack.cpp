/*
time   :  2015-5-10
author :  ht
comment:  构造一种min stack使其各种操作都是在常数时间内完成
*/
#include<iostream>
#include<cmath>
#include<cstring>



using namespace std;


/*
typedef struct {
int*data;
int*index;
int current;
int maxSize;
int minimum;
} MinStack;
void minStackCreate(MinStack *stack, int maxSize) {
// initilize the stack

stack->maxSize = maxSize;
stack->current = -1;
stack->index = (int*)malloc(maxSize*sizeof(int));
for (int i = 0; i < maxSize;i++)
{
stack->index[i] = 0;
}
stack->data = (int*)malloc(maxSize*sizeof(int));
}

void minStackPush(MinStack *stack, int element) {
if (stack->current < stack->maxSize)
{
int count = 0;
for (int i = 0; i <= stack->current; i++)
{
if (stack->data[i] >= element)
{
stack->index[i]++;
//count++;
}
else
{
count++;
}

}
stack->current++;
stack->index[stack->current] = count;
stack->data[stack->current] = element;

}
else
{
return;
}
}
void minStackPop(MinStack *stack) {
if (stack->current < 0)
{
int element = stack->data[stack->current];
stack->current--;
for (int i = 0; i <= stack->current; i++)
{
if (stack->data[i] >= element && stack->index[i]>0)
{
stack->index[i]--;

}
}
}
else
{
return;
}

}

int minStackTop(MinStack *stack) {
if (stack->current >= 0)
{
return stack->data[stack->current];
}
else
{
return 0;
}

}

int minStackGetMin(MinStack *stack) {
if (stack->current < 0)
{
return 0;//这个栈已经是空的了
}
for (int i = 0; i <= stack->current; i++)
{
if (stack->index[i] == 0)
return stack->data[i];
}
//return 0;
}

void minStackDestroy(MinStack *stack) {
stack->current = -1;
stack->maxSize = 0;
free(stack->data);
free(stack->index);
stack->data = NULL;
stack->index = NULL;
}
void minStackPrint(MinStack *stack)
{
int i;
printf("the whole stack is :");
for (i = 0; i <= stack->current; i++)
{
printf("%d ", stack->data[i]);
}
printf("\n");
}
*/
typedef struct {
	int*data;
	int current;
	int maxSize;
	int *minimum;
} MinStack;
void minStackCreate(MinStack *stack, int maxSize) {
	// initilize the stack
	
	stack->maxSize = maxSize;
	stack->current = -1;
	stack->data = (int*)malloc(maxSize*sizeof(int));
	stack->minimum = (int*)malloc(maxSize*sizeof(int));
}

void minStackPush(MinStack *stack, int element) {
	if (stack->current < stack->maxSize)
	{	
		int previous;
		stack->current++;
		stack->data[stack->current] = element;
		if (stack->current == 0)
		{
			stack->minimum[0] = stack->data[0];
		}
		else
		{
			previous = stack->minimum[stack->current - 1];
			
			stack->minimum[stack->current] = previous < element ?  previous: element;
		}

	}
	else
	{
		return;
	}
}
void minStackPop(MinStack *stack) {
	if (stack->current >= 0)
	{
		int element = stack->data[stack->current];
		stack->current--;
	}
	else
	{
		return;
	}

}

int minStackTop(MinStack *stack) {
	if (stack->current >= 0)
	{
		return stack->data[stack->current];
	}
	else
	{
		return 0;
	}
	
}

int minStackGetMin(MinStack *stack) {
	if (stack->current < 0)
	{
		return 0;//这个栈已经是空的了
	}
	{
		return stack->minimum[stack->current];
	}
}

void minStackDestroy(MinStack *stack) {
	stack->current = -1;
	stack->maxSize = 0;
	free(stack->data);
	free(stack->minimum);
	stack->minimum = NULL;
	stack->data = NULL;

}
void minStackPrint(MinStack *stack)
{
	int i;
	printf("the whole stack is :");
	for (i = 0; i <= stack->current; i++)
	{
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}
int main()
{
	MinStack* mystack =NULL;
	int data[6] = {2,1,3,-1,-1,5};
	int maxSize = 5;
	int index = 0;
	
	int top;

	mystack = (MinStack*)malloc(sizeof(MinStack));
	minStackCreate(mystack,maxSize);
	
	minStackPush(mystack,data[index]);
	index++;
	minStackPrint(mystack);
	printf("minimum is %d \n",minStackGetMin(mystack));

	

	minStackPush(mystack, data[index]);
	index++;
	minStackPrint(mystack);
	printf("minimum is %d \n", minStackGetMin(mystack));

	minStackPush(mystack, data[index]);
	index++;
	minStackPrint(mystack);
	printf("minimum is %d \n", minStackGetMin(mystack));
	

	minStackPush(mystack, data[index]);
	index++;
	minStackPrint(mystack);
	printf("minimum is %d \n", minStackGetMin(mystack));
	

	minStackPush(mystack, data[index]);
	index++;
	minStackPrint(mystack);
	printf("minimum is %d \n", minStackGetMin(mystack));

	minStackPop(mystack);
	minStackPrint(mystack);
	printf("minimum is %d \n", minStackGetMin(mystack));


	minStackPop(mystack);
	minStackPrint(mystack);
	printf("minimum is %d \n", minStackGetMin(mystack));

	minStackPop(mystack);
	minStackPrint(mystack);
	printf("minimum is %d \n", minStackGetMin(mystack));

	minStackPop(mystack);
	minStackPrint(mystack);
	printf("minimum is %d \n", minStackGetMin(mystack));

	minStackPop(mystack);
	minStackPrint(mystack);
	printf("minimum is %d \n", minStackGetMin(mystack));

	top = minStackTop(mystack);
	printf("%d \n", top);
	minStackPrint(mystack);
	return 0;
}