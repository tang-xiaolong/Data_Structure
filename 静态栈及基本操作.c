#include<stdio.h>
#include<malloc.h>
#define maxSize 100
typedef int ElemType;
typedef struct sqStack
{
	ElemType stack_array[maxSize];
	int top;
	int bottom;
}Stack;

Stack *Init(void);//初始化一个栈
void Push(Stack *S,ElemType num);//入栈
ElemType Pop(Stack *S);//出栈
void Treaverse(Stack *S,char *info);//遍历整个栈

int main(void)
{
	Stack* S = NULL;
	S = Init();
	Push(S,12);
	Push(S,9);
	Push(S,5);
	Treaverse(S,"初始栈：");
	Pop(S);
	Treaverse(S,"操作后：");
	return 0;
}

Stack *Init()
{
	Stack *S = (Stack*)malloc(sizeof(Stack));
	S->top=S->bottom = -1;
	return S;
}
void Push(Stack *S,ElemType num)
{
	if(S->top == maxSize-1)
	{
		printf("入栈失败！\n");
		return;
	}
	S->top++;
	S->stack_array[S->top] = num;
}

ElemType Pop(Stack *S)
{
	ElemType num;
	if(S->top == S->bottom)
	{
		printf("出栈失败！\n");
		return -1;
	}
	num = S->stack_array[S->top];
	S->top--;
	return num;
}
void Treaverse(Stack *S,char *info)
{
	Stack *p = S;
	int index = p->top;
	if(index == p->bottom)
		return;
	printf("%s",info);
	while(index != p->bottom)
	{
		printf("%3d ",p->stack_array[index]);
		index--;
	}
	printf("\n");
}
