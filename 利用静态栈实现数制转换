#include<stdio.h>
#define maxSize 100
typedef struct stack
{
	int array[maxSize];
	int top;
	int bottom;
}Stack;

Stack Init(void);
void Push(Stack *S,int num);
int Pop(Stack *S);
void Treaverse(Stack *S,char *info);

void Change(int num,int w,Stack *S);

int main(void)
{
	Stack S = Init();
	Change(17,8,&S);
	return 0;
}

Stack Init(void)
{
	Stack S;
	S.top = S.bottom = -1;
	return S;
}
void Push(Stack *S,int num)
{
	if(S->top == maxSize-1)
	{
		printf("栈满了，入栈失败！\n");
		return;
	}
	S->top++;
	S->array[S->top] = num;
}
int Pop(Stack *S)
{
	int num;
	if(S->top == S->bottom)
	{
		printf("栈空了，出栈失败！\n");
		return -1;	
	}
	num = S->array[S->top];
	S->top--;
	return num;
}
void Treaverse(Stack *S,char *info)
{
	if(S->top == S->bottom)
		return;
	printf("%s",info);
	while(S->top != S->bottom)
	{
		printf("%d",S->array[S->top]);
		S->top--;
	}
	printf("\n");
}

void Change(int num,int w,Stack *S)
{
	int div,remain,n = num;
	char info[50] = "";
	while(1)
	{
		div = n/w;
		remain = n%w;
		if(div != 0)
		{
			//余数入栈,更新num
			Push(S,remain);
			n = div;
		}
		else
		{
			Push(S,remain);
			break;
		}
	}
	sprintf(info,"十进制数%d转换为%d进制后为：",num,w);
	Treaverse(S,info);
}
