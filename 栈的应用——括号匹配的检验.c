#include<stdio.h>
#include<malloc.h>
//先构建一个字符栈。用来保存处理过程中的括号
//输入一段字符串，它们由两种括号组成：()[]  检验是否合法

typedef struct Node
{
	char c;
	struct Node * next;
}NODE;

typedef struct Stack
{
	NODE * top;
	NODE * button;
}STACK;

void init(STACK *);
void push(STACK *,char);
char pop(STACK *);
int isEmpty(STACK *);
int calculate(char *);

int main(void)
{
	int result = 0;
	char zifu[50];
	scanf("%s",zifu);
	result = calculate(zifu);
	if(1 == result)
		printf("合法\n");
	else 
		printf("不合法\n");
	return 0;
}

void init(STACK * pS)
{
	pS->top = (NODE *)malloc(sizeof(NODE));
	pS->button = pS->top;
	pS->top->next = NULL;
}


void push(STACK * pS,char c)
{
	NODE * temp = (NODE *)malloc(sizeof(NODE));
	temp->c = c;
	temp->next = pS->top;
	pS->top = temp;
}


int isEmpty(STACK * pS)
{
	if(pS->top == pS->button)
		return 1;
	else 
		return 0;
}


char pop(STACK * pS)
{
	char c;
	if(1 == isEmpty(pS))
		return '#';
	else
	{
		c = pS->top->c;
		pS->top = pS->top->next;
	}
	return c;
}

int calculate(char *str)
{
	char *s = str,c,c1;
	STACK S;
	init(&S);
	c = *s;
	while(c != '\0')
	{
		//判断c是什么类型的括号，如果是右括号，则抛出一个括号判断是否匹配
		if(c == '(' || c == '[')
		{
			push(&S,c);
		}
		else if(c == ')')
		{
			c1 = pop(&S);
			if(c1 != '(')
				return 0;
		}
		else if(c == ']')
		{
			c1 = pop(&S);
			if(c1 != '[')
				return 0;
		}
		else 
			return 0;
		s++;
		c = *s;
	}
	if(1 == isEmpty(&S))
		return 1;
	return 0;
}
